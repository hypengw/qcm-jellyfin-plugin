#pragma once

#include "request/request.h"
#include "error/error.h"
#include "json_helper/helper.h"

namespace jellyfin
{
using json_t = qcm::json::njson;

using Params     = std::map<std::string, std::string, std::less<>>;
using Error      = error::Error;
using BodyReader = request::req_opt::Read;

using Operation = request::Operation;
using UrlParams = request::UrlParams;

template<typename T>
using Result = nstd::expected<T, Error>;


namespace model {}
namespace api::param 
{
    using namespace jellyfin::model;
}

template<typename T>
auto format_param(const T& in) -> std::string {
    return convert_from<std::string>(in);
}

template<typename T>
    requires ycore::is_specialization_of_v<T, std::vector>
auto format_param(const T& in) -> std::string {
    return fmt::format("[{}]", fmt::join(in, ","));
}

} // namespace ncm