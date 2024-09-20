#include "service_qml_jellyfin/client.h"
#include <mutex>
#include "request/response.h"
#include "qcm_interface/global.h"

namespace jellyfin
{
class Client::Private {
public:
    rc<request::Session> session;
    executor_type        ex;
    std::string          device_id;

    request::Request                             common_req;
    std::string                                  base;
    std::optional<std::string>                   token;
    std::map<std::string, std::any, std::less<>> props;

    mutable std::mutex mutex;
};
Client::Client(rc<request::Session> session, executor_type ex, std::string device_id)
    : d_ptr(make_rc<Private>(session, ex, device_id)) {
    C_D(Client);
    d->common_req.set_header("Content-Type", "application/json")
        .set_header("User-Agent", qcm::Global::instance()->user_agent());
}
Client::~Client() {}

auto Client::base() const -> std::string_view {
    C_D(const Client);
    std::unique_lock lock { d->mutex };
    return d->base;
}
auto Client::make_req(std::string_view url, const UrlParams&) const -> request::Request {
    C_D(const Client);
    request::Request req(d->common_req);
    req.set_url(url).set_header("Authorization", format_auth());
    return req;
}
auto Client::prop(std::string_view key) const -> std::optional<std::any> {
    C_D(const Client);
    if (auto it = d->props.find(key); it != d->props.end()) {
        return *it;
    }
    return std::nullopt;
}
void Client::set_prop(std::string_view key, std::any val) {
    C_D(Client);
    d->props.insert_or_assign(std::string(key), val);
}
auto Client::post(const request::Request& req,
                  std::string_view body) const -> asio::awaitable<Result<std::vector<byte>>> {
    C_D(const Client);
    rc<request::Response> rsp;
    EC_RET_CO(rsp, co_await d->session->post(req, asio::buffer(body)));

    _assert_(rsp);

    asio::streambuf buf;
    auto [ec, size] = co_await asio::async_read(
        *rsp, buf, asio::transfer_all(), asio::as_tuple(asio::use_awaitable));

    asio::cancellation_state cs = co_await asio::this_coro::cancellation_state;
    if (cs.cancelled() != asio::cancellation_type::none) {
        asio::detail::throw_error(asio::error::operation_aborted);
    }

    Error err;
    if (ec != asio::error::eof && ec) {
        err = Error::push(ec);
    } else {
        auto code = rsp->code().value_or(0);
        switch (code) {
        case 200: {
            co_return convert_from<std::vector<byte>>(buf);
        }
        default: {
            Error::push(err, fmt::format("code: {}", code));
        }
        }
    }
    co_return nstd::unexpected(err);
}

void Client::set_base(std::string_view base) {
    C_D(Client);
    std::unique_lock lock { d->mutex };
    d->base = base;
    if (d->base.ends_with("/")) {
        d->base.pop_back();
    }
}

void Client::set_token(std::optional<std::string_view> token) {
    C_D(Client);
    std::unique_lock lock { d->mutex };
    d->token = token;
}

auto Client::format_auth() const -> std::string {
    C_D(const Client);
    std::unique_lock lock { d->mutex };
    return fmt::format("MediaBrowser {}{}",
                       fmt::join(std::array { "Client="s APP_NAME,
                                              "Version="s APP_VERSION,
                                              "Device=Linux"s,
                                              fmt::format("DeviceId={}", d->device_id) },
                                 ", "),
                       (d->token ? fmt::format(", Token={}", d->token.value()) : ""s));
}

auto Client::get_executor() -> executor_type& {
    C_D(Client);
    return d->ex;
}

} // namespace jellyfin