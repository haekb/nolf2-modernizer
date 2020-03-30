project(AutoRun CXX)

################################################################################
# Source groups
################################################################################
set(Headers
    "resource.h"
    "STDAFX.H"
    "Utils.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "AutoRun.cpp"
    "Utils.cpp"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${Headers}
    ${Sources}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
################################################################################
# Target name
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG MFC DLL   "AutoRun"
    TARGET_NAME_DEBUG           "AutoRun"
    TARGET_NAME_FINAL DE        "AutoRun"
    TARGET_NAME_FINAL ES        "AutoRun"
    TARGET_NAME_FINAL FR        "AutoRun"
    TARGET_NAME_FINAL IT        "AutoRun"
    TARGET_NAME_FINAL MFC DLL   "AutoRun"
    TARGET_NAME_FINAL           "AutoRun"
    TARGET_NAME_RELEASE MFC DLL "AutoRun"
    TARGET_NAME_RELEASE         "AutoRun"
    TARGET_NAME_TEMPLATE        "AutoRun"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/debug/AutoRun"
    OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/debug/AutoRun"
    OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun"
    OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun"
    OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun"
    OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun"
    OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun"
    OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun"
    OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/./../built/release/AutoRun"
    OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/release/AutoRun"
    OUTPUT_DIRECTORY_TEMPLATE        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/release/AutoRun"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../clientres/shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../clientres/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/butemgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/cryptmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/mfcstub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ltguimgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/serverdir"
    ">"
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../clientres/shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../clientres/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/butemgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/cryptmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/mfcstub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ltguimgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/serverdir"
    ">"
    "$<$<CONFIG:Final DE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../proj/nolf/lt2/lithshared/incs"
    ">"
    "$<$<CONFIG:Final ES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../proj/nolf/lt2/lithshared/incs"
    ">"
    "$<$<CONFIG:Final FR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../proj/nolf/lt2/lithshared/incs"
    ">"
    "$<$<CONFIG:Final IT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../proj/nolf/lt2/lithshared/incs"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../proj/nolf/lt2/lithshared/incs"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../proj/nolf/lt2/lithshared/incs"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../clientres/shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../clientres/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/butemgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/cryptmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/mfcstub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ltguimgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/serverdir"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../clientres/shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../clientres/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/butemgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/cryptmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/mfcstub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ltguimgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/serverdir"
    ">"
    "$<$<CONFIG:Template>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../clientres/shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../clientres/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/butemgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/cryptmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/mfcstub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/ltguimgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/regmgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/serverdir"
    ">"
    "${CMAKE_CURRENT_SOURCE_DIR}/.;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/STLPort-4.0/stlport;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
    "${CMAKE_CURRENT_SOURCE_DIR}/..;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/RegMgr32"
)

################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug MFC DLL>:"
        "_DEBUG"
    ">"
    "$<$<CONFIG:Debug>:"
        "_DEBUG"
    ">"
    "$<$<CONFIG:Final DE>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Final ES>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Final FR>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Final IT>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Final>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Release>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Template>:"
        "NDEBUG"
    ">"
    "WIN32;"
    "_WINDOWS"
)

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug MFC DLL>:
            /Gm-;
            /Od;
            /MTd;
            /ZI
        >
        $<$<CONFIG:Debug>:
            /Gm-;
            /Od;
            /MTd;
            /ZI
        >
        $<$<CONFIG:Final DE>:
            /O2;
            /GF;
            /MT;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:Final ES>:
            /O2;
            /GF;
            /MT;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:Final FR>:
            /O2;
            /GF;
            /MT;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:Final IT>:
            /O2;
            /GF;
            /MT;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:Final MFC DLL>:
            /O2;
            /GF;
            /MT;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:Final>:
            /O2;
            /GF;
            /MT;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:Release MFC DLL>:
            /O2;
            /GF;
            /MT;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:Release>:
            /O2;
            /GF;
            /MT;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:Template>:
            /O2;
            /GF;
            /MT;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        /Gy;
        /W3;
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug MFC DLL>:
            /DEBUG;
            /INCREMENTAL
        >
        $<$<CONFIG:Debug>:
            /DEBUG;
            /INCREMENTAL
        >
        $<$<CONFIG:Final DE>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final ES>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final FR>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final IT>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final MFC DLL>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Release MFC DLL>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Release>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Template>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        /NOLOGO;
        /SUBSYSTEM:WINDOWS
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

