project(CryptMgr CXX)

################################################################################
# Source groups
################################################################################
set(Source_Files
    "blowfish.cpp"
    "blowfish.h"
    "cryptmgr.cpp"
    "cryptmgr.h"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "MFCProj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG MFC DLL   "CryptMgrMfcDll"
        TARGET_NAME_DEBUG           "cryptmgr"
        TARGET_NAME_FINAL MFC DLL   "CryptMgrMfcDll"
        TARGET_NAME_FINAL           "cryptmgr"
        TARGET_NAME_RELEASE MFC DLL "CryptMgrMfcDll"
        TARGET_NAME_RELEASE         "cryptmgr"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG MFC DLL   "CryptMgrMfcDll"
        TARGET_NAME_DEBUG           "cryptmgr"
        TARGET_NAME_FINAL DE        "CryptMgrMfcDll"
        TARGET_NAME_FINAL ES        "CryptMgrMfcDll"
        TARGET_NAME_FINAL FR        "CryptMgrMfcDll"
        TARGET_NAME_FINAL IT        "CryptMgrMfcDll"
        TARGET_NAME_FINAL MFC DLL   "CryptMgrMfcDll"
        TARGET_NAME_FINAL           "cryptmgr"
        TARGET_NAME_RELEASE MFC DLL "CryptMgrMfcDll"
        TARGET_NAME_RELEASE         "cryptmgr"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/Debug/CryptMgrMfcDll"
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/CryptMgr"
        OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/CryptMgrMfcDll"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/CryptMgr"
        OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/CryptMgrMfcDll"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/CryptMgr"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/Debug/CryptMgrMfcDll"
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/CryptMgr"
        OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/CryptMgrMfcDll"
        OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/CryptMgrMfcDll"
        OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/CryptMgrMfcDll"
        OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/CryptMgrMfcDll"
        OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/CryptMgrMfcDll"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/CryptMgr"
        OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/CryptMgrMfcDll"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/CryptMgr"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug MFC DLL>:"
            "_DEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "NO_PRAGMA_LIBS"
        ">"
        "$<$<CONFIG:Debug>:"
            "_DEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "NO_PRAGMA_LIBS"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "NO_PRAGMA_LIBS"
        ">"
        "$<$<CONFIG:Final>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_FINAL"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "NO_PRAGMA_LIBS"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug MFC DLL>:"
            "_DEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "NO_PRAGMA_LIBS"
        ">"
        "$<$<CONFIG:Debug>:"
            "_DEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "NO_PRAGMA_LIBS"
        ">"
        "$<$<CONFIG:Final DE>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "NO_PRAGMA_LIBS"
        ">"
        "$<$<CONFIG:Final ES>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "NO_PRAGMA_LIBS"
        ">"
        "$<$<CONFIG:Final FR>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "NO_PRAGMA_LIBS"
        ">"
        "$<$<CONFIG:Final IT>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "NO_PRAGMA_LIBS"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "NO_PRAGMA_LIBS"
        ">"
        "$<$<CONFIG:Final>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_FINAL"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "NO_PRAGMA_LIBS"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS"
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
                /Od;
                /MDd;
                /Gy-;
                /W3
            >
            $<$<CONFIG:Debug>:
                /Od;
                /MDd;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final DE>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Final ES>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Final FR>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Final IT>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Final MFC DLL>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3
            >
            $<$<CONFIG:Release MFC DLL>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3
            >
            $<$<CONFIG:Release>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3
            >
            $<$<CONFIG:Template>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug MFC DLL>:
                /Od;
                /MDd;
                /Gy-;
                /W3
            >
            $<$<CONFIG:Debug>:
                /Od;
                /MDd;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final DE>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final ES>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final FR>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final IT>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final MFC DLL>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3
            >
            $<$<CONFIG:Release MFC DLL>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3
            >
            $<$<CONFIG:Release>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3
            >
            $<$<CONFIG:Template>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug MFC DLL>:
                /NOLOGO
            >
            $<$<CONFIG:Debug>:
                /NOLOGO
            >
            $<$<CONFIG:Final DE>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Final ES>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Final FR>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Final IT>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Final MFC DLL>:
                /NOLOGO
            >
            $<$<CONFIG:Final>:
                /NOLOGO
            >
            $<$<CONFIG:Release MFC DLL>:
                /NOLOGO
            >
            $<$<CONFIG:Release>:
                /NOLOGO
            >
            $<$<CONFIG:Template>:
                /DEBUG:FULL
            >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug MFC DLL>:
                /NOLOGO
            >
            $<$<CONFIG:Debug>:
                /NOLOGO
            >
            $<$<CONFIG:Final DE>:
                /NOLOGO
            >
            $<$<CONFIG:Final ES>:
                /NOLOGO
            >
            $<$<CONFIG:Final FR>:
                /NOLOGO
            >
            $<$<CONFIG:Final IT>:
                /NOLOGO
            >
            $<$<CONFIG:Final MFC DLL>:
                /NOLOGO
            >
            $<$<CONFIG:Final>:
                /NOLOGO
            >
            $<$<CONFIG:Release MFC DLL>:
                /NOLOGO
            >
            $<$<CONFIG:Release>:
                /NOLOGO
            >
            $<$<CONFIG:Template>:
                /DEBUG:FULL
            >
        )
    endif()
endif()

