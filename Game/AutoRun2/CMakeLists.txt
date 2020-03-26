project(AutoRun2 CXX)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "ReadMe.txt"
)
source_group("" FILES ${no_group_source_files})

set(Header_Files
    "StdAfx.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "AutoRun2.cpp"
    "StdAfx.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${no_group_source_files}
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG           "AutoRun2"
        TARGET_NAME_FINAL           "AutoRun2"
        TARGET_NAME_RELEASE         "AutoRun2"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG MFC DLL   "AutoRun2"
        TARGET_NAME_DEBUG           "AutoRun2"
        TARGET_NAME_FINAL DE        "AutoRun2"
        TARGET_NAME_FINAL ES        "AutoRun2"
        TARGET_NAME_FINAL FR        "AutoRun2"
        TARGET_NAME_FINAL IT        "AutoRun2"
        TARGET_NAME_FINAL MFC DLL   "AutoRun2"
        TARGET_NAME_FINAL           "AutoRun2"
        TARGET_NAME_RELEASE MFC DLL "AutoRun2"
        TARGET_NAME_RELEASE         "AutoRun2"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/AutoRun2"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun2"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/AutoRun2"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/AutoRun2"
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/AutoRun2"
        OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun2"
        OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun2"
        OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun2"
        OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun2"
        OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun2"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun2"
        OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/AutoRun2"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/AutoRun2"
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
            "_WINDOWS"
        ">"
        "$<$<CONFIG:Final>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS"
        ">"
        "$<$<CONFIG:Release>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug MFC DLL>:"
            "WIN32;"
            "_DEBUG;"
            "_WINDOWS"
        ">"
        "$<$<CONFIG:Debug>:"
            "WIN32;"
            "_DEBUG;"
            "_WINDOWS"
        ">"
        "$<$<CONFIG:Final DE>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS"
        ">"
        "$<$<CONFIG:Final ES>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS"
        ">"
        "$<$<CONFIG:Final FR>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS"
        ">"
        "$<$<CONFIG:Final IT>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS"
        ">"
        "$<$<CONFIG:Final>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS"
        ">"
        "$<$<CONFIG:Release>:"
            "WIN32;"
            "NDEBUG;"
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
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Debug>:
                /Gm;
                /Od;
                /RTC1;
                /MTd;
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
                /MT;
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
                /MT;
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
                /MTd;
                /Gy;
                /W3;
                /ZI
            >
            $<$<CONFIG:Debug>:
                /Gm;
                /Od;
                /RTC1;
                /MTd;
                /Gy;
                /W3;
                /ZI
            >
            $<$<CONFIG:Final DE>:
                /O2;
                /GF;
                /MT;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final ES>:
                /O2;
                /GF;
                /MT;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final FR>:
                /O2;
                /GF;
                /MT;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final IT>:
                /O2;
                /GF;
                /MT;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final MFC DLL>:
                /O2;
                /GF;
                /MT;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final>:
                /O2;
                /GF;
                /MT;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Release MFC DLL>:
                /O2;
                /GF;
                /MT;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Release>:
                /O2;
                /GF;
                /MT;
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
                /NOLOGO;
                /DEBUG;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
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
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL:NO
            >
            $<$<CONFIG:Release MFC DLL>:
                /DEBUG:FULL
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
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "$<$<CONFIG:Final>:"
            "odbc32;"
            "odbccp32"
        ">"
        "$<$<CONFIG:Release>:"
            "odbc32;"
            "odbccp32"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
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
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

