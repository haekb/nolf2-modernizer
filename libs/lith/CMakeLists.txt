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
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG           "Lib_Lith"
        TARGET_NAME_FINAL           "Lib_Lith"
        TARGET_NAME_RELEASE         "Lib_Lith"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Debug/Lib_Lith"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Final/Lib_Lith"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../built/Release/Lib_Lith"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT_NO"
        ">"
        "$<$<CONFIG:Final>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT"
        ">"
        "$<$<CONFIG:Release>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs/STLPORT-4.0/STLPORT_NO"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
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
        "$<$<CONFIG:Release>:"
            "WIN32;"
            "NDEBUG;"
            "_WINDOWS"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug MFC DLL>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Debug>:
                /Od;
                /RTC1;
                /MDd;
                /Gy;
                /W3
            >
            $<$<CONFIG:Final DE>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Final ES>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Final FR>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Final IT>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Final MFC DLL>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
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
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
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
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug MFC DLL>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Debug>:
                /NOLOGO
            >
            $<$<CONFIG:Final DE>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Final ES>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Final FR>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Final IT>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Final MFC DLL>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Final>:
                /NOLOGO
            >
            $<$<CONFIG:Release MFC DLL>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Release>:
                /NOLOGO
            >
            $<$<CONFIG:Template>:
                /DEBUG:FULL
            >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
endif()

