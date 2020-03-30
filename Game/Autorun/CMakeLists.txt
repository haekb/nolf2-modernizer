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
    TARGET_NAME_DEBUG         "AutoRun"
    TARGET_NAME_DEBUGMFCDLL   "AutoRun"
    TARGET_NAME_FINAL         "AutoRun"
    TARGET_NAME_FINALDE       "AutoRun"
    TARGET_NAME_FINALES       "AutoRun"
    TARGET_NAME_FINALFR       "AutoRun"
    TARGET_NAME_FINALIT       "AutoRun"
    TARGET_NAME_FINALMFCDLL   "AutoRun"
    TARGET_NAME_RELEASE       "AutoRun"
    TARGET_NAME_RELEASEMFCDLL "AutoRun"
    TARGET_NAME_TEMPLATE      "AutoRun"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/debug/AutoRun"
    OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/debug/AutoRun"
    OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun"
    OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun"
    OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun"
    OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun"
    OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun"
    OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun"
    OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/release/AutoRun"
    OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/./../built/release/AutoRun"
    OUTPUT_DIRECTORY_TEMPLATE      "${CMAKE_CURRENT_SOURCE_DIR}/./../built/release/AutoRun"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
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
    "$<$<CONFIG:DebugMFCDLL>:"
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
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../proj/nolf/lt2/lithshared/incs"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../proj/nolf/lt2/lithshared/incs"
    ">"
    "$<$<CONFIG:FinalES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../proj/nolf/lt2/lithshared/incs"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../proj/nolf/lt2/lithshared/incs"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../proj/nolf/lt2/lithshared/incs"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../../proj/nolf/lt2/lithshared/incs"
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
    "$<$<CONFIG:ReleaseMFCDLL>:"
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
    "$<$<CONFIG:Debug>:"
        "_DEBUG"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "_DEBUG"
    ">"
    "$<$<CONFIG:Final>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:FinalES>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Release>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:ReleaseMFCDLL>:"
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
        $<$<CONFIG:Debug>:
            /Gm-;
            /Od;
            /MTd;
            /ZI
        >
        $<$<CONFIG:DebugMFCDLL>:
            /Gm-;
            /Od;
            /MTd;
            /ZI
        >
        $<$<CONFIG:Final>:
            /O2;
            /GF;
            /MT;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalDE>:
            /O2;
            /GF;
            /MT;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalES>:
            /O2;
            /GF;
            /MT;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalFR>:
            /O2;
            /GF;
            /MT;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalIT>:
            /O2;
            /GF;
            /MT;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalMFCDLL>:
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
        $<$<CONFIG:ReleaseMFCDLL>:
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
        $<$<CONFIG:Debug>:
            /DEBUG;
            /INCREMENTAL
        >
        $<$<CONFIG:DebugMFCDLL>:
            /DEBUG;
            /INCREMENTAL
        >
        $<$<CONFIG:Final>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalDE>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalES>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalFR>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalIT>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalMFCDLL>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Release>:
            /DEBUG:FULL;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:ReleaseMFCDLL>:
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

