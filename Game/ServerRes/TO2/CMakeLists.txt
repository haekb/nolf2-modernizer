project(ServerRes CXX)

################################################################################
# Source groups
################################################################################
set(Sources
    "MAIN.CPP"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${Sources}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG           "SRes"
        TARGET_NAME_FINAL           "SRes"
        TARGET_NAME_RELEASE         "SRes"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG MFC DLL   "SRes"
        TARGET_NAME_DEBUG           "SRes"
        TARGET_NAME_FINAL DE        "SRes"
        TARGET_NAME_FINAL ES        "SRes"
        TARGET_NAME_FINAL FR        "SRes"
        TARGET_NAME_FINAL IT        "SRes"
        TARGET_NAME_FINAL MFC DLL   "SRes"
        TARGET_NAME_FINAL           "SRes"
        TARGET_NAME_RELEASE MFC DLL "SRes"
        TARGET_NAME_RELEASE         "SRes"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/ServerRes/TO2"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ServerRes/TO2"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/ServerRes/TO2"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/ServerRes/TO2"
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/ServerRes/TO2"
        OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ServerRes/TO2"
        OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ServerRes/TO2"
        OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ServerRes/TO2"
        OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ServerRes/TO2"
        OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ServerRes/TO2"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ServerRes/TO2"
        OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/ServerRes/TO2"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/ServerRes/TO2"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ServerRes/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ServerRes/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Release/ServerRes/TO2"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ServerRes/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ServerRes/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ServerRes/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ServerRes/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ServerRes/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ServerRes/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ServerRes/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ServerRes/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Release/ServerRes/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Release/ServerRes/TO2"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG           "SRes"
        ARCHIVE_OUTPUT_NAME_FINAL           "SRes"
        ARCHIVE_OUTPUT_NAME_RELEASE         "SRes"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG MFC DLL   "SRes"
        ARCHIVE_OUTPUT_NAME_DEBUG           "SRes"
        ARCHIVE_OUTPUT_NAME_FINAL DE        "SRes"
        ARCHIVE_OUTPUT_NAME_FINAL ES        "SRes"
        ARCHIVE_OUTPUT_NAME_FINAL FR        "SRes"
        ARCHIVE_OUTPUT_NAME_FINAL IT        "SRes"
        ARCHIVE_OUTPUT_NAME_FINAL MFC DLL   "SRes"
        ARCHIVE_OUTPUT_NAME_FINAL           "SRes"
        ARCHIVE_OUTPUT_NAME_RELEASE MFC DLL "SRes"
        ARCHIVE_OUTPUT_NAME_RELEASE         "SRes"
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
            "_WINDOWS;"
            "_FINAL"
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
            "_WINDOWS;"
            "_FINAL"
        ">"
        "$<$<CONFIG:Final ES>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS;"
            "_FINAL"
        ">"
        "$<$<CONFIG:Final FR>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS;"
            "_FINAL"
        ">"
        "$<$<CONFIG:Final IT>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS;"
            "_FINAL"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS;"
            "_FINAL"
        ">"
        "$<$<CONFIG:Final>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS;"
            "_FINAL"
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
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Debug>:
                /Gm;
                /Od;
                /MTd;
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
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Final>:
                /O2;
                /GF;
                /MT;
                /Gy;
                /W3
            >
            $<$<CONFIG:Release MFC DLL>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
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
                /Gm;
                /Od;
                /MTd;
                /Gy;
                /W3
            >
            $<$<CONFIG:Debug>:
                /Gm;
                /Od;
                /MTd;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final DE>:
                /O2;
                /GF;
                /MT;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final ES>:
                /O2;
                /GF;
                /MT;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final FR>:
                /O2;
                /GF;
                /MT;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final IT>:
                /O2;
                /GF;
                /MT;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final MFC DLL>:
                /O2;
                /GF;
                /MT;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final>:
                /O2;
                /GF;
                /MT;
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
# Post build events
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    add_custom_command_if(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMANDS
        COMMAND           $<CONFIG:Debug> cd ..\\
        COMMAND           $<CONFIG:Debug> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    add_custom_command_if(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMANDS
        COMMAND   $<CONFIG:Debug MFC DLL> cd ..\\
        COMMAND   $<CONFIG:Debug MFC DLL> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
        COMMAND           $<CONFIG:Debug> cd ..\\
        COMMAND           $<CONFIG:Debug> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
    )
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "$<$<CONFIG:Debug>:"
            "odbc32;"
            "odbccp32"
        ">"
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
        "$<$<CONFIG:Debug MFC DLL>:"
            "odbc32;"
            "odbccp32"
        ">"
        "$<$<CONFIG:Debug>:"
            "odbc32;"
            "odbccp32"
        ">"
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

