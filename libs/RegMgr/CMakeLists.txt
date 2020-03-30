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
    TARGET_NAME_DEBUG         "regmgr"
    TARGET_NAME_DEBUGMFCDLL   "regmgr"
    TARGET_NAME_FINAL         "regmgr"
    TARGET_NAME_FINALDE       "regmgr"
    TARGET_NAME_FINALES       "regmgr"
    TARGET_NAME_FINALFR       "regmgr"
    TARGET_NAME_FINALIT       "regmgr"
    TARGET_NAME_FINALMFCDLL   "regmgr"
    TARGET_NAME_RELEASE       "regmgr"
    TARGET_NAME_RELEASEMFCDLL "regmgr"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/../built/debug/RegMgr"
    OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/debug/RegMgr"
    OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/RegMgr"
    OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/RegMgr"
    OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/RegMgr"
    OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/RegMgr"
    OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/RegMgr"
    OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/RegMgr"
    OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/RegMgr"
    OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/RegMgr"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:FinalES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lith"
    ">"
)

################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:"
        "_DEBUG;"
        "WIN32;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "_DEBUG;"
        "WIN32;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:Final>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:FinalES>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_FINAL"
    ">"
    "$<$<CONFIG:Release>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:ReleaseMFCDLL>:"
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
        $<$<CONFIG:Debug>:
            /Od;
            /MDd;
            /Gy;
            /W3;
            /ZI
        >
        $<$<CONFIG:DebugMFCDLL>:
            /Od;
            /MDd;
            /Gy;
            /W3;
            /ZI
        >
        $<$<CONFIG:Final>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalDE>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalES>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalFR>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalIT>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        $<$<CONFIG:FinalMFCDLL>:
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
        $<$<CONFIG:ReleaseMFCDLL>:
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
        $<$<CONFIG:Debug>:
            /NOLOGO
        >
        $<$<CONFIG:DebugMFCDLL>:
            /NOLOGO
        >
        $<$<CONFIG:Final>:
            /NOLOGO
        >
        $<$<CONFIG:FinalDE>:
            /NOLOGO
        >
        $<$<CONFIG:FinalES>:
            /NOLOGO
        >
        $<$<CONFIG:FinalFR>:
            /NOLOGO
        >
        $<$<CONFIG:FinalIT>:
            /NOLOGO
        >
        $<$<CONFIG:FinalMFCDLL>:
            /NOLOGO
        >
        $<$<CONFIG:Release>:
            /NOLOGO
        >
        $<$<CONFIG:ReleaseMFCDLL>:
            /NOLOGO
        >
        $<$<CONFIG:Template>:
            /DEBUG:FULL
        >
    )
endif()

