project(regmgr32 CXX)

################################################################################
# Source groups
################################################################################
set(Source_Files
    "regmgr32.cpp"
    "regmgr32.h"
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
        TARGET_NAME_DEBUG           "regmgr32"
        TARGET_NAME_FINAL           "regmgr32"
        TARGET_NAME_RELEASE         "regmgr32"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG MFC DLL   "regmgr32"
        TARGET_NAME_DEBUG           "regmgr32"
        TARGET_NAME_FINAL DE        "regmgr32"
        TARGET_NAME_FINAL ES        "regmgr32"
        TARGET_NAME_FINAL FR        "regmgr32"
        TARGET_NAME_FINAL IT        "regmgr32"
        TARGET_NAME_FINAL MFC DLL   "regmgr32"
        TARGET_NAME_FINAL           "regmgr32"
        TARGET_NAME_RELEASE MFC DLL "regmgr32"
        TARGET_NAME_RELEASE         "regmgr32"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/RegMgr32"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/RegMgr32"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/RegMgr32"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/RegMgr32"
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/RegMgr32"
        OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/RegMgr32"
        OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/RegMgr32"
        OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/RegMgr32"
        OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/RegMgr32"
        OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/RegMgr32"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/RegMgr32"
        OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/RegMgr32"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/RegMgr32"
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
                /Od;
                /MDd;
                /Gy;
                /W3;
                /ZI
            >
            $<$<CONFIG:Final DE>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final ES>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final FR>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final IT>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
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
                /Od;
                /MDd;
                /Gy;
                /W3;
                /ZI
            >
            $<$<CONFIG:Debug>:
                /Od;
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
                /DEBUG:FULL
            >
            $<$<CONFIG:Final>:
                /NOLOGO
            >
            $<$<CONFIG:Release MFC DLL>:
                /DEBUG:FULL
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

