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
    TARGET_NAME_DEBUG         "Lib_StdLith"
    TARGET_NAME_DEBUGMFCDLL   "Lib_StdLith"
    TARGET_NAME_FINAL         "Lib_StdLith"
    TARGET_NAME_FINALDE       "Lib_StdLith"
    TARGET_NAME_FINALES       "Lib_StdLith"
    TARGET_NAME_FINALFR       "Lib_StdLith"
    TARGET_NAME_FINALIT       "Lib_StdLith"
    TARGET_NAME_FINALMFCDLL   "Lib_StdLith"
    TARGET_NAME_RELEASE       "Lib_StdLith"
    TARGET_NAME_RELEASEMFCDLL "Lib_StdLith"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/Lib_StdLith"
    OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/Lib_StdLith"
    OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_StdLith"
    OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_StdLith"
    OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_StdLith"
    OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_StdLith"
    OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_StdLith"
    OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_StdLith"
    OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/Lib_StdLith"
    OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/Lib_StdLith"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:FinalES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
    ">"
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../zlib"
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

