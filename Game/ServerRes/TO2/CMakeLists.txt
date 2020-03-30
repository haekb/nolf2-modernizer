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
################################################################################
# Output directory
################################################################################
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
################################################################################
# Compile definitions
################################################################################
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

################################################################################
# Compile and link options
################################################################################
if(MSVC)
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

################################################################################
# Post build events
################################################################################
add_custom_command_if(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMANDS
    COMMAND   $<CONFIG:Debug MFC DLL> cd ..\\
    COMMAND   $<CONFIG:Debug MFC DLL> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
    COMMAND           $<CONFIG:Debug> cd ..\\
    COMMAND           $<CONFIG:Debug> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
)

################################################################################
# Dependencies
################################################################################
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
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

