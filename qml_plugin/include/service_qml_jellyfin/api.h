#pragma once

#include "qcm_interface/api.h"
#include "service_qml_jellyfin/client.h"

namespace jellyfin_qml
{

auto create_client() -> qcm::Client;
auto get_jellfin_client(const qcm::Client& c) -> std::optional<jellyfin::Client>;

template<typename TApi, typename TModel>
class ApiQuerier : public qcm::ApiQuerierBase {
public:
    using api_type    = TApi;
    using out_type    = typename TApi::out_type;
    using in_type     = typename TApi::in_type;
    using model_type  = TModel;
    using helper_type = querier_helper<TApi, TModel>;

    ApiQuerier(QObject* parent): ApiQuerierBase(parent), m_model(new model_type(this)) {
        if constexpr (std::derived_from<TModel, QAbstractItemModel>) {
            connect(m_model,
                    &TModel::fetchMoreReq,
                    this,
                    &ApiQuerier::fetch_more,
                    Qt::DirectConnection);
        }
    }

    virtual void handle_output(const out_type&) = 0;
    model_type*  data() const override { return m_model; }
    void         reload() override {
        // co_spawn need strand for cancel
        auto cnt = gen_context();
        if (! cnt) {
            cancel();
            ERROR_LOG("session not valid");
            set_error("session not valid");
            set_status(Status::Error);
            return;
        }

        auto ex = asio::make_strand(cnt->client.get_executor());
        this->set_status(Status::Querying);
        this->spawn(ex, [cnt = cnt.value()]() mutable -> asio::awaitable<void> {
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
    model_type*     model() { return m_model; }
    auto            client() -> std::optional<jellyfin::Client> {
        return session()->client().and_then(get_jellfin_client);
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
                .main_ex = get_executor(),
                .client  = c,
                .api     = this->api(),
                .self    = this,
            };
        });
    }

    api_type    m_api;
    model_type* m_model;
};

} // namespace jellyfin_qml