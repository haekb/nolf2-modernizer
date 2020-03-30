project(Lib_StdLith CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "abstractio.h"
    "copy_lists.h"
    "dynarray.h"
    "fastlinklist.h"
    "fileio.h"
    "genhash.h"
    "genlist.h"
    "glink.h"
    "goodlinklist.h"
    "helpers.h"
    "l_allocator.h"
    "linklist.h"
    "lithexception.h"
    "memory.h"
    "memoryio.h"
    "morect.h"
    "multilinklist.h"
    "object_bank.h"
    "stdafx.h"
    "stdlith.h"
    "stdlithdefs.h"
    "stringholder.h"
    "struct_bank.h"
    "sys/win/compressedio.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "abstractio.cpp"
    "dynarray.cpp"
    "fileio.cpp"
    "goodlinklist.cpp"
    "helpers.cpp"
    "l_allocator.cpp"
    "linklist.cpp"
    "lithexception.cpp"
    "memory.cpp"
    "memoryio.cpp"
    "stringholder.cpp"
    "struct_bank.cpp"
    "sys/win/compressedio.cpp"
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
    TARGET_NAME_DEBUG MFC DLL   "Lib_StdLith"
    TARGET_NAME_DEBUG           "Lib_StdLith"
    TARGET_NAME_FINAL DE        "Lib_StdLith"
    TARGET_NAME_FINAL ES        "Lib_StdLith"
    TARGET_NAME_FINAL FR        "Lib_StdLith"
    TARGET_NAME_FINAL IT        "Lib_StdLith"
    TARGET_NAME_FINAL MFC DLL   "Lib_StdLith"
    TARGET_NAME_FINAL           "Lib_StdLith"
    TARGET_NAME_RELEASE MFC DLL "Lib_StdLith"
    TARGET_NAME_RELEASE         "Lib_StdLith"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/Lib_StdLith"
    OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/Lib_StdLith"
    OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_StdLith"
    OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_StdLith"
    OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_StdLith"
    OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_StdLith"
    OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_StdLith"
    OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_StdLith"
    OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/Lib_StdLith"
    OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/Lib_StdLith"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:Final DE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:Final ES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:Final FR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:Final IT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
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

