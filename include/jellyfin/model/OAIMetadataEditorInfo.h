#pragma once

/*
 * OAIMetadataEditorInfo.h
 * name: MetadataEditorInfo
 * schemaName: MetadataEditorInfo
 * classFilename: MetadataEditorInfo
 * classVarName: MetadataEditorInfo
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * 
 */


#include "jellyfin/type.h"


#include "jellyfin/model/OAICollectionType.h"
#include "jellyfin/model/OAICountryInfo.h"
#include "jellyfin/model/OAICultureDto.h"
#include "jellyfin/model/OAIExternalIdInfo.h"
#include "jellyfin/model/OAINameValuePair.h"
#include "jellyfin/model/OAIParentalRating.h"
#include <vector>



namespace jellyfin::model {
class OAIParentalRating;
class OAICountryInfo;
class OAICultureDto;
class OAIExternalIdInfo;
class OAINameValuePair;


    class OAIMetadataEditorInfo {
    public:
    
        std::vector<OAIParentalRating> ParentalRatingOptions;

        std::vector<OAICountryInfo> Countries;

        std::vector<OAICultureDto> Cultures;

        std::vector<OAIExternalIdInfo> ExternalIdInfos;

        std::optional<OAICollectionType> ContentType;

        std::vector<OAINameValuePair> ContentTypeOptions;

        OAIMetadataEditorInfo();
        ~OAIMetadataEditorInfo();
    };
    extern void to_json(json_t&, const OAIMetadataEditorInfo&);
    extern void from_json(const json_t&, OAIMetadataEditorInfo&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAIMetadataEditorInfo);
