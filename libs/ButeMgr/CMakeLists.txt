project(ButeMgr CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "arange.h"
    "avector.h"
    "butemgr.h"
    "stdafx.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "arange.cpp"
    "avector.cpp"
    "butemgr.cpp"
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
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

add_precompiled_header(${PROJECT_NAME} "stdafx.h" "stdafx.cpp")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "MFCProj"
)
################################################################################
# Target name
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG         "ButeMgr"
    TARGET_NAME_DEBUGMFCDLL   "ButeMgrMfcDll"
    TARGET_NAME_FINAL         "ButeMgr"
    TARGET_NAME_FINALDE       "ButeMgrMfcDll"
    TARGET_NAME_FINALES       "ButeMgrMfcDll"
    TARGET_NAME_FINALFR       "ButeMgrMfcDll"
    TARGET_NAME_FINALIT       "ButeMgrMfcDll"
    TARGET_NAME_FINALMFCDLL   "ButeMgrMfcDll"
    TARGET_NAME_RELEASE       "ButeMgr"
    TARGET_NAME_RELEASEMFCDLL "ButeMgrMfcDll"
    TARGET_NAME_TEMPLATE      "ButeMgrMfcDll"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/ButeMgr"
    OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/Debug/ButeMgrMFCDll"
    OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/ButeMgr"
    OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ButeMgrMFCDll"
    OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ButeMgrMFCDll"
    OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ButeMgrMFCDll"
    OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ButeMgrMFCDll"
    OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/ButeMgrMFCDll"
    OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/release/ButeMgr"
    OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/ButeMgrMFCDll"
    OUTPUT_DIRECTORY_TEMPLATE      "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/ButeMgrMFCDll"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
    ">"
    "$<$<CONFIG:FinalES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO"
    ">"
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
    ">"
    "$<$<CONFIG:Template>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
    ">"
    "${CMAKE_CURRENT_SOURCE_DIR}/../stdlith;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../MFCStub;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../CryptMgr;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
)

################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:"
        "_DEBUG;"
        "_NOMFC;"
        "_CRT_SECURE_NO_WARNINGS;"
        "NO_PRAGMA_LIBS;"
        "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "_DEBUG"
    ">"
    "$<$<CONFIG:Final>:"
        "NDEBUG;"
        "_NOMFC;"
        "_FINAL"
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
        "NDEBUG;"
        "_NOMFC;"
        "NO_PRAGMA_LIBS;"
        "_REZFILE;"
        "_FINAL;"
        "_NOLFBUILD;"
        "_CRT_SECURE_NO_WARNINGS"
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
            /Od;
            /MDd;
            /Gy;
            /ZI
        >
        $<$<CONFIG:DebugMFCDLL>:
            /Od;
            /MDd;
            /Gy-;
            /ZI
        >
        $<$<CONFIG:Final>:
            /O2;
            /GF;
            /MD;
            /Gy;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalDE>:
            /O2;
            /GF;
            /MD;
            /Gy;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalES>:
            /O2;
            /GF;
            /MD;
            /Gy;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalFR>:
            /O2;
            /GF;
            /MD;
            /Gy;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalIT>:
            /O2;
            /GF;
            /MD;
            /Gy;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalMFCDLL>:
            /O2;
            /GF;
            /MD;
            /Gy;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:Release>:
            /O2;
            /GF;
            /MD;
            /Gy;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:ReleaseMFCDLL>:
            /O2;
            /GF;
            /MD;
            /Gy;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:Template>:
            /O2;
            /GF;
            /MD;
            /Gy;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        /W3;
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        /NOLOGO
    )
endif()

