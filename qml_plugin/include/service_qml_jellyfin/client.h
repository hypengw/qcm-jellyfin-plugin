#pragma once

#include <asio/detached.hpp>
#include <asio/co_spawn.hpp>
#include <asio/strand.hpp>

#include "asio_helper/helper.h"
#include "core/strv_helper.h"
#include "ncrequest/session.hpp"
#include "ncrequest/request.hpp"
#include "jellyfin/type.h"
#include "service_qml_jellyfin/type.h"

namespace jellyfin
{

namespace api
{
auto format_api(std::string_view path, const UrlParams& query,
                std::string_view body) -> std::string;

auto process_error(std::span<const byte>) -> std::string;
} // namespace api

class Client {
public:
    using executor_type = asio::thread_pool::executor_type;

    Client(rc<ncrequest::Session> session, executor_type ex, std::string device_id);
    ~Client();
    Client(const Client&)            = default;
    Client& operator=(const Client&) = default;

    template<typename TApi>
    auto format_url(const TApi& api) const -> std::string {
        return fmt::format("{}{}", base(), api.path());
    }

    template<typename TApi>
    auto parse(std::span<const byte> data) -> Result<typename TApi::out_type> {
        using out_type = typename TApi::out_type;
        return qcm::json::parse(convert_from<std::string_view>(data))
            .transform([](const auto& j) {
                out_type out;
                from_json(*j, out);
                return out;
            })
            .map_error([](const auto& err) {
                return Error::push(err);
            });
    }

    template<typename TApi>
    auto perform(const TApi& api,
                 u32         timeout = 60) -> asio::awaitable<Result<typename TApi::out_type>> {
        auto                      req = make_req(format_url(api), api.query());
        Result<std::vector<byte>> res;
        if constexpr (TApi::oper == Operation::GET) {
            res = co_await get(req);
        } else if constexpr (TApi::oper == Operation::POST) {
            res = co_await post(req, api.body());
        } else {
            _assert_rel_(false);
        }
        co_return res
            .and_then([&api, this](const auto& res) {
                // DEBUG_LOG("{}", convert_from<std::string>(res));
                return parse<TApi>(res);
            })
            .transform_error([&api](auto err) {
                return Error::push(err, api::format_api(api.path(), api.query(), api.body()));
            });
    }

    auto get_executor() -> executor_type&;

    auto base() const -> std::string_view;
    auto make_req(std::string_view url, const UrlParams&) const -> ncrequest::Request;
    auto prop(std::string_view) const -> std::optional<std::any>;
    void set_prop(std::string_view, std::any);

    void set_base(std::string_view);

    auto token() const -> std::optional<std::string>;
    void set_token(std::optional<std::string_view>);

private:
    auto format_auth() const -> std::string;
    auto process_rsp(rc<ncrequest::Response>) const -> asio::awaitable<Result<std::vector<byte>>>;
    auto get(const ncrequest::Request&) const -> asio::awaitable<Result<std::vector<byte>>>;
    auto post(const ncrequest::Request&,
              std::string_view) const -> asio::awaitable<Result<std::vector<byte>>>;

    class Private;
    rc<Private> d_ptr;
    C_DECLARE_PRIVATE_FUNC(Client, d_ptr);
};

} // namespace jellyfin
