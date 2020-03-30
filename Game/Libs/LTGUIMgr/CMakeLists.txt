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
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG         "ltguimgr"
    TARGET_NAME_DEBUGMFCDLL   "ltguimgr"
    TARGET_NAME_FINAL         "ltguimgr"
    TARGET_NAME_FINALDE       "ltguimgr"
    TARGET_NAME_FINALES       "ltguimgr"
    TARGET_NAME_FINALFR       "ltguimgr"
    TARGET_NAME_FINALIT       "ltguimgr"
    TARGET_NAME_FINALMFCDLL   "ltguimgr"
    TARGET_NAME_RELEASE       "ltguimgr"
    TARGET_NAME_RELEASEMFCDLL "ltguimgr"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Debug/libs/LTGuiMgr"
    OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Debug/libs/LTGuiMgr"
    OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/libs/LTGuiMgr"
    OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/libs/LTGuiMgr"
    OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/libs/LTGuiMgr"
    OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/libs/LTGuiMgr"
    OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/libs/LTGuiMgr"
    OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Final/libs/LTGuiMgr"
    OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Release/libs/LTGuiMgr"
    OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/../../built/Release/libs/LTGuiMgr"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_no;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
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
    "$<$<CONFIG:FinalDE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat"
    ">"
    "$<$<CONFIG:FinalES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
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
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_no;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc/compat;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD"
    ">"
)

################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:"
        "_DEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_LITHTECH2;"
        "LT15_COMPAT;"
        "_MBCS"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
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
    "$<$<CONFIG:FinalDE>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_LITHTECH2;"
        "LT15_COMPAT;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:FinalES>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_LITHTECH2;"
        "LT15_COMPAT;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_LITHTECH2;"
        "LT15_COMPAT;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_LITHTECH2;"
        "LT15_COMPAT;"
        "_FINAL;"
        "_MBCS"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
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
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "NDEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "_LITHTECH2;"
        "LT15_COMPAT;"
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
            /ZI;
            /Zc:forScope-;
            /Y-
        >
        $<$<CONFIG:DebugMFCDLL>:
            /Od;
            /MDd;
            /Gy;
            /W3;
            /ZI;
            /Zc:forScope-;
            /Y-
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
        $<$<CONFIG:FinalDE>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /Zm1000
        >
        $<$<CONFIG:FinalES>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /Zm1000
        >
        $<$<CONFIG:FinalFR>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /Zm1000
        >
        $<$<CONFIG:FinalIT>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /Zm1000
        >
        $<$<CONFIG:FinalMFCDLL>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /Zm1000
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
        $<$<CONFIG:ReleaseMFCDLL>:
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
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalDE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalFR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalIT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:ReleaseMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ltguibutton.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalDE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalFR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalIT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:ReleaseMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ltguicolumnctrl.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalDE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalFR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalIT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:ReleaseMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ltguicommandhandler.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalDE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalFR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalIT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:ReleaseMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ltguictrl.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalDE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalFR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalIT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:ReleaseMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ltguicyclectrl.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalDE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalFR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalIT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:ReleaseMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ltguieditctrl.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalDE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalFR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalIT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:ReleaseMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ltguiframe.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalDE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalFR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalIT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:ReleaseMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ltguilargetext.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalDE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalFR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalIT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:ReleaseMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ltguilistctrl.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalDE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalFR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalIT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:ReleaseMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ltguislider.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalDE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalFR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalIT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:ReleaseMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ltguitextitemctrl.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalDE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalFR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalIT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:ReleaseMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ltguitoggle.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Final>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalDE>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalES>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalFR>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalIT>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:FinalMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Release>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:ReleaseMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
    )
    source_file_compile_options(ltguiwindow.cpp ${FILE_CL_OPTIONS})
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

