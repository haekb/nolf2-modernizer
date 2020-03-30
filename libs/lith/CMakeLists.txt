project(Lib_Lith CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "basehash.h"
    "baselist.h"
    "baselistcounter.h"
    "dprintf.h"
    "lith.h"
    "lithbaselist.h"
    "lithchunkallocator.h"
    "lithsimpary.h"
    "lithsimparystat.h"
    "lithtmpl.h"
    "lithtypes.h"
    "virtlist.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "basehash.cpp"
    "baselist.cpp"
    "baselistcounter.cpp"
    "dprintf.cpp"
    "lith.cpp"
    "lithbaselist.cpp"
    "lithchunkallocator.cpp"
    "lithsimpary.cpp"
    "lithsimparystat.cpp"
    "virtlist.cpp"
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
    TARGET_NAME_DEBUG MFC DLL   "Lib_Lith"
    TARGET_NAME_DEBUG           "Lib_Lith"
    TARGET_NAME_FINAL DE        "Lib_Lith"
    TARGET_NAME_FINAL ES        "Lib_Lith"
    TARGET_NAME_FINAL FR        "Lib_Lith"
    TARGET_NAME_FINAL IT        "Lib_Lith"
    TARGET_NAME_FINAL MFC DLL   "Lib_Lith"
    TARGET_NAME_FINAL           "Lib_Lith"
    TARGET_NAME_RELEASE MFC DLL "Lib_Lith"
    TARGET_NAME_RELEASE         "Lib_Lith"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/Lib_Lith"
    OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/Lib_Lith"
    OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_Lith"
    OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_Lith"
    OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_Lith"
    OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_Lith"
    OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_Lith"
    OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_Lith"
    OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/Lib_Lith"
    OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/Lib_Lith"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT_NO"
    ">"
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT_NO"
    ">"
    "$<$<CONFIG:Final DE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT"
    ">"
    "$<$<CONFIG:Final ES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT"
    ">"
    "$<$<CONFIG:Final FR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT"
    ">"
    "$<$<CONFIG:Final IT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT_NO"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT_NO"
    ">"
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
            /Od;
            /RTC1;
            /MDd;
            /Gy;
            /W3
        >
        $<$<CONFIG:Debug>:
            /Od;
            /RTC1;
            /MDd;
            /Gy;
            /W3
        >
        $<$<CONFIG:Final DE>:
            /O2;
            /Ob2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:Final ES>:
            /O2;
            /Ob2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:Final FR>:
            /O2;
            /Ob2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:Final IT>:
            /O2;
            /Ob2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:Final MFC DLL>:
            /O2;
            /Ob2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:Final>:
            /O2;
            /Ob2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:Release MFC DLL>:
            /O2;
            /Ob2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:Release>:
            /O2;
            /Ob2;
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

