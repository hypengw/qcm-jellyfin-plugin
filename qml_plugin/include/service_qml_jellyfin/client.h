#pragma once

#include <asio/detached.hpp>
#include <asio/co_spawn.hpp>
#include <asio/strand.hpp>

#include "asio_helper/helper.h"
#include "request/session.h"
#include "request/request.h"
#include "jellyfin/type.h"
#include "service_qml_jellyfin/api.h"

namespace jellyfin
{

class Crypto;
class Client {
public:
    using executor_type = asio::thread_pool::executor_type;

    Client(rc<request::Session> session, executor_type ex, std::string device_id);
    ~Client();

    template<typename TApi>
    auto perform(const TApi& api,
                 u32         timeout = 60) -> asio::awaitable<Result<typename TApi::out_type>> {
        using out_type = typename TApi::out_type;
        Result<out_type> out;
        return {};
    }

    executor_type& get_executor();

    auto prop(std::string_view) const -> std::optional<std::any>;
    void set_prop(std::string_view, std::any);

private:
    auto post(const request::Request&,
              std::string_view) const -> asio::awaitable<Result<std::vector<byte>>>;

    class Private;
    rc<Private> d_ptr;
    C_DECLARE_PRIVATE_FUNC(Client, d_ptr);
};

} // namespace jellyfin
