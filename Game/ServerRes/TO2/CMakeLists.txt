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
    TARGET_NAME_DEBUG         "SRes"
    TARGET_NAME_DEBUGMFCDLL   "SRes"
    TARGET_NAME_FINAL         "SRes"
    TARGET_NAME_FINALDE       "SRes"
    TARGET_NAME_FINALES       "SRes"
    TARGET_NAME_FINALFR       "SRes"
    TARGET_NAME_FINALIT       "SRes"
    TARGET_NAME_FINALMFCDLL   "SRes"
    TARGET_NAME_RELEASE       "SRes"
    TARGET_NAME_RELEASEMFCDLL "SRes"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/ServerRes/TO2"
    OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/ServerRes/TO2"
    OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ServerRes/TO2"
    OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ServerRes/TO2"
    OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ServerRes/TO2"
    OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ServerRes/TO2"
    OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ServerRes/TO2"
    OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ServerRes/TO2"
    OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/ServerRes/TO2"
    OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/ServerRes/TO2"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ServerRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ServerRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ServerRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ServerRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ServerRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ServerRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ServerRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ServerRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Release/ServerRes/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Release/ServerRes/TO2"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_NAME_DEBUG         "SRes"
    ARCHIVE_OUTPUT_NAME_DEBUGMFCDLL   "SRes"
    ARCHIVE_OUTPUT_NAME_FINAL         "SRes"
    ARCHIVE_OUTPUT_NAME_FINALDE       "SRes"
    ARCHIVE_OUTPUT_NAME_FINALES       "SRes"
    ARCHIVE_OUTPUT_NAME_FINALFR       "SRes"
    ARCHIVE_OUTPUT_NAME_FINALIT       "SRes"
    ARCHIVE_OUTPUT_NAME_FINALMFCDLL   "SRes"
    ARCHIVE_OUTPUT_NAME_RELEASE       "SRes"
    ARCHIVE_OUTPUT_NAME_RELEASEMFCDLL "SRes"
)
################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:"
        "WIN32;"
        "_DEBUG;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
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
    "$<$<CONFIG:FinalDE>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:FinalES>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
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
    "$<$<CONFIG:ReleaseMFCDLL>:"
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
        $<$<CONFIG:Debug>:
            /Gm;
            /Od;
            /MTd;
            /Gy;
            /W3
        >
        $<$<CONFIG:DebugMFCDLL>:
            /Gm;
            /Od;
            /MTd;
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
        $<$<CONFIG:FinalDE>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalES>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalFR>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalIT>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalMFCDLL>:
            /O2;
            /GF;
            /MT;
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
        $<$<CONFIG:ReleaseMFCDLL>:
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
        $<$<CONFIG:Debug>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:DebugMFCDLL>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:Final>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalDE>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalES>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalFR>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalIT>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalMFCDLL>:
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
        $<$<CONFIG:ReleaseMFCDLL>:
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
    COMMAND         $<CONFIG:Debug> cd ..\\
    COMMAND         $<CONFIG:Debug> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
    COMMAND   $<CONFIG:DebugMFCDLL> cd ..\\
    COMMAND   $<CONFIG:DebugMFCDLL> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
)

################################################################################
# Dependencies
################################################################################
set(ADDITIONAL_LIBRARY_DEPENDENCIES
    "$<$<CONFIG:Debug>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:FinalES>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Release>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "odbc32;"
        "odbccp32"
    ">"
)
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

