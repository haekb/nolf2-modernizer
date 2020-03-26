project(Launcher CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "../BitmapCheckButton.h"
    "../ButtonEx.h"
    "../CustomizeDlg.h"
    "../DetailSettingsDlg.h"
    "../DisplayDlg.h"
    "../DisplayMgr.h"
    "../DlgEx.h"
    "../EditEx.h"
    "../Launcher.h"
    "../LauncherDlg.h"
    "../MessageBoxDlg.h"
    "../MoveDlg.h"
    "../OptionsDlg.h"
    "../PlaySound.h"
    "../RezFind.h"
    "../StaticEx.h"
    "../StdAfx.h"
    "../TextCheckBox.h"
    "../Utils.h"
    "resource.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "../BitmapCheckButton.cpp"
    "../ButtonEx.cpp"
    "../CustomizeDlg.cpp"
    "../DetailSettingsDlg.cpp"
    "../DisplayDlg.cpp"
    "../DisplayMgr.cpp"
    "../DlgEx.cpp"
    "../EditEx.cpp"
    "../Launcher.cpp"
    "../LauncherDlg.cpp"
    "../MessageBoxDlg.cpp"
    "../MoveDlg.cpp"
    "../OptionsDlg.cpp"
    "../RezFind.cpp"
    "../StaticEx.cpp"
    "../StdAfx.cpp"
    "../TextCheckBox.cpp"
    "../Utils.cpp"
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

add_precompiled_header(${PROJECT_NAME} "StdAfx.h" "../StdAfx.cpp")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "MFCProj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG           "NOLF2"
        TARGET_NAME_FINAL DE        "NOLF2"
        TARGET_NAME_FINAL ES        "NOLF2"
        TARGET_NAME_FINAL FR        "NOLF2"
        TARGET_NAME_FINAL IT        "NOLF2"
        TARGET_NAME_FINAL           "NOLF2"
        TARGET_NAME_RELEASE         "NOLF2"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG MFC DLL   "NOLF2"
        TARGET_NAME_DEBUG           "NOLF2"
        TARGET_NAME_FINAL DE        "NOLF2"
        TARGET_NAME_FINAL ES        "NOLF2"
        TARGET_NAME_FINAL FR        "NOLF2"
        TARGET_NAME_FINAL IT        "NOLF2"
        TARGET_NAME_FINAL MFC DLL   "NOLF2"
        TARGET_NAME_FINAL           "NOLF2"
        TARGET_NAME_RELEASE MFC DLL "NOLF2"
        TARGET_NAME_RELEASE         "NOLF2"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/Launcher"
        OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/FinalDE/Launcher"
        OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/FinalES/Launcher"
        OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/FinalFR/Launcher"
        OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/FinalIT/Launcher"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/Launcher"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/Launcher"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/Launcher"
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/Launcher"
        OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/FinalDE/Launcher"
        OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/FinalES/Launcher"
        OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/FinalFR/Launcher"
        OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/FinalIT/Launcher"
        OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/FinalES/Launcher"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/Launcher"
        OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/Launcher"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/Launcher"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Final DE>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Final ES>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Final FR>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Final IT>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Final>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Release>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Debug>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Final DE>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Final ES>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Final FR>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Final IT>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Final>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
        "$<$<CONFIG:Release>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/..;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
        ">"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "WIN32;"
            "_DEBUG;"
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
        "$<$<CONFIG:Final>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS;"
            "_FINAL;"
            "_MBCS"
        ">"
        "$<$<CONFIG:Release>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS;"
            "_MBCS"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug MFC DLL>:"
            "WIN32;"
            "_DEBUG;"
            "_WINDOWS;"
            "_MBCS"
        ">"
        "$<$<CONFIG:Debug>:"
            "WIN32;"
            "_DEBUG;"
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
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug MFC DLL>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Debug>:
                /Gm;
                /Od;
                /RTC1;
                /MDd;
                /Gy;
                /W3;
                /ZI
            >
            $<$<CONFIG:Final DE>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final ES>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final FR>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final IT>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final MFC DLL>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Release MFC DLL>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Release>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Template>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug MFC DLL>:
                /Gm;
                /Od;
                /RTC1;
                /MDd;
                /Gy;
                /W3;
                /ZI
            >
            $<$<CONFIG:Debug>:
                /Gm;
                /Od;
                /RTC1;
                /MDd;
                /Gy;
                /W3;
                /ZI
            >
            $<$<CONFIG:Final DE>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final ES>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final FR>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final IT>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final MFC DLL>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Release MFC DLL>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Release>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Template>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug MFC DLL>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Debug>:
                /NODEFAULTLIB:nafxcw.lib;
                /NODEFAULTLIB:libcmt.lib;
                /NOLOGO;
                /DEBUG;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Final DE>:
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Final ES>:
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Final FR>:
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Final IT>:
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Final MFC DLL>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Final>:
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Release MFC DLL>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Release>:
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Template>:
                /DEBUG:FULL
            >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug MFC DLL>:
                /NODEFAULTLIB:nafxcw.lib;
                /NODEFAULTLIB:libcmt.lib;
                /NOLOGO;
                /DEBUG;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Debug>:
                /NODEFAULTLIB:nafxcw.lib;
                /NODEFAULTLIB:libcmt.lib;
                /NOLOGO;
                /DEBUG;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Final DE>:
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Final ES>:
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Final FR>:
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Final IT>:
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Final MFC DLL>:
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Final>:
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Release MFC DLL>:
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
            >
            $<$<CONFIG:Template>:
                /DEBUG:FULL
            >
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    regmgr32
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    regmgr32
)

