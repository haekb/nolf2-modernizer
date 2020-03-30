project(ClientFxDLL CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "../Shared/BankedList.h"
    "../Shared/BankedList_impl.h"
    "../Shared/BaseFx.h"
    "../Shared/DebugNew.h"
    "../Shared/DebugNew_impl.h"
    "bouncychunkfx.h"
    "camjitterfx.h"
    "camwobblefx.h"
    "clientfx.h"
    "CreateFX.h"
    "cycletimer.h"
    "dynalightfx.h"
    "fallingstufffx.h"
    "FlareSpriteFX.h"
    "lightningfx.h"
    "LTBbouncychunkfx.h"
    "ltbmodelfx.h"
    "memarray.h"
    "nullfx.h"
    "ParticleSystemFX.h"
    "playrandomsoundfx.h"
    "playsoundfx.h"
    "polyfanfx.h"
    "polytubefx.h"
    "resource.h"
    "spritefx.h"
    "spritesystemfx.h"
    "stdafx.h"
    "swaplist.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "../../Engine/sdk/inc/ltmodule.cpp"
    "../../Engine/sdk/inc/ltquatbase.cpp"
    "../Shared/DebugNew.cpp"
    "BaseFx.cpp"
    "bouncychunkfx.cpp"
    "camjitterfx.cpp"
    "camwobblefx.cpp"
    "clientfx.cpp"
    "CreateFX.cpp"
    "cycletimer.cpp"
    "dynalightfx.cpp"
    "fallingstufffx.cpp"
    "FlareSpriteFX.cpp"
    "lightningfx.cpp"
    "LTBbouncychunkfx.cpp"
    "ltbmodelfx.cpp"
    "nullfx.cpp"
    "ParticleSystemFX.cpp"
    "playrandomsoundfx.cpp"
    "playsoundfx.cpp"
    "polyfanfx.cpp"
    "polytubefx.cpp"
    "spritefx.cpp"
    "spritesystemfx.cpp"
    "stdafx.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})

add_precompiled_header(${PROJECT_NAME} "stdafx.h" "stdafx.cpp")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
################################################################################
# Target name
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG MFC DLL   "ClientFx"
    TARGET_NAME_DEBUG           "ClientFx"
    TARGET_NAME_FINAL DE        "ClientFx"
    TARGET_NAME_FINAL ES        "ClientFx"
    TARGET_NAME_FINAL FR        "ClientFx"
    TARGET_NAME_FINAL IT        "ClientFx"
    TARGET_NAME_FINAL MFC DLL   "ClientFx"
    TARGET_NAME_FINAL           "ClientFx"
    TARGET_NAME_RELEASE MFC DLL "ClientFx"
    TARGET_NAME_RELEASE         "ClientFx"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/debug/ClientFxDll"
    OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/../built/debug/ClientFxDll"
    OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ClientFxDll"
    OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ClientFxDll"
    OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ClientFxDll"
    OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ClientFxDll"
    OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ClientFxDll"
    OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ClientFxDll"
    OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/ClientFxDll"
    OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/ClientFxDll"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/debug/ClientFxDll"
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/debug/ClientFxDll"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/ClientFxDll"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/ClientFxDll"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/ClientFxDll"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/ClientFxDll"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/ClientFxDll"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/ClientFxDll"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/ClientFxDll"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/ClientFxDll"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_NAME_DEBUG MFC DLL   "ClientFx"
    ARCHIVE_OUTPUT_NAME_DEBUG           "ClientFx"
    ARCHIVE_OUTPUT_NAME_FINAL DE        "ClientFx"
    ARCHIVE_OUTPUT_NAME_FINAL ES        "ClientFx"
    ARCHIVE_OUTPUT_NAME_FINAL FR        "ClientFx"
    ARCHIVE_OUTPUT_NAME_FINAL IT        "ClientFx"
    ARCHIVE_OUTPUT_NAME_FINAL MFC DLL   "ClientFx"
    ARCHIVE_OUTPUT_NAME_FINAL           "ClientFx"
    ARCHIVE_OUTPUT_NAME_RELEASE MFC DLL "ClientFx"
    ARCHIVE_OUTPUT_NAME_RELEASE         "ClientFx"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Libs/LTGUIMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-STD"
    ">"
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Libs/LTGUIMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-STD"
    ">"
    "$<$<CONFIG:Final DE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Libs/LTGUIMgr"
    ">"
    "$<$<CONFIG:Final ES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Libs/LTGUIMgr"
    ">"
    "$<$<CONFIG:Final FR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Libs/LTGUIMgr"
    ">"
    "$<$<CONFIG:Final IT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Libs/LTGUIMgr"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Libs/LTGUIMgr"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Libs/LTGUIMgr"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Libs/LTGUIMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-STD"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Libs/LTGUIMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-STD"
    ">"
)

################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug MFC DLL>:"
        "_DEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "MEMTRACK_CLIENTFX;"
        "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS"
    ">"
    "$<$<CONFIG:Debug>:"
        "_DEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "MEMTRACK_CLIENTFX;"
        "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS"
    ">"
    "$<$<CONFIG:Final DE>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_FINAL;"
        "MEMTRACK_CLIENTFX"
    ">"
    "$<$<CONFIG:Final ES>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_FINAL;"
        "MEMTRACK_CLIENTFX"
    ">"
    "$<$<CONFIG:Final FR>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_FINAL;"
        "MEMTRACK_CLIENTFX"
    ">"
    "$<$<CONFIG:Final IT>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_FINAL;"
        "MEMTRACK_CLIENTFX"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_FINAL;"
        "MEMTRACK_CLIENTFX"
    ">"
    "$<$<CONFIG:Final>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_FINAL;"
        "MEMTRACK_CLIENTFX"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "MEMTRACK_CLIENTFX;"
        "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS"
    ">"
    "$<$<CONFIG:Release>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "MEMTRACK_CLIENTFX;"
        "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS"
    ">"
)

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug MFC DLL>:
            /Od;
            /RTC1;
            /MDd;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:Debug>:
            /Od;
            /RTC1;
            /MDd;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:Final DE>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:Final ES>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:Final FR>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:Final IT>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:Final MFC DLL>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:Final>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:Release MFC DLL>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000;
            /Zc:forScope-
        >
        $<$<CONFIG:Release>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000;
            /Zc:forScope-
        >
        $<$<CONFIG:Template>:
            ${DEFAULT_CXX_RUNTIME_LIBRARY}
        >
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
    )
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
    )
    source_file_compile_options(../../Engine/sdk/inc/ltmodule.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000;/Y-"
        ">"
    )
    source_file_compile_options(../../Engine/sdk/inc/ltquatbase.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(../Shared/DebugNew.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(BaseFx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(bouncychunkfx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(camjitterfx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(camwobblefx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(clientfx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(CreateFX.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(cycletimer.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(dynalightfx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(fallingstufffx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(FlareSpriteFX.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(lightningfx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(LTBbouncychunkfx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ltbmodelfx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(nullfx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ParticleSystemFX.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(playrandomsoundfx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(playsoundfx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(polyfanfx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(polytubefx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(spritefx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(spritesystemfx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(stdafx.cpp ${FILE_CL_OPTIONS})
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug MFC DLL>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:Debug>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:Final DE>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final ES>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final FR>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final IT>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final MFC DLL>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Release MFC DLL>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Release>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Template>:
            /DEBUG:FULL
        >
    )
endif()

################################################################################
# Post build events
################################################################################
add_custom_command_if(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMANDS
    COMMAND   $<CONFIG:Debug MFC DLL> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
    COMMAND           $<CONFIG:Debug> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
)

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    ButeMgr
    CryptMgr
    Lib_Lith
    MFCStub
    Lib_StdLith
    LTGUIMgr
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    ButeMgr
    CryptMgr
    Lib_Lith
    MFCStub
    Lib_StdLith
    LTGUIMgr
)

set(ADDITIONAL_LIBRARY_DEPENDENCIES
    "$<$<CONFIG:Debug MFC DLL>:"
        "kernel32;"
        "user32;"
        "gdi32;"
        "ButeMgr;"
        "cryptmgr;"
        "Lib_Lith;"
        "Lib_StdLith;"
        "ltguimgr;"
        "MFCStub"
    ">"
    "$<$<CONFIG:Debug>:"
        "kernel32;"
        "user32;"
        "gdi32;"
        "ButeMgr;"
        "cryptmgr;"
        "Lib_Lith;"
        "Lib_StdLith;"
        "ltguimgr;"
        "MFCStub"
    ">"
    "$<$<CONFIG:Final DE>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final ES>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final FR>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final IT>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Release>:"
        "odbc32;"
        "odbccp32"
    ">"
)
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

target_link_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug MFC DLL>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/ButeMgr;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/cryptmgr;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/MFCStub;"
        "${CMAKE_SOURCE_DIR}//built/debug/libs/ltguimgr"
    ">"
    "$<$<CONFIG:Debug>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/ButeMgr;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/cryptmgr;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/MFCStub;"
        "${CMAKE_SOURCE_DIR}//built/debug/libs/ltguimgr"
    ">"
)

