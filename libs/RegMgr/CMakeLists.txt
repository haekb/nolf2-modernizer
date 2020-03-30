project(RegMgr CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "regmgr.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "regmgr.cpp"
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

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
################################################################################
# Target name
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG MFC DLL   "regmgr"
    TARGET_NAME_DEBUG           "regmgr"
    TARGET_NAME_FINAL DE        "regmgr"
    TARGET_NAME_FINAL ES        "regmgr"
    TARGET_NAME_FINAL FR        "regmgr"
    TARGET_NAME_FINAL IT        "regmgr"
    TARGET_NAME_FINAL MFC DLL   "regmgr"
    TARGET_NAME_FINAL           "regmgr"
    TARGET_NAME_RELEASE MFC DLL "regmgr"
    TARGET_NAME_RELEASE         "regmgr"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/debug/RegMgr"
    OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/../built/debug/RegMgr"
    OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/RegMgr"
    OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/RegMgr"
    OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/RegMgr"
    OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/RegMgr"
    OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/RegMgr"
    OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/RegMgr"
    OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/RegMgr"
    OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/RegMgr"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:Final DE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:Final ES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:Final FR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:Final IT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
)

################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug MFC DLL>:"
        "_DEBUG;"
        "WIN32;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:Debug>:"
        "_DEBUG;"
        "WIN32;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:Final DE>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:Final ES>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:Final FR>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:Final IT>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_FINAL"
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
        "_WINDOWS"
    ">"
    "$<$<CONFIG:Release>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS"
    ">"
)

################################################################################
# Compile and link options
################################################################################
if(MSVC)
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

