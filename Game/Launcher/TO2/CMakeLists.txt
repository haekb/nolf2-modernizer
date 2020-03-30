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
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG         "NOLF2"
    TARGET_NAME_DEBUGMFCDLL   "NOLF2"
    TARGET_NAME_FINAL         "NOLF2"
    TARGET_NAME_FINALDE       "NOLF2"
    TARGET_NAME_FINALES       "NOLF2"
    TARGET_NAME_FINALFR       "NOLF2"
    TARGET_NAME_FINALIT       "NOLF2"
    TARGET_NAME_FINALMFCDLL   "NOLF2"
    TARGET_NAME_RELEASE       "NOLF2"
    TARGET_NAME_RELEASEMFCDLL "NOLF2"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/Launcher"
    OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/Launcher"
    OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/Launcher"
    OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/FinalDE/Launcher"
    OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/FinalES/Launcher"
    OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/FinalFR/Launcher"
    OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/FinalIT/Launcher"
    OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/Launcher"
    OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/Launcher"
    OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/Launcher"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/..;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/..;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
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
    "$<$<CONFIG:FinalDE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/..;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
    ">"
    "$<$<CONFIG:FinalES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/..;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/..;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/..;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
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
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/..;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr32"
    ">"
)

################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:"
        "WIN32;"
        "_DEBUG;"
        "_WINDOWS;"
        "_MBCS"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "WIN32;"
        "_DEBUG;"
        "_WINDOWS;"
        "_MBCS"
    ">"
    "$<$<CONFIG:Final>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:FinalES>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
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
    "$<$<CONFIG:ReleaseMFCDLL>:"
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
        $<$<CONFIG:Debug>:
            /Gm;
            /Od;
            /RTC1;
            /MDd;
            /Gy;
            /W3;
            /ZI
        >
        $<$<CONFIG:DebugMFCDLL>:
            /Gm;
            /Od;
            /RTC1;
            /MDd;
            /Gy;
            /W3;
            /ZI
        >
        $<$<CONFIG:Final>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalDE>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalES>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalFR>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalIT>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalMFCDLL>:
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
        $<$<CONFIG:ReleaseMFCDLL>:
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
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:
            /NODEFAULTLIB:nafxcw.lib;
            /NODEFAULTLIB:libcmt.lib;
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:DebugMFCDLL>:
            /NODEFAULTLIB:nafxcw.lib;
            /NODEFAULTLIB:libcmt.lib;
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:Final>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:FinalDE>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:FinalES>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:FinalFR>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:FinalIT>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:FinalMFCDLL>:
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
        $<$<CONFIG:ReleaseMFCDLL>:
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

