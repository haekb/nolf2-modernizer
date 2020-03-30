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
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG         "AutoRun2"
    TARGET_NAME_DEBUGMFCDLL   "AutoRun2"
    TARGET_NAME_FINAL         "AutoRun2"
    TARGET_NAME_FINALDE       "AutoRun2"
    TARGET_NAME_FINALES       "AutoRun2"
    TARGET_NAME_FINALFR       "AutoRun2"
    TARGET_NAME_FINALIT       "AutoRun2"
    TARGET_NAME_FINALMFCDLL   "AutoRun2"
    TARGET_NAME_RELEASE       "AutoRun2"
    TARGET_NAME_RELEASEMFCDLL "AutoRun2"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/AutoRun2"
    OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/AutoRun2"
    OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun2"
    OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun2"
    OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun2"
    OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun2"
    OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun2"
    OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/AutoRun2"
    OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/AutoRun2"
    OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/AutoRun2"
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
        "_WINDOWS"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:FinalES>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS"
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
            /RTC1;
            /MTd;
            /Gy;
            /W3;
            /ZI
        >
        $<$<CONFIG:DebugMFCDLL>:
            /Gm;
            /Od;
            /RTC1;
            /MTd;
            /Gy;
            /W3;
            /ZI
        >
        $<$<CONFIG:Final>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalDE>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalES>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalFR>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalIT>:
            /O2;
            /GF;
            /MT;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalMFCDLL>:
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
        $<$<CONFIG:ReleaseMFCDLL>:
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
# Dependencies
################################################################################
set(ADDITIONAL_LIBRARY_DEPENDENCIES
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

