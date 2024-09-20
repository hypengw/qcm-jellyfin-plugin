#pragma once
#include <concepts>
#include "core/strv_helper.h"

#include "jellyfin/type.h"

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

constexpr auto provider_name { "jellyfin"sv };

} // namespace jellyfin_qml