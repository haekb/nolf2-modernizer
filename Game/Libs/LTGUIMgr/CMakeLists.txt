project(LTGUIMgr CXX)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "ltguilargetext.cpp"
    "ltguilargetext.h"
)
source_group("" FILES ${no_group_source_files})

set(Headers
    "ltguibutton.h"
    "ltguicolumnctrl.h"
    "ltguicommandhandler.h"
    "ltguictrl.h"
    "ltguicyclectrl.h"
    "ltguieditctrl.h"
    "ltguiframe.h"
    "ltguilistctrl.h"
    "ltguimgr.h"
    "ltguislider.h"
    "ltguitextitemctrl.h"
    "ltguitoggle.h"
    "ltguiwindow.h"
    "ltquaduvutils.h"
    "vkdefs.h"
)
source_group("Headers" FILES ${Headers})

set(Source
    "ltguibutton.cpp"
    "ltguicolumnctrl.cpp"
    "ltguicommandhandler.cpp"
    "ltguictrl.cpp"
    "ltguicyclectrl.cpp"
    "ltguieditctrl.cpp"
    "ltguiframe.cpp"
    "ltguilistctrl.cpp"
    "ltguislider.cpp"
    "ltguitextitemctrl.cpp"
    "ltguitoggle.cpp"
    "ltguiwindow.cpp"
)
source_group("Source" FILES ${Source})

set(ALL_FILES
    ${no_group_source_files}
    ${Headers}
    ${Source}
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
        TARGET_NAME_DEBUG           "ltguimgr"
        TARGET_NAME_FINAL           "ltguimgr"
        TARGET_NAME_RELEASE         "ltguimgr"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG MFC DLL   "ltguimgr"
        TARGET_NAME_DEBUG           "ltguimgr"
        TARGET_NAME_FINAL DE        "ltguimgr"
        TARGET_NAME_FINAL ES        "ltguimgr"
        TARGET_NAME_FINAL FR        "ltguimgr"
        TARGET_NAME_FINAL IT        "ltguimgr"
        TARGET_NAME_FINAL MFC DLL   "ltguimgr"
        TARGET_NAME_FINAL           "ltguimgr"
        TARGET_NAME_RELEASE MFC DLL "ltguimgr"
        TARGET_NAME_RELEASE         "ltguimgr"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Debug/libs/LTGuiMgr"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/libs/LTGuiMgr"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Release/libs/LTGuiMgr"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Debug/libs/LTGuiMgr"
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Debug/libs/LTGuiMgr"
        OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/libs/LTGuiMgr"
        OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/libs/LTGuiMgr"
        OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/libs/LTGuiMgr"
        OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/libs/LTGuiMgr"
        OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/libs/LTGuiMgr"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/libs/LTGuiMgr"
        OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Release/libs/LTGuiMgr"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Release/libs/LTGuiMgr"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_no;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD"
        ">"
        "$<$<CONFIG:Final>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat"
        ">"
        "$<$<CONFIG:Release>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_no;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_no;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD"
        ">"
        "$<$<CONFIG:Debug>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_no;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD"
        ">"
        "$<$<CONFIG:Final DE>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat"
        ">"
        "$<$<CONFIG:Final ES>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat"
        ">"
        "$<$<CONFIG:Final FR>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat"
        ">"
        "$<$<CONFIG:Final IT>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat"
        ">"
        "$<$<CONFIG:Final>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_no;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD"
        ">"
        "$<$<CONFIG:Release>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_no;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD"
        ">"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_LITHTECH2;"
            "LT15_COMPAT;"
            "_MBCS"
        ">"
        "$<$<CONFIG:Final>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_LITHTECH2;"
            "LT15_COMPAT;"
            "_FINAL;"
            "_MBCS"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_LITHTECH2;"
            "LT15_COMPAT;"
            "_MBCS"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug MFC DLL>:"
            "_DEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_LITHTECH2;"
            "LT15_COMPAT;"
            "_MBCS"
        ">"
        "$<$<CONFIG:Debug>:"
            "_DEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_LITHTECH2;"
            "LT15_COMPAT;"
            "_MBCS"
        ">"
        "$<$<CONFIG:Final DE>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_LITHTECH2;"
            "LT15_COMPAT;"
            "_FINAL;"
            "_MBCS"
        ">"
        "$<$<CONFIG:Final ES>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_LITHTECH2;"
            "LT15_COMPAT;"
            "_FINAL;"
            "_MBCS"
        ">"
        "$<$<CONFIG:Final FR>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_LITHTECH2;"
            "LT15_COMPAT;"
            "_FINAL;"
            "_MBCS"
        ">"
        "$<$<CONFIG:Final IT>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_LITHTECH2;"
            "LT15_COMPAT;"
            "_FINAL;"
            "_MBCS"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_LITHTECH2;"
            "LT15_COMPAT;"
            "_FINAL;"
            "_MBCS"
        ">"
        "$<$<CONFIG:Final>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_LITHTECH2;"
            "LT15_COMPAT;"
            "_FINAL;"
            "_MBCS"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_LITHTECH2;"
            "LT15_COMPAT;"
            "_MBCS"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG;"
            "WIN32;"
            "_WINDOWS;"
            "_LITHTECH2;"
            "LT15_COMPAT;"
            "_MBCS"
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
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Debug>:
                /Od;
                /MDd;
                /Gy;
                /W3;
                /ZI;
                /Zc:forScope-;
                /Y-
            >
            $<$<CONFIG:Final DE>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final ES>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final FR>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final IT>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final MFC DLL>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Final>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                /Zm1000
            >
            $<$<CONFIG:Release MFC DLL>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            $<$<CONFIG:Release>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                /Zm1000;
                /Zc:forScope-
            >
            $<$<CONFIG:Template>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug MFC DLL>:
                /Od;
                /MDd;
                /Gy;
                /W3;
                /ZI;
                /Zc:forScope-;
                /Y-
            >
            $<$<CONFIG:Debug>:
                /Od;
                /MDd;
                /Gy;
                /W3;
                /ZI;
                /Zc:forScope-;
                /Y-
            >
            $<$<CONFIG:Final DE>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                /Zm1000
            >
            $<$<CONFIG:Final ES>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                /Zm1000
            >
            $<$<CONFIG:Final FR>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                /Zm1000
            >
            $<$<CONFIG:Final IT>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                /Zm1000
            >
            $<$<CONFIG:Final MFC DLL>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                /Zm1000
            >
            $<$<CONFIG:Final>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                /Zm1000
            >
            $<$<CONFIG:Release MFC DLL>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                /Zm1000;
                /Zc:forScope-
            >
            $<$<CONFIG:Release>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                /Zm1000;
                /Zc:forScope-
            >
            $<$<CONFIG:Template>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
            >
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    endif()
    source_file_compile_options(ltguibutton.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    endif()
    source_file_compile_options(ltguicolumnctrl.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    endif()
    source_file_compile_options(ltguicommandhandler.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    endif()
    source_file_compile_options(ltguictrl.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    endif()
    source_file_compile_options(ltguicyclectrl.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    endif()
    source_file_compile_options(ltguieditctrl.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    endif()
    source_file_compile_options(ltguiframe.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    endif()
    source_file_compile_options(ltguilargetext.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    endif()
    source_file_compile_options(ltguilistctrl.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    endif()
    source_file_compile_options(ltguislider.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    endif()
    source_file_compile_options(ltguitextitemctrl.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    endif()
    source_file_compile_options(ltguitoggle.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    endif()
    source_file_compile_options(ltguiwindow.cpp ${FILE_CL_OPTIONS})
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

