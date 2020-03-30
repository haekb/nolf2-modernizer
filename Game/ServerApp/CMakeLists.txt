project(ServerApp CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "../../Engine/sdk/inc/ltmodule.h"
    "../Shared/CommonUtilities.h"
    "../Shared/DebugNew.h"
    "../Shared/DebugNew_impl.h"
    "../Shared/MsgIDs.h"
    "../Shared/ParsedMsg.h"
    "../Shared/ProfileUtils.h"
    "../Shared/ResShared.h"
    "../Shared/ScmdConsole.h"
    "../Shared/TO2/TO2VersionMgr.h"
    "../Shared/VersionMgr.h"
    "resource.h"
    "ScmdConsoleDriver_ServerApp.h"
    "SelectConfigDlg.h"
    "ServerApp.h"
    "ServerDlg.h"
    "Splash.h"
    "StdAfx.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "../../Engine/sdk/inc/ltmodule.cpp"
    "../Shared/CommonUtilities.cpp"
    "../Shared/DebugNew.cpp"
    "../Shared/GameAlloc.cpp"
    "../Shared/NetDefs.cpp"
    "../Shared/ParsedMsg.cpp"
    "../Shared/ProfileUtils.cpp"
    "../Shared/ScmdConsole.cpp"
    "../Shared/TO2/TO2VersionMgr.cpp"
    "../Shared/VersionMgr.cpp"
    "ScmdConsoleDriver_ServerApp.cpp"
    "SelectConfigDlg.cpp"
    "ServerApp.cpp"
    "ServerDlg.cpp"
    "Splash.cpp"
    "StdAfx.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

add_precompiled_header(${PROJECT_NAME} "StdAfx.h" "StdAfx.cpp")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "MFCProj"
)
################################################################################
# Target name
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG MFC DLL   "NOLF2Srv"
    TARGET_NAME_DEBUG           "NOLF2Srv"
    TARGET_NAME_FINAL DE        "NOLF2Srv"
    TARGET_NAME_FINAL ES        "NOLF2Srv"
    TARGET_NAME_FINAL FR        "NOLF2Srv"
    TARGET_NAME_FINAL IT        "NOLF2Srv"
    TARGET_NAME_FINAL MFC DLL   "NOLF2Srv"
    TARGET_NAME_FINAL           "NOLF2Srv"
    TARGET_NAME_RELEASE MFC DLL "NOLF2Srv"
    TARGET_NAME_RELEASE         "NOLF2Srv"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../Built/Debug/ServerApp"
    OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/../Built/Debug/ServerApp"
    OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/../Built/FinalDE/ServerApp"
    OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/../Built/FinalES/ServerApp"
    OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/../Built/FinalFR/ServerApp"
    OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/../Built/FinalIT/ServerApp"
    OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../Built/FinalES/ServerApp"
    OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/../Built/Final/ServerApp"
    OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/../Built/Release/ServerApp"
    OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/../Built/Release/ServerApp"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/EN;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith"
    ">"
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/EN;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith"
    ">"
    "$<$<CONFIG:Final DE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/DE;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith"
    ">"
    "$<$<CONFIG:Final ES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/ES;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith"
    ">"
    "$<$<CONFIG:Final FR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/FR;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith"
    ">"
    "$<$<CONFIG:Final IT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/IT;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/ES;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/EN;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/EN;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../Shared/Lang/EN;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/stdlith"
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
        "_MBCS"
    ">"
    "$<$<CONFIG:Debug>:"
        "_DEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_MBCS"
    ">"
    "$<$<CONFIG:Final DE>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:Final ES>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:Final FR>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:Final IT>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:Final>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_MBCS"
    ">"
    "$<$<CONFIG:Release>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_MBCS"
    ">"
)

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug MFC DLL>:
            /Gm;
            /Od;
            /MDd;
            /Gy;
            /W3;
            /ZI;
            /GR
        >
        $<$<CONFIG:Debug>:
            /Gm;
            /Od;
            /MDd;
            /Gy;
            /W3;
            /ZI;
            /GR
        >
        $<$<CONFIG:Final DE>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /GR
        >
        $<$<CONFIG:Final ES>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /GR
        >
        $<$<CONFIG:Final FR>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /GR
        >
        $<$<CONFIG:Final IT>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /GR
        >
        $<$<CONFIG:Final MFC DLL>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /GR
        >
        $<$<CONFIG:Final>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /GR
        >
        $<$<CONFIG:Release MFC DLL>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /GR
        >
        $<$<CONFIG:Release>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /GR
        >
        $<$<CONFIG:Template>:
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
    )
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Y-"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Y-"
        ">"
        "$<$<CONFIG:Final DE>:"
            "/Y-"
        ">"
        "$<$<CONFIG:Final ES>:"
            "/Y-"
        ">"
        "$<$<CONFIG:Final FR>:"
            "/Y-"
        ">"
        "$<$<CONFIG:Final IT>:"
            "/Y-"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "/Y-"
        ">"
        "$<$<CONFIG:Final>:"
            "/Y-"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "/Y-"
        ">"
        "$<$<CONFIG:Release>:"
            "/Y-"
        ">"
    )
    source_file_compile_options(../../Engine/sdk/inc/ltmodule.cpp ${FILE_CL_OPTIONS})
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
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    Lib_Lith
    regmgr32
    RegMgr
    Lib_StdLith
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    Lib_Lith
    regmgr32
    RegMgr
    Lib_StdLith
)

set(ADDITIONAL_LIBRARY_DEPENDENCIES
    "$<$<CONFIG:Debug MFC DLL>:"
        "server;"
        "regmgr32;"
        "regmgr;"
        "lib_lith;"
        "ButeMgrMfcDll;"
        "cryptmgrmfcdll;"
        "lib_stdlith;"
        "winmm"
    ">"
    "$<$<CONFIG:Debug>:"
        "server;"
        "regmgr32;"
        "regmgr;"
        "lib_lith;"
        "ButeMgrMfcDll;"
        "cryptmgrmfcdll;"
        "lib_stdlith;"
        "winmm"
    ">"
    "$<$<CONFIG:Final DE>:"
        "server;"
        "regmgr32;"
        "regmgr;"
        "lib_lith;"
        "ButeMgrMfcDll;"
        "cryptmgrMfcDll;"
        "lib_stdlith;"
        "winmm"
    ">"
    "$<$<CONFIG:Final ES>:"
        "server;"
        "regmgr32;"
        "regmgr;"
        "lib_lith;"
        "ButeMgrMfcDll;"
        "cryptmgrMfcDll;"
        "lib_stdlith;"
        "winmm"
    ">"
    "$<$<CONFIG:Final FR>:"
        "server;"
        "regmgr32;"
        "regmgr;"
        "lib_lith;"
        "ButeMgrMfcDll;"
        "cryptmgrMfcDll;"
        "lib_stdlith;"
        "winmm"
    ">"
    "$<$<CONFIG:Final IT>:"
        "server;"
        "regmgr32;"
        "regmgr;"
        "lib_lith;"
        "ButeMgrMfcDll;"
        "cryptmgrMfcDll;"
        "lib_stdlith;"
        "winmm"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "server;"
        "regmgr32;"
        "regmgr;"
        "lib_lith;"
        "ButeMgrMfcDll;"
        "cryptmgrMfcDll;"
        "lib_stdlith;"
        "winmm"
    ">"
    "$<$<CONFIG:Final>:"
        "server;"
        "regmgr32;"
        "regmgr;"
        "lib_lith;"
        "ButeMgrMfcDll;"
        "cryptmgrMfcDll;"
        "lib_stdlith;"
        "winmm"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "server;"
        "regmgr32;"
        "regmgr;"
        "lib_lith;"
        "ButeMgrMfcDll;"
        "cryptmgrMfcDll;"
        "lib_stdlith;"
        "winmm"
    ">"
    "$<$<CONFIG:Release>:"
        "server;"
        "regmgr32;"
        "regmgr;"
        "lib_lith;"
        "ButeMgrMfcDll;"
        "cryptmgrMfcDll;"
        "lib_stdlith;"
        "winmm"
    ">"
)
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

target_link_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../engine/sdk/lib;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/debug/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/debug/regmgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/debug/lib_lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/debug/ButeMgrMFCDll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/debug/cryptmgrmfcdll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/debug/lib_stdlith"
    ">"
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../engine/sdk/lib;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/debug/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/debug/regmgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/debug/lib_lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/debug/ButeMgrMFCDll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/debug/cryptmgrmfcdll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/debug/lib_stdlith"
    ">"
    "$<$<CONFIG:Final DE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../engine/built/Final/Runtime/DLL_Server;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/regmgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/lib_lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/ButeMgrMFCDll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/cryptmgrmfcdll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/lib_stdlith"
    ">"
    "$<$<CONFIG:Final ES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../engine/built/Final/Runtime/DLL_Server;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/regmgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/lib_lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/ButeMgrMFCDll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/cryptmgrmfcdll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/lib_stdlith"
    ">"
    "$<$<CONFIG:Final FR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../engine/built/Final/Runtime/DLL_Server;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/regmgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/lib_lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/ButeMgrMFCDll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/cryptmgrmfcdll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/lib_stdlith"
    ">"
    "$<$<CONFIG:Final IT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../engine/built/Final/Runtime/DLL_Server;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/regmgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/lib_lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/ButeMgrMFCDll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/cryptmgrmfcdll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/lib_stdlith"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../engine/built/Final/Runtime/DLL_Server;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/regmgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/lib_lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/ButeMgrMFCDll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/cryptmgrmfcdll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/lib_stdlith"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../engine/sdk/lib;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/regmgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/lib_lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/ButeMgrMFCDll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/cryptmgrmfcdll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/Final/lib_stdlith"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../engine/sdk/lib;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/release/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/release/regmgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/release/lib_lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/release/ButeMgrMFCDll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/release/cryptmgrmfcdll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/release/lib_stdlith"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../engine/sdk/lib;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/release/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/release/regmgr32;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/release/lib_lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/release/ButeMgrMFCDll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/release/cryptmgrmfcdll;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/built/release/lib_stdlith"
    ">"
)

