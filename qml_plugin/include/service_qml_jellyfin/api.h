#pragma once

#include "qcm_interface/api.h"
#include "service_qml_jellyfin/client.h"

namespace jellyfin_qml
{

namespace detail
{
auto get_client() -> jellyfin::Client;
}

template<typename TApi, typename TModel>
class ApiQuerier : public qcm::ApiQuerierBase {
public:
    using api_type   = TApi;
    using out_type   = typename TApi::out_type;
    using in_type    = typename TApi::in_type;
    using model_type = TModel;

    ApiQuerier(QObject* parent)
        : ApiQuerierBase(parent), m_model(new model_type(this)), m_client(detail::get_client()) {
        if constexpr (std::derived_from<TModel, QAbstractItemModel>) {
            connect(m_model,
                    &TModel::fetchMoreReq,
                    this,
                    &ApiQuerier::fetch_more,
                    Qt::DirectConnection);
        }
    }

    model_type* data() const override { return m_model; }

    void reload() override {
        // co_spawn need strand for cancel
        auto ex = asio::make_strand(m_client.get_executor());
        this->set_status(Status::Querying);
        this->spawn(ex, [cnt = gen_context()]() mutable -> asio::awaitable<void> {
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
                    /*
                    if constexpr (modelable<TModel, TApi>) {
                        self->model()->handle_output(std::move(out).value(),
   cnt.api.input); } else { handle_output(*self->model(), out.value());
                    }
                    */
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
    auto            client() const { return m_client; }

private:
    struct Context {
        QtExecutor                         main_ex;
        jellyfin::Client                   client;
        api_type                           api;
        QPointer<ApiQuerier<TApi, TModel>> self;
    };

    Context gen_context() {
        return Context {
            .main_ex = get_executor(),
            .client  = m_client,
            .api     = this->api(),
            .self    = this,
        };
    }

    api_type         m_api;
    model_type*      m_model;
    jellyfin::Client m_client;
};

} // namespace jellyfin_qml