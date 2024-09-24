#pragma once

/*
 * OAINetworkConfiguration.h
 * name: NetworkConfiguration
 * schemaName: NetworkConfiguration
 * classFilename: NetworkConfiguration
 * classVarName: NetworkConfiguration
 * dataType: rc&lt;json_t&gt;
 * isNullable: false
 * isDeprecated: false
 * isEnum: false, isModel: true
 * parent: 
 * xmlPrefix: , xmlNamespace: , xmlName: 
 * Defines the MediaBrowser.Common.Net.NetworkConfiguration.
 */


#include "jellyfin/type.h"


#include <cstdint>
#include <string>
#include <vector>



namespace jellyfin::model {


    class OAINetworkConfiguration {
    public:
    
        // Gets or sets a value used to specify the URL prefix that your Jellyfin instance can be accessed at.
        std::string BaseUrl;

        // Gets or sets a value indicating whether to use HTTPS.
        bool EnableHttps;

        // Gets or sets a value indicating whether the server should force connections over HTTPS.
        bool RequireHttps;

        // Gets or sets the filesystem path of an X.509 certificate to use for SSL.
        std::string CertificatePath;

        // Gets or sets the password required to access the X.509 certificate data in the file specified by MediaBrowser.Common.Net.NetworkConfiguration.CertificatePath.
        std::string CertificatePassword;

        // Gets or sets the internal HTTP server port.
        std::int32_t InternalHttpPort;

        // Gets or sets the internal HTTPS server port.
        std::int32_t InternalHttpsPort;

        // Gets or sets the public HTTP port.
        std::int32_t PublicHttpPort;

        // Gets or sets the public HTTPS port.
        std::int32_t PublicHttpsPort;

        // Gets or sets a value indicating whether Autodiscovery is enabled.
        bool AutoDiscovery;

        // Gets or sets a value indicating whether to enable automatic port forwarding.
        bool EnableUPnP;

        // Gets or sets a value indicating whether IPv6 is enabled.
        bool EnableIPv4;

        // Gets or sets a value indicating whether IPv6 is enabled.
        bool EnableIPv6;

        // Gets or sets a value indicating whether access from outside of the LAN is permitted.
        bool EnableRemoteAccess;

        // Gets or sets the subnets that are deemed to make up the LAN.
        std::vector<std::string> LocalNetworkSubnets;

        // Gets or sets the interface addresses which Jellyfin will bind to. If empty, all interfaces will be used.
        std::vector<std::string> LocalNetworkAddresses;

        // Gets or sets the known proxies.
        std::vector<std::string> KnownProxies;

        // Gets or sets a value indicating whether address names that match MediaBrowser.Common.Net.NetworkConfiguration.VirtualInterfaceNames should be ignored for the purposes of binding.
        bool IgnoreVirtualInterfaces;

        // Gets or sets a value indicating the interface name prefixes that should be ignored. The list can be comma separated and values are case-insensitive. &lt;seealso cref&#x3D;\&quot;P:MediaBrowser.Common.Net.NetworkConfiguration.IgnoreVirtualInterfaces\&quot; /&gt;.
        std::vector<std::string> VirtualInterfaceNames;

        // Gets or sets a value indicating whether the published server uri is based on information in HTTP requests.
        bool EnablePublishedServerUriByRequest;

        // Gets or sets the PublishedServerUriBySubnet  Gets or sets PublishedServerUri to advertise for specific subnets.
        std::vector<std::string> PublishedServerUriBySubnet;

        // Gets or sets the filter for remote IP connectivity. Used in conjunction with &lt;seealso cref&#x3D;\&quot;P:MediaBrowser.Common.Net.NetworkConfiguration.IsRemoteIPFilterBlacklist\&quot; /&gt;.
        std::vector<std::string> RemoteIPFilter;

        // Gets or sets a value indicating whether &lt;seealso cref&#x3D;\&quot;P:MediaBrowser.Common.Net.NetworkConfiguration.RemoteIPFilter\&quot; /&gt; contains a blacklist or a whitelist. Default is a whitelist.
        bool IsRemoteIPFilterBlacklist;

        OAINetworkConfiguration();
        ~OAINetworkConfiguration();
    };
    extern void to_json(json_t&, const OAINetworkConfiguration&);
    extern void from_json(const json_t&, OAINetworkConfiguration&);
} // namespace jellyfin::model
DECLARE_CONVERT(std::string, jellyfin::model::OAINetworkConfiguration);
