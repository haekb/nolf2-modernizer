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
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG         "cryptmgr"
    TARGET_NAME_DEBUGMFCDLL   "CryptMgrMfcDll"
    TARGET_NAME_FINAL         "cryptmgr"
    TARGET_NAME_FINALDE       "CryptMgrMfcDll"
    TARGET_NAME_FINALES       "CryptMgrMfcDll"
    TARGET_NAME_FINALFR       "CryptMgrMfcDll"
    TARGET_NAME_FINALIT       "CryptMgrMfcDll"
    TARGET_NAME_FINALMFCDLL   "cryptmgr"
    TARGET_NAME_RELEASE       "cryptmgr"
    TARGET_NAME_RELEASEMFCDLL "CryptMgrMfcDll"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/CryptMgr"
    OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/../built/Debug/CryptMgrMfcDll"
    OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/CryptMgr"
    OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/CryptMgrMfcDll"
    OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/CryptMgrMfcDll"
    OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/CryptMgrMfcDll"
    OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/../built/Final/CryptMgrMfcDll"
    OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/CryptMgr"
    OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/CryptMgr"
    OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/../built/Release/CryptMgrMfcDll"
)
################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:"
        "_DEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NO_PRAGMA_LIBS"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "_DEBUG;"
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
    "$<$<CONFIG:FinalDE>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NO_PRAGMA_LIBS"
    ">"
    "$<$<CONFIG:FinalES>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NO_PRAGMA_LIBS"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NO_PRAGMA_LIBS"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NO_PRAGMA_LIBS"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:Release>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS"
    ">"
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NO_PRAGMA_LIBS"
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
            /W3
        >
        $<$<CONFIG:DebugMFCDLL>:
            /Od;
            /MDd;
            /Gy-;
            /W3
        >
        $<$<CONFIG:Final>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalDE>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalES>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalFR>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalIT>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalMFCDLL>:
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

