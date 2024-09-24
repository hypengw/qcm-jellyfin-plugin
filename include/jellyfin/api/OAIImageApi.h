#pragma once
/*
 * OAIImageApi.h
 *
 * 
 */

#include <optional>
#include <core/str_helper.h>
#include <core/strv_helper.h>
#include "jellyfin/type.h"


// #include "jellyfin-cpp/ModelBase.h"
#include "jellyfin/model/OAIImageFormat.h"
#include "jellyfin/model/OAIImageInfo.h"
#include "jellyfin/model/OAIImageType.h"
#include "jellyfin/model/OAIProblemDetails.h"
#include <cstdint>
#include <string>
#include <vector>

namespace jellyfin {
namespace model
{
using return_type_deleteCustomSplashscreen = std::nullptr_t;
using return_type_deleteItemImage = std::nullptr_t;
using return_type_deleteItemImageByIndex = std::nullptr_t;
using return_type_deleteUserImage = std::nullptr_t;
using return_type_getArtistImage = std::vector<std::byte>;
using return_type_getGenreImage = std::vector<std::byte>;
using return_type_getGenreImageByIndex = std::vector<std::byte>;
using return_type_getItemImage = std::vector<std::byte>;
using return_type_getItemImage2 = std::vector<std::byte>;
using return_type_getItemImageByIndex = std::vector<std::byte>;
using return_type_getItemImageInfos = std::vector<OAIImageInfo>;
using return_type_getMusicGenreImage = std::vector<std::byte>;
using return_type_getMusicGenreImageByIndex = std::vector<std::byte>;
using return_type_getPersonImage = std::vector<std::byte>;
using return_type_getPersonImageByIndex = std::vector<std::byte>;
using return_type_getSplashscreen = std::vector<std::byte>;
using return_type_getStudioImage = std::vector<std::byte>;
using return_type_getStudioImageByIndex = std::vector<std::byte>;
using return_type_getUserImage = std::vector<std::byte>;
using return_type_headArtistImage = std::vector<std::byte>;
using return_type_headGenreImage = std::vector<std::byte>;
using return_type_headGenreImageByIndex = std::vector<std::byte>;
using return_type_headItemImage = std::vector<std::byte>;
using return_type_headItemImage2 = std::vector<std::byte>;
using return_type_headItemImageByIndex = std::vector<std::byte>;
using return_type_headMusicGenreImage = std::vector<std::byte>;
using return_type_headMusicGenreImageByIndex = std::vector<std::byte>;
using return_type_headPersonImage = std::vector<std::byte>;
using return_type_headPersonImageByIndex = std::vector<std::byte>;
using return_type_headStudioImage = std::vector<std::byte>;
using return_type_headStudioImageByIndex = std::vector<std::byte>;
using return_type_headUserImage = std::vector<std::byte>;
using return_type_postUserImage = std::nullptr_t;
using return_type_setItemImage = std::nullptr_t;
using return_type_setItemImageByIndex = std::nullptr_t;
using return_type_updateItemImageIndex = std::nullptr_t;
using return_type_uploadCustomSplashscreen = std::nullptr_t;
}

namespace api::param 
{
struct deleteCustomSplashscreen {
};
struct deleteItemImage {
    std::string itemId; // Item id.
    OAIImageType imageType; // Image type.
    std::optional<std::int32_t> imageIndex; // The image index.
};
struct deleteItemImageByIndex {
    std::string itemId; // Item id.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // The image index.
};
struct deleteUserImage {
    std::optional<std::string> userId; // User Id.
};
struct getArtistImage {
    std::string name; // Artist name.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // Image index.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
};
struct getGenreImage {
    std::string name; // Genre name.
    OAIImageType imageType; // Image type.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
    std::optional<std::int32_t> imageIndex; // Image index.
};
struct getGenreImageByIndex {
    std::string name; // Genre name.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // Image index.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
};
struct getItemImage {
    std::string itemId; // Item id.
    OAIImageType imageType; // Image type.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Optional. The MediaBrowser.Model.Drawing.ImageFormat of the returned image.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
    std::optional<std::int32_t> imageIndex; // Image index.
};
struct getItemImage2 {
    std::string itemId; // Item id.
    OAIImageType imageType; // Image type.
    std::int32_t maxWidth; // The maximum image width to return.
    std::int32_t maxHeight; // The maximum image height to return.
    std::string tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    OAIImageFormat format; // Determines the output format of the image - original,gif,jpg,png.
    double percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::int32_t unplayedCount; // Optional. Unplayed count overlay to render.
    std::int32_t imageIndex; // Image index.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
};
struct getItemImageByIndex {
    std::string itemId; // Item id.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // Image index.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Optional. The MediaBrowser.Model.Drawing.ImageFormat of the returned image.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
};
struct getItemImageInfos {
    std::string itemId; // Item id.
};
struct getMusicGenreImage {
    std::string name; // Music genre name.
    OAIImageType imageType; // Image type.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
    std::optional<std::int32_t> imageIndex; // Image index.
};
struct getMusicGenreImageByIndex {
    std::string name; // Music genre name.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // Image index.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
};
struct getPersonImage {
    std::string name; // Person name.
    OAIImageType imageType; // Image type.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
    std::optional<std::int32_t> imageIndex; // Image index.
};
struct getPersonImageByIndex {
    std::string name; // Person name.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // Image index.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
};
struct getSplashscreen {
    std::optional<std::string> tag; // Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Blur image.
    std::optional<std::string> backgroundColor; // Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Apply a foreground layer on top of the image.
    std::optional<std::int32_t> quality; // Quality setting, from 0-100.
};
struct getStudioImage {
    std::string name; // Studio name.
    OAIImageType imageType; // Image type.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
    std::optional<std::int32_t> imageIndex; // Image index.
};
struct getStudioImageByIndex {
    std::string name; // Studio name.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // Image index.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
};
struct getUserImage {
    std::optional<std::string> userId; // User id.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
    std::optional<std::int32_t> imageIndex; // Image index.
};
struct headArtistImage {
    std::string name; // Artist name.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // Image index.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
};
struct headGenreImage {
    std::string name; // Genre name.
    OAIImageType imageType; // Image type.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
    std::optional<std::int32_t> imageIndex; // Image index.
};
struct headGenreImageByIndex {
    std::string name; // Genre name.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // Image index.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
};
struct headItemImage {
    std::string itemId; // Item id.
    OAIImageType imageType; // Image type.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Optional. The MediaBrowser.Model.Drawing.ImageFormat of the returned image.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
    std::optional<std::int32_t> imageIndex; // Image index.
};
struct headItemImage2 {
    std::string itemId; // Item id.
    OAIImageType imageType; // Image type.
    std::int32_t maxWidth; // The maximum image width to return.
    std::int32_t maxHeight; // The maximum image height to return.
    std::string tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    OAIImageFormat format; // Determines the output format of the image - original,gif,jpg,png.
    double percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::int32_t unplayedCount; // Optional. Unplayed count overlay to render.
    std::int32_t imageIndex; // Image index.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
};
struct headItemImageByIndex {
    std::string itemId; // Item id.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // Image index.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Optional. The MediaBrowser.Model.Drawing.ImageFormat of the returned image.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
};
struct headMusicGenreImage {
    std::string name; // Music genre name.
    OAIImageType imageType; // Image type.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
    std::optional<std::int32_t> imageIndex; // Image index.
};
struct headMusicGenreImageByIndex {
    std::string name; // Music genre name.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // Image index.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
};
struct headPersonImage {
    std::string name; // Person name.
    OAIImageType imageType; // Image type.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
    std::optional<std::int32_t> imageIndex; // Image index.
};
struct headPersonImageByIndex {
    std::string name; // Person name.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // Image index.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
};
struct headStudioImage {
    std::string name; // Studio name.
    OAIImageType imageType; // Image type.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
    std::optional<std::int32_t> imageIndex; // Image index.
};
struct headStudioImageByIndex {
    std::string name; // Studio name.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // Image index.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
};
struct headUserImage {
    std::optional<std::string> userId; // User id.
    std::optional<std::string> tag; // Optional. Supply the cache tag from the item object to receive strong caching headers.
    std::optional<OAIImageFormat> format; // Determines the output format of the image - original,gif,jpg,png.
    std::optional<std::int32_t> maxWidth; // The maximum image width to return.
    std::optional<std::int32_t> maxHeight; // The maximum image height to return.
    std::optional<double> percentPlayed; // Optional. Percent to render for the percent played overlay.
    std::optional<std::int32_t> unplayedCount; // Optional. Unplayed count overlay to render.
    std::optional<std::int32_t> width; // The fixed image width to return.
    std::optional<std::int32_t> height; // The fixed image height to return.
    std::optional<std::int32_t> quality; // Optional. Quality setting, from 0-100. Defaults to 90 and should suffice in most cases.
    std::optional<std::int32_t> fillWidth; // Width of box to fill.
    std::optional<std::int32_t> fillHeight; // Height of box to fill.
    std::optional<std::int32_t> blur; // Optional. Blur image.
    std::optional<std::string> backgroundColor; // Optional. Apply a background color for transparent images.
    std::optional<std::string> foregroundLayer; // Optional. Apply a foreground layer on top of the image.
    std::optional<std::int32_t> imageIndex; // Image index.
};
struct postUserImage {
    std::optional<std::string> userId; // User Id.
    std::optional<std::vector<std::byte>> body; // 
};
struct setItemImage {
    std::string itemId; // Item id.
    OAIImageType imageType; // Image type.
    std::optional<std::vector<std::byte>> body; // 
};
struct setItemImageByIndex {
    std::string itemId; // Item id.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // (Unused) Image index.
    std::optional<std::vector<std::byte>> body; // 
};
struct updateItemImageIndex {
    std::string itemId; // Item id.
    OAIImageType imageType; // Image type.
    std::int32_t imageIndex; // Old image index.
    std::int32_t newIndex; // New image index.
};
struct uploadCustomSplashscreen {
    std::optional<std::vector<std::byte>> body; // 
};
}

namespace api 
{
// Delete a custom splashscreen.
struct deleteCustomSplashscreen {
public:
    using in_type                      = param::deleteCustomSplashscreen;
    using out_type                     = model::return_type_deleteCustomSplashscreen;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return "/Branding/Splashscreen"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Image
 * defaultResponse: 
 */
};
// Delete an item&#39;s image.
struct deleteItemImage {
public:
    using in_type                      = param::deleteItemImage;
    using out_type                     = model::return_type_deleteItemImage;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/Items/{}/Images/{}"sv,
            input.itemId,
            input.imageType
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.imageIndex)
            p.set_param("imageIndex", convert_from<std::string>(input.imageIndex.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Image
 * defaultResponse: 
 */
};
// Delete an item&#39;s image.
struct deleteItemImageByIndex {
public:
    using in_type                      = param::deleteItemImageByIndex;
    using out_type                     = model::return_type_deleteItemImageByIndex;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return fmt::format("/Items/{}/Images/{}/{}"sv,
            input.itemId,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Image
 * defaultResponse: 
 */
};
// Delete the user&#39;s image.
struct deleteUserImage {
public:
    using in_type                      = param::deleteUserImage;
    using out_type                     = model::return_type_deleteUserImage;
    constexpr static Operation  oper   = Operation::DELETE;
    auto path() const { 
        return "/UserImage"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Image
 * defaultResponse: 
 */
};
// Get artist image by name.
struct getArtistImage {
public:
    using in_type                      = param::getArtistImage;
    using out_type                     = model::return_type_getArtistImage;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Artists/{}/Images/{}/{}"sv,
            input.name,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get genre image by name.
struct getGenreImage {
public:
    using in_type                      = param::getGenreImage;
    using out_type                     = model::return_type_getGenreImage;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Genres/{}/Images/{}"sv,
            input.name,
            input.imageType
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        if(input.imageIndex)
            p.set_param("imageIndex", convert_from<std::string>(input.imageIndex.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get genre image by name.
struct getGenreImageByIndex {
public:
    using in_type                      = param::getGenreImageByIndex;
    using out_type                     = model::return_type_getGenreImageByIndex;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Genres/{}/Images/{}/{}"sv,
            input.name,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Gets the item&#39;s image.
struct getItemImage {
public:
    using in_type                      = param::getItemImage;
    using out_type                     = model::return_type_getItemImage;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/Images/{}"sv,
            input.itemId,
            input.imageType
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        if(input.imageIndex)
            p.set_param("imageIndex", convert_from<std::string>(input.imageIndex.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Gets the item&#39;s image.
struct getItemImage2 {
public:
    using in_type                      = param::getItemImage2;
    using out_type                     = model::return_type_getItemImage2;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/Images/{}/{}/{}/{}/{}/{}/{}/{}"sv,
            input.itemId,
            input.imageType,
            input.maxWidth,
            input.maxHeight,
            input.tag,
            input.format,
            input.percentPlayed,
            input.unplayedCount,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Gets the item&#39;s image.
struct getItemImageByIndex {
public:
    using in_type                      = param::getItemImageByIndex;
    using out_type                     = model::return_type_getItemImageByIndex;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/Images/{}/{}"sv,
            input.itemId,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get item image infos.
struct getItemImageInfos {
public:
    using in_type                      = param::getItemImageInfos;
    using out_type                     = model::return_type_getItemImageInfos;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Items/{}/Images"sv,
            input.itemId
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;OAIImageInfo&gt;
 * returnFormat: 
 * returnBaseType: OAIImageInfo
 * returnContainer: array
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get music genre image by name.
struct getMusicGenreImage {
public:
    using in_type                      = param::getMusicGenreImage;
    using out_type                     = model::return_type_getMusicGenreImage;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/MusicGenres/{}/Images/{}"sv,
            input.name,
            input.imageType
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        if(input.imageIndex)
            p.set_param("imageIndex", convert_from<std::string>(input.imageIndex.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get music genre image by name.
struct getMusicGenreImageByIndex {
public:
    using in_type                      = param::getMusicGenreImageByIndex;
    using out_type                     = model::return_type_getMusicGenreImageByIndex;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/MusicGenres/{}/Images/{}/{}"sv,
            input.name,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get person image by name.
struct getPersonImage {
public:
    using in_type                      = param::getPersonImage;
    using out_type                     = model::return_type_getPersonImage;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Persons/{}/Images/{}"sv,
            input.name,
            input.imageType
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        if(input.imageIndex)
            p.set_param("imageIndex", convert_from<std::string>(input.imageIndex.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get person image by name.
struct getPersonImageByIndex {
public:
    using in_type                      = param::getPersonImageByIndex;
    using out_type                     = model::return_type_getPersonImageByIndex;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Persons/{}/Images/{}/{}"sv,
            input.name,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Generates or gets the splashscreen.
struct getSplashscreen {
public:
    using in_type                      = param::getSplashscreen;
    using out_type                     = model::return_type_getSplashscreen;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/Branding/Splashscreen"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get studio image by name.
struct getStudioImage {
public:
    using in_type                      = param::getStudioImage;
    using out_type                     = model::return_type_getStudioImage;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Studios/{}/Images/{}"sv,
            input.name,
            input.imageType
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        if(input.imageIndex)
            p.set_param("imageIndex", convert_from<std::string>(input.imageIndex.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get studio image by name.
struct getStudioImageByIndex {
public:
    using in_type                      = param::getStudioImageByIndex;
    using out_type                     = model::return_type_getStudioImageByIndex;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return fmt::format("/Studios/{}/Images/{}/{}"sv,
            input.name,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get user profile image.
struct getUserImage {
public:
    using in_type                      = param::getUserImage;
    using out_type                     = model::return_type_getUserImage;
    constexpr static Operation  oper   = Operation::GET;
    auto path() const { 
        return "/UserImage"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        if(input.imageIndex)
            p.set_param("imageIndex", convert_from<std::string>(input.imageIndex.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get artist image by name.
struct headArtistImage {
public:
    using in_type                      = param::headArtistImage;
    using out_type                     = model::return_type_headArtistImage;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/Artists/{}/Images/{}/{}"sv,
            input.name,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get genre image by name.
struct headGenreImage {
public:
    using in_type                      = param::headGenreImage;
    using out_type                     = model::return_type_headGenreImage;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/Genres/{}/Images/{}"sv,
            input.name,
            input.imageType
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        if(input.imageIndex)
            p.set_param("imageIndex", convert_from<std::string>(input.imageIndex.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get genre image by name.
struct headGenreImageByIndex {
public:
    using in_type                      = param::headGenreImageByIndex;
    using out_type                     = model::return_type_headGenreImageByIndex;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/Genres/{}/Images/{}/{}"sv,
            input.name,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Gets the item&#39;s image.
struct headItemImage {
public:
    using in_type                      = param::headItemImage;
    using out_type                     = model::return_type_headItemImage;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/Items/{}/Images/{}"sv,
            input.itemId,
            input.imageType
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        if(input.imageIndex)
            p.set_param("imageIndex", convert_from<std::string>(input.imageIndex.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Gets the item&#39;s image.
struct headItemImage2 {
public:
    using in_type                      = param::headItemImage2;
    using out_type                     = model::return_type_headItemImage2;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/Items/{}/Images/{}/{}/{}/{}/{}/{}/{}/{}"sv,
            input.itemId,
            input.imageType,
            input.maxWidth,
            input.maxHeight,
            input.tag,
            input.format,
            input.percentPlayed,
            input.unplayedCount,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Gets the item&#39;s image.
struct headItemImageByIndex {
public:
    using in_type                      = param::headItemImageByIndex;
    using out_type                     = model::return_type_headItemImageByIndex;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/Items/{}/Images/{}/{}"sv,
            input.itemId,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get music genre image by name.
struct headMusicGenreImage {
public:
    using in_type                      = param::headMusicGenreImage;
    using out_type                     = model::return_type_headMusicGenreImage;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/MusicGenres/{}/Images/{}"sv,
            input.name,
            input.imageType
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        if(input.imageIndex)
            p.set_param("imageIndex", convert_from<std::string>(input.imageIndex.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get music genre image by name.
struct headMusicGenreImageByIndex {
public:
    using in_type                      = param::headMusicGenreImageByIndex;
    using out_type                     = model::return_type_headMusicGenreImageByIndex;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/MusicGenres/{}/Images/{}/{}"sv,
            input.name,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get person image by name.
struct headPersonImage {
public:
    using in_type                      = param::headPersonImage;
    using out_type                     = model::return_type_headPersonImage;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/Persons/{}/Images/{}"sv,
            input.name,
            input.imageType
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        if(input.imageIndex)
            p.set_param("imageIndex", convert_from<std::string>(input.imageIndex.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get person image by name.
struct headPersonImageByIndex {
public:
    using in_type                      = param::headPersonImageByIndex;
    using out_type                     = model::return_type_headPersonImageByIndex;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/Persons/{}/Images/{}/{}"sv,
            input.name,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get studio image by name.
struct headStudioImage {
public:
    using in_type                      = param::headStudioImage;
    using out_type                     = model::return_type_headStudioImage;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/Studios/{}/Images/{}"sv,
            input.name,
            input.imageType
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        if(input.imageIndex)
            p.set_param("imageIndex", convert_from<std::string>(input.imageIndex.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get studio image by name.
struct headStudioImageByIndex {
public:
    using in_type                      = param::headStudioImageByIndex;
    using out_type                     = model::return_type_headStudioImageByIndex;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return fmt::format("/Studios/{}/Images/{}/{}"sv,
            input.name,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Get user profile image.
struct headUserImage {
public:
    using in_type                      = param::headUserImage;
    using out_type                     = model::return_type_headUserImage;
    constexpr static Operation  oper   = Operation::HEAD;
    auto path() const { 
        return "/UserImage"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        if(input.tag)
            p.set_param("tag", convert_from<std::string>(input.tag.value()));
        if(input.format)
            p.set_param("format", convert_from<std::string>(input.format.value()));
        if(input.maxWidth)
            p.set_param("maxWidth", convert_from<std::string>(input.maxWidth.value()));
        if(input.maxHeight)
            p.set_param("maxHeight", convert_from<std::string>(input.maxHeight.value()));
        if(input.percentPlayed)
            p.set_param("percentPlayed", convert_from<std::string>(input.percentPlayed.value()));
        if(input.unplayedCount)
            p.set_param("unplayedCount", convert_from<std::string>(input.unplayedCount.value()));
        if(input.width)
            p.set_param("width", convert_from<std::string>(input.width.value()));
        if(input.height)
            p.set_param("height", convert_from<std::string>(input.height.value()));
        if(input.quality)
            p.set_param("quality", convert_from<std::string>(input.quality.value()));
        if(input.fillWidth)
            p.set_param("fillWidth", convert_from<std::string>(input.fillWidth.value()));
        if(input.fillHeight)
            p.set_param("fillHeight", convert_from<std::string>(input.fillHeight.value()));
        if(input.blur)
            p.set_param("blur", convert_from<std::string>(input.blur.value()));
        if(input.backgroundColor)
            p.set_param("backgroundColor", convert_from<std::string>(input.backgroundColor.value()));
        if(input.foregroundLayer)
            p.set_param("foregroundLayer", convert_from<std::string>(input.foregroundLayer.value()));
        if(input.imageIndex)
            p.set_param("imageIndex", convert_from<std::string>(input.imageIndex.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: std::vector&lt;std::byte&gt;
 * returnFormat: binary
 * returnBaseType: std::vector&lt;std::byte&gt;
 * returnContainer: 
 * baseName: Image
 * defaultResponse: {}
 */
};
// Sets the user image.
struct postUserImage {
public:
    using in_type                      = param::postUserImage;
    using out_type                     = model::return_type_postUserImage;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/UserImage"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        if(input.userId)
            p.set_param("userId", convert_from<std::string>(input.userId.value()));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        if(input.body)
            out = format_param(input.body.value());
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Image
 * defaultResponse: 
 */
};
// Set item image.
struct setItemImage {
public:
    using in_type                      = param::setItemImage;
    using out_type                     = model::return_type_setItemImage;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Items/{}/Images/{}"sv,
            input.itemId,
            input.imageType
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        if(input.body)
            out = format_param(input.body.value());
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Image
 * defaultResponse: 
 */
};
// Set item image.
struct setItemImageByIndex {
public:
    using in_type                      = param::setItemImageByIndex;
    using out_type                     = model::return_type_setItemImageByIndex;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Items/{}/Images/{}/{}"sv,
            input.itemId,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        if(input.body)
            out = format_param(input.body.value());
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Image
 * defaultResponse: 
 */
};
// Updates the index for an item image.
struct updateItemImageIndex {
public:
    using in_type                      = param::updateItemImageIndex;
    using out_type                     = model::return_type_updateItemImageIndex;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return fmt::format("/Items/{}/Images/{}/{}/Index"sv,
            input.itemId,
            input.imageType,
            input.imageIndex
        );
    }

    auto query() const -> UrlParams {
        UrlParams p;
        p.set_param("newIndex", convert_from<std::string>(input.newIndex));
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Image
 * defaultResponse: 
 */
};
// Uploads a custom splashscreen.  The body is expected to the image contents base64 encoded.
struct uploadCustomSplashscreen {
public:
    using in_type                      = param::uploadCustomSplashscreen;
    using out_type                     = model::return_type_uploadCustomSplashscreen;
    constexpr static Operation  oper   = Operation::POST;
    auto path() const { 
        return "/Branding/Splashscreen"sv; 
    }

    auto query() const -> UrlParams {
        UrlParams p;
        return p;
    }
    auto body() const -> std::string { 
        std::string out;
        if(input.body)
            out = format_param(input.body.value());
        return out; 
    }
    in_type input;

/*
 * returnType: 
 * returnFormat: 
 * returnBaseType: 
 * returnContainer: 
 * baseName: Image
 * defaultResponse: 
 */
};
}
}
