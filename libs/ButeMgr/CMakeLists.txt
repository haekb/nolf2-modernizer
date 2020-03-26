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
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG MFC DLL   "ButeMgrMfcDll"
        TARGET_NAME_DEBUG           "ButeMgr"
        TARGET_NAME_FINAL DE        "ButeMgr"
        TARGET_NAME_FINAL ES        "ButeMgr"
        TARGET_NAME_FINAL FR        "ButeMgr"
        TARGET_NAME_FINAL IT        "ButeMgr"
        TARGET_NAME_FINAL MFC DLL   "ButeMgrMfcDll"
        TARGET_NAME_FINAL           "ButeMgr"
        TARGET_NAME_RELEASE MFC DLL "ButeMgrMfcDll"
        TARGET_NAME_RELEASE         "ButeMgr"
        TARGET_NAME_TEMPLATE        "ButeMgr"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG MFC DLL   "ButeMgrMfcDll"
        TARGET_NAME_DEBUG           "ButeMgr"
        TARGET_NAME_FINAL DE        "ButeMgrMfcDll"
        TARGET_NAME_FINAL ES        "ButeMgrMfcDll"
        TARGET_NAME_FINAL FR        "ButeMgrMfcDll"
        TARGET_NAME_FINAL IT        "ButeMgrMfcDll"
        TARGET_NAME_FINAL MFC DLL   "ButeMgrMfcDll"
        TARGET_NAME_FINAL           "ButeMgr"
        TARGET_NAME_RELEASE MFC DLL "ButeMgrMfcDll"
        TARGET_NAME_RELEASE         "ButeMgr"
        TARGET_NAME_TEMPLATE        "ButeMgrMfcDll"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/Debug/ButeMgrMFCDll"
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/ButeMgr"
        OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/release/ButeMgr"
        OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/release/ButeMgr"
        OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/release/ButeMgr"
        OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/release/ButeMgr"
        OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ButeMgrMFCDll"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/ButeMgr"
        OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/ButeMgrMFCDll"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/release/ButeMgr"
        OUTPUT_DIRECTORY_TEMPLATE        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/release/ButeMgr"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/Debug/ButeMgrMFCDll"
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/ButeMgr"
        OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ButeMgrMFCDll"
        OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ButeMgrMFCDll"
        OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ButeMgrMFCDll"
        OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ButeMgrMFCDll"
        OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/ButeMgrMFCDll"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/ButeMgr"
        OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/ButeMgrMFCDll"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/release/ButeMgr"
        OUTPUT_DIRECTORY_TEMPLATE        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/ButeMgrMFCDll"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
        ">"
        "$<$<CONFIG:Debug>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO"
        ">"
        "$<$<CONFIG:Final DE>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO"
        ">"
        "$<$<CONFIG:Final ES>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO"
        ">"
        "$<$<CONFIG:Final FR>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO"
        ">"
        "$<$<CONFIG:Final IT>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
        ">"
        "$<$<CONFIG:Final>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
        ">"
        "$<$<CONFIG:Release>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO"
        ">"
        "$<$<CONFIG:Template>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO"
        ">"
        "${CMAKE_CURRENT_SOURCE_DIR}/../stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
        ">"
        "$<$<CONFIG:Debug>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO"
        ">"
        "$<$<CONFIG:Final DE>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
        ">"
        "$<$<CONFIG:Final ES>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
        ">"
        "$<$<CONFIG:Final FR>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
        ">"
        "$<$<CONFIG:Final IT>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
        ">"
        "$<$<CONFIG:Final>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
        ">"
        "$<$<CONFIG:Release>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO"
        ">"
        "$<$<CONFIG:Template>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport"
        ">"
        "${CMAKE_CURRENT_SOURCE_DIR}/../stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug MFC DLL>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Debug>:"
            "_DEBUG;"
            "_NOMFC;"
            "_CRT_SECURE_NO_WARNINGS;"
            "NO_PRAGMA_LIBS;"
            "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS"
        ">"
        "$<$<CONFIG:Final DE>:"
            "NDEBUG;"
            "_NOMFC;"
            "NO_PRAGMA_LIBS;"
            "_REZFILE;"
            "_FINAL;"
            "_NOLFBUILD;"
            "_CRT_SECURE_NO_WARNINGS"
        ">"
        "$<$<CONFIG:Final ES>:"
            "NDEBUG;"
            "_NOMFC;"
            "NO_PRAGMA_LIBS;"
            "_REZFILE;"
            "_FINAL;"
            "_NOLFBUILD;"
            "_CRT_SECURE_NO_WARNINGS"
        ">"
        "$<$<CONFIG:Final FR>:"
            "NDEBUG;"
            "_NOMFC;"
            "NO_PRAGMA_LIBS;"
            "_REZFILE;"
            "_FINAL;"
            "_NOLFBUILD;"
            "_CRT_SECURE_NO_WARNINGS"
        ">"
        "$<$<CONFIG:Final IT>:"
            "NDEBUG;"
            "_NOMFC;"
            "NO_PRAGMA_LIBS;"
            "_REZFILE;"
            "_FINAL;"
            "_NOLFBUILD;"
            "_CRT_SECURE_NO_WARNINGS"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "NDEBUG"
        ">"
        "$<$<CONFIG:Final>:"
            "NDEBUG;"
            "_NOMFC;"
            "_FINAL"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
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
        "$<$<CONFIG:Template>:"
            "NDEBUG;"
            "_NOMFC;"
            "NO_PRAGMA_LIBS;"
            "_REZFILE;"
            "_FINAL;"
            "_NOLFBUILD;"
            "_CRT_SECURE_NO_WARNINGS"
        ">"
        "WIN32;"
        "_WINDOWS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug MFC DLL>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Debug>:"
            "_DEBUG;"
            "_NOMFC;"
            "_CRT_SECURE_NO_WARNINGS;"
            "NO_PRAGMA_LIBS;"
            "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS"
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
            "NDEBUG;"
            "_NOMFC;"
            "_FINAL"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
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
        "$<$<CONFIG:Template>:"
            "NDEBUG"
        ">"
        "WIN32;"
        "_WINDOWS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug MFC DLL>:
                /Od;
                /MDd;
                /Gy-;
                /ZI
            >
            $<$<CONFIG:Debug>:
                /Od;
                /MDd;
                /Gy;
                /ZI
            >
            $<$<CONFIG:Final DE>:
                /O2;
                /GF;
                /MD;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final ES>:
                /O2;
                /GF;
                /MD;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final FR>:
                /O2;
                /GF;
                /MD;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final IT>:
                /O2;
                /GF;
                /MD;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final MFC DLL>:
                /O2;
                /GF;
                /MD;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final>:
                /O2;
                /GF;
                /MD;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Release MFC DLL>:
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
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug MFC DLL>:
                /Od;
                /MDd;
                /Gy-;
                /ZI
            >
            $<$<CONFIG:Debug>:
                /Od;
                /MDd;
                /Gy;
                /ZI
            >
            $<$<CONFIG:Final DE>:
                /O2;
                /GF;
                /MD;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final ES>:
                /O2;
                /GF;
                /MD;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final FR>:
                /O2;
                /GF;
                /MD;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final IT>:
                /O2;
                /GF;
                /MD;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final MFC DLL>:
                /O2;
                /GF;
                /MD;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final>:
                /O2;
                /GF;
                /MD;
                /Gy;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Release MFC DLL>:
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
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            /NOLOGO
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            /NOLOGO
        )
    endif()
endif()

