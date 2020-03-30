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
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG         "regmgr32"
    TARGET_NAME_DEBUGMFCDLL   "regmgr32"
    TARGET_NAME_FINAL         "regmgr32"
    TARGET_NAME_FINALDE       "regmgr32"
    TARGET_NAME_FINALES       "regmgr32"
    TARGET_NAME_FINALFR       "regmgr32"
    TARGET_NAME_FINALIT       "regmgr32"
    TARGET_NAME_FINALMFCDLL   "regmgr32"
    TARGET_NAME_RELEASE       "regmgr32"
    TARGET_NAME_RELEASEMFCDLL "regmgr32"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/RegMgr32"
    OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/RegMgr32"
    OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/RegMgr32"
    OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/RegMgr32"
    OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/RegMgr32"
    OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/RegMgr32"
    OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/RegMgr32"
    OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/RegMgr32"
    OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/RegMgr32"
    OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/RegMgr32"
)
################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:"
        "WIN32;"
        "_DEBUG;"
        "_WINDOWS;"
        "_MBCS"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
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
    "$<$<CONFIG:FinalDE>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:FinalES>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
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
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "WIN32;"
        "NDEBUG;"
        "_WINDOWS;"
        "_MBCS"
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

