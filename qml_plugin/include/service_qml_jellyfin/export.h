#pragma once
#include "core/macro.h"

#if defined(SERVICE_QML_JF_EXPORT)
#    define SERVICE_QML_JF_API C_DECL_EXPORT
#else
#    define SERVICE_QML_JF_API C_DECL_IMPORT
#endif