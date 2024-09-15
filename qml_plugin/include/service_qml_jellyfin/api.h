#pragma once
#include "jellyfin/type.h"
#include <concepts>
#include <string_view>

namespace jellyfin::api
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
    { t.body() } -> std::convertible_to<BodyReader>;
};

template<typename T>
concept ApiCP_Header = requires(T t) {
    { t.header() } -> std::convertible_to<request::Header>;
};
} // namespace