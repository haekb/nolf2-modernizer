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
    TARGET_NAME_DEBUG         "Lib_Lith"
    TARGET_NAME_DEBUGMFCDLL   "Lib_Lith"
    TARGET_NAME_FINAL         "Lib_Lith"
    TARGET_NAME_FINALDE       "Lib_Lith"
    TARGET_NAME_FINALES       "Lib_Lith"
    TARGET_NAME_FINALFR       "Lib_Lith"
    TARGET_NAME_FINALIT       "Lib_Lith"
    TARGET_NAME_FINALMFCDLL   "Lib_Lith"
    TARGET_NAME_RELEASE       "Lib_Lith"
    TARGET_NAME_RELEASEMFCDLL "Lib_Lith"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/Lib_Lith"
    OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/Lib_Lith"
    OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_Lith"
    OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_Lith"
    OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_Lith"
    OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_Lith"
    OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_Lith"
    OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_Lith"
    OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/Lib_Lith"
    OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/Lib_Lith"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT_NO"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT_NO"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT"
    ">"
    "$<$<CONFIG:FinalES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT_NO"
    ">"
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT_NO"
    ">"
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
            /Od;
            /RTC1;
            /MDd;
            /Gy;
            /W3
        >
        $<$<CONFIG:DebugMFCDLL>:
            /Od;
            /RTC1;
            /MDd;
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
        $<$<CONFIG:FinalDE>:
            /O2;
            /Ob2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalES>:
            /O2;
            /Ob2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalFR>:
            /O2;
            /Ob2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalIT>:
            /O2;
            /Ob2;
            /GF;
            /MD;
            /Gy;
            /W3
        >
        $<$<CONFIG:FinalMFCDLL>:
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
        $<$<CONFIG:ReleaseMFCDLL>:
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

