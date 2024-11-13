#pragma once

#include "qcm_interface/api.h"
#include "service_qml_jellyfin/client.h"

namespace jellyfin_qml
{

auto create_client() -> qcm::Client;
auto get_jellfin_client(const qcm::Client& c) -> std::optional<jellyfin::Client>;

template<typename TApi, typename TModel>
class ApiQuerier : public qcm::QAsyncResultT<TModel, qcm::ApiQueryBase> {
public:
    using api_type    = TApi;
    using out_type    = typename TApi::out_type;
    using in_type     = typename TApi::in_type;
    using model_type  = TModel;
    using helper_type = querier_helper<TApi, TModel>;
    using Status      = qcm::QAsyncResult::Status;

    ApiQuerier(QObject* parent): qcm::QAsyncResultT<TModel, qcm::ApiQueryBase>(parent) {
        if constexpr (std::derived_from<TModel, QAbstractItemModel>) {
            connect(this->tdata(),
                    &TModel::fetchMoreReq,
                    this,
                    &ApiQuerier::fetch_more,
                    Qt::DirectConnection);
        }
    }

    virtual void handle_output(const out_type&) = 0;
    void         reload() override {
        // co_spawn need strand for cancel
        auto cnt = gen_context();
        if (! cnt) {
            this->cancel();
            ERROR_LOG("session not valid");
            this->set_error("session not valid");
            this->set_status(Status::Error);
            return;
        }

        this->set_status(Status::Querying);
        this->spawn([cnt = cnt.value()]() mutable -> asio::awaitable<void> {
            auto& self = cnt.self;
            auto& cli  = cnt.client;

            jellyfin::Result<out_type> out = co_await cli.perform(cnt.api);

            if (! out) {
                ERROR_LOG("{}", out.error());
            }

            // switch to qt thread
            co_await asio::post(asio::bind_executor(cnt.main_ex, asio::use_awaitable));
            if (self) {
                if (out) {
                    self->handle_output(out.value());
                    self->set_status(Status::Finished);
                } else {
                    self->set_error(convert_from<QString>(out.error().what()));
                    self->set_status(Status::Error);
                }
            }
            co_return;
        });
    }

protected:
    api_type&       api() { return m_api; }
    const api_type& api() const { return m_api; }
    model_type*     model() { return this->tdata(); }
    auto            client() -> std::optional<jellyfin::Client> {
        return this->session()->client().and_then(get_jellfin_client);
    }

private:
    struct Context {
        QtExecutor                         main_ex;
        jellyfin::Client                   client;
        api_type                           api;
        QPointer<ApiQuerier<TApi, TModel>> self;
    };

    auto gen_context() -> std::optional<Context> {
        return client().transform([this](auto c) {
            return Context {
                .main_ex = this->get_executor(),
                .client  = c,
                .api     = this->api(),
                .self    = this,
            };
        });
    }
    api_type m_api;
};

} // namespace jellyfin_qml