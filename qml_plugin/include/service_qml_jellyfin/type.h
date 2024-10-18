#pragma once
#include <concepts>
#include "core/strv_helper.h"

#include "jellyfin/type.h"
#include "service_qml_jellyfin/info.h"

namespace jellyfin_qml
{
template<typename T>
concept ApiCP_Base = requires(T t) {
    { T::base } -> std::convertible_to<std::string_view>;
};
template<typename T>
concept ApiCP_BaseFunc = requires(T t) {
    { t.base() } -> std::convertible_to<std::string_view>;
};
template<typename T>
concept ApiCP_Reader = requires(T t) {
    { t.body() } -> std::convertible_to<jellyfin::BodyReader>;
};

template<typename T>
concept ApiCP_Header = requires(T t) {
    { t.header() } -> std::convertible_to<request::Header>;
};


template<typename TApi, typename TModel>
struct querier_helper {
    using api_type   = TApi;
    using model_type = TModel;
    using out_type   = typename TApi::out_type;
    static void handle_output(const api_type& api, model_type& model, const out_type& in);
};

} // namespace jellyfin_qml