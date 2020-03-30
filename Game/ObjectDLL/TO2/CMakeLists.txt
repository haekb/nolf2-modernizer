project(Object CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "../../Shared/TO2/TO2MissionButeMgr.h"
    "../../Shared/TO2/TO2VersionMgr.h"
    "Stdafx.h"
    "TO2GameServerShell.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "../../Shared/TO2/TO2MissionButeMgr.cpp"
    "../../Shared/TO2/TO2VersionMgr.cpp"
    "GlobalsInit.cpp"
    "Stdafx.cpp"
    "TO2GameServerShell.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})

add_precompiled_header(${PROJECT_NAME} "Stdafx.h" "Stdafx.cpp")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
################################################################################
# Target name
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG MFC DLL   "Object"
    TARGET_NAME_DEBUG           "Object"
    TARGET_NAME_FINAL DE        "Object"
    TARGET_NAME_FINAL ES        "Object"
    TARGET_NAME_FINAL FR        "Object"
    TARGET_NAME_FINAL IT        "Object"
    TARGET_NAME_FINAL MFC DLL   "Object"
    TARGET_NAME_FINAL           "Object"
    TARGET_NAME_RELEASE MFC DLL "Object"
    TARGET_NAME_RELEASE         "Object"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/ObjectDLL/TO2"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ObjectDLL/TO2"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_NAME_DEBUG MFC DLL   "Object"
    ARCHIVE_OUTPUT_NAME_DEBUG           "Object"
    ARCHIVE_OUTPUT_NAME_FINAL DE        "Object"
    ARCHIVE_OUTPUT_NAME_FINAL ES        "Object"
    ARCHIVE_OUTPUT_NAME_FINAL FR        "Object"
    ARCHIVE_OUTPUT_NAME_FINAL IT        "Object"
    ARCHIVE_OUTPUT_NAME_FINAL MFC DLL   "Object"
    ARCHIVE_OUTPUT_NAME_FINAL           "Object"
    ARCHIVE_OUTPUT_NAME_RELEASE MFC DLL "Object"
    ARCHIVE_OUTPUT_NAME_RELEASE         "Object"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ObjectShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD"
    ">"
    "$<$<CONFIG:Debug>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ObjectShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD"
    ">"
    "$<$<CONFIG:Final DE>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ObjectShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir"
    ">"
    "$<$<CONFIG:Final ES>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ObjectShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir"
    ">"
    "$<$<CONFIG:Final FR>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ObjectShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir"
    ">"
    "$<$<CONFIG:Final IT>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ObjectShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ObjectShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ObjectShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ObjectShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../ObjectShared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD"
    ">"
)

################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug MFC DLL>:"
        "_DEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_SERVERBUILD;"
        "MEMTRACK_SERVER;"
        "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS;"
        "_CRT_SECURE_NO_WARNINGS"
    ">"
    "$<$<CONFIG:Debug>:"
        "_DEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_SERVERBUILD;"
        "MEMTRACK_SERVER;"
        "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS;"
        "_CRT_SECURE_NO_WARNINGS"
    ">"
    "$<$<CONFIG:Final DE>:"
        "NDEBUG;"
        "_NOLFBUILD;"
        "USE_INTEL_COMPILER;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_SERVERBUILD;"
        "_FINAL;"
        "MEMTRACK_SERVER"
    ">"
    "$<$<CONFIG:Final ES>:"
        "NDEBUG;"
        "_NOLFBUILD;"
        "USE_INTEL_COMPILER;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_SERVERBUILD;"
        "_FINAL;"
        "MEMTRACK_SERVER"
    ">"
    "$<$<CONFIG:Final FR>:"
        "NDEBUG;"
        "_NOLFBUILD;"
        "USE_INTEL_COMPILER;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_SERVERBUILD;"
        "_FINAL;"
        "MEMTRACK_SERVER"
    ">"
    "$<$<CONFIG:Final IT>:"
        "NDEBUG;"
        "_NOLFBUILD;"
        "USE_INTEL_COMPILER;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_SERVERBUILD;"
        "_FINAL;"
        "MEMTRACK_SERVER"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "NDEBUG;"
        "_NOLFBUILD;"
        "USE_INTEL_COMPILER;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_SERVERBUILD;"
        "_FINAL;"
        "MEMTRACK_SERVER"
    ">"
    "$<$<CONFIG:Final>:"
        "NDEBUG;"
        "_NOLFBUILD;"
        "USE_INTEL_COMPILER;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_SERVERBUILD;"
        "_FINAL;"
        "MEMTRACK_SERVER"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "NDEBUG;"
        "_NOLFBUILD;"
        "USE_INTEL_COMPILER;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_SERVERBUILD;"
        "MEMTRACK_SERVER;"
        "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS;"
        "_CRT_SECURE_NO_WARNINGS"
    ">"
    "$<$<CONFIG:Release>:"
        "NDEBUG;"
        "_NOLFBUILD;"
        "USE_INTEL_COMPILER;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_SERVERBUILD;"
        "MEMTRACK_SERVER;"
        "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS;"
        "_CRT_SECURE_NO_WARNINGS"
    ">"
)

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug MFC DLL>:
            /Gm;
            /Od;
            /MDd;
            /Gy;
            /W3;
            /wd4996;
            /Zm1000;
            /Zc:forScope-
        >
        $<$<CONFIG:Debug>:
            /Gm;
            /Od;
            /MDd;
            /Gy;
            /W3;
            /wd4996;
            /Zm1000;
            /Zc:forScope-
        >
        $<$<CONFIG:Final DE>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:Final ES>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:Final FR>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:Final IT>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:Final MFC DLL>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:Final>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:Release MFC DLL>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000;
            /Zc:forScope-
        >
        $<$<CONFIG:Release>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000;
            /Zc:forScope-
        >
        $<$<CONFIG:Template>:
            ${DEFAULT_CXX_RUNTIME_LIBRARY}
        >
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
    )
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
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
    source_file_compile_options(../../Shared/TO2/TO2MissionButeMgr.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
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
    source_file_compile_options(../../Shared/TO2/TO2VersionMgr.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
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
    source_file_compile_options(GlobalsInit.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
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
    source_file_compile_options(Stdafx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug MFC DLL>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
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
    source_file_compile_options(TO2GameServerShell.cpp ${FILE_CL_OPTIONS})
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug MFC DLL>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:Debug>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:Final DE>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final ES>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final FR>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final IT>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final MFC DLL>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Release MFC DLL>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Release>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Template>:
            /DEBUG:FULL
        >
    )
endif()

################################################################################
# Post build events
################################################################################
add_custom_command_if(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMANDS
    COMMAND   $<CONFIG:Debug MFC DLL> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
    COMMAND           $<CONFIG:Debug> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
)

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    ButeMgr
    CryptMgr
    Lib_Lith
    MFCStub
    RegMgr
    Lib_StdLith
    ObjectShared
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    ButeMgr
    CryptMgr
    Lib_Lith
    MFCStub
    RegMgr
    Lib_StdLith
    ObjectShared
)

set(ADDITIONAL_LIBRARY_DEPENDENCIES
    "$<$<CONFIG:Debug MFC DLL>:"
        "odbc32;"
        "odbccp32;"
        "ButeMgr;"
        "ObjectShared;"
        "cryptmgr;"
        "Lib_Lith;"
        "Lib_StdLith;"
        "MFCStub;"
        "regmgr;"
        "ServerDir"
    ">"
    "$<$<CONFIG:Debug>:"
        "odbc32;"
        "odbccp32;"
        "ButeMgr;"
        "ObjectShared;"
        "cryptmgr;"
        "Lib_Lith;"
        "Lib_StdLith;"
        "MFCStub;"
        "regmgr;"
        "ServerDir"
    ">"
    "$<$<CONFIG:Final DE>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final ES>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final FR>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final IT>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Final>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "odbc32;"
        "odbccp32;"
        "ButeMgr;"
        "ObjectShared;"
        "cryptmgr;"
        "Lib_Lith;"
        "Lib_StdLith;"
        "MFCStub;"
        "regmgr;"
        "ServerDir"
    ">"
    "$<$<CONFIG:Release>:"
        "odbc32;"
        "odbccp32;"
        "ButeMgr;"
        "ObjectShared;"
        "cryptmgr;"
        "Lib_Lith;"
        "Lib_StdLith;"
        "MFCStub;"
        "regmgr;"
        "ServerDir"
    ">"
)
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

target_link_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug MFC DLL>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/ButeMgr;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/cryptmgr;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/MFCStub;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/regmgr;"
        "${CMAKE_SOURCE_DIR}//built/debug/ObjectDLL/ObjectShared;"
        "${CMAKE_SOURCE_DIR}//libs/ServerDir/debug"
    ">"
    "$<$<CONFIG:Debug>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/ButeMgr;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/cryptmgr;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/MFCStub;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/regmgr;"
        "${CMAKE_SOURCE_DIR}//built/debug/ObjectDLL/ObjectShared;"
        "${CMAKE_SOURCE_DIR}//libs/ServerDir/debug"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/ButeMgr;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/cryptmgr;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/MFCStub;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/regmgr;"
        "${CMAKE_SOURCE_DIR}//built/Release/ObjectDLL/ObjectShared;"
        "${CMAKE_SOURCE_DIR}//libs/ServerDir/Release"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/ButeMgr;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/cryptmgr;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/MFCStub;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/regmgr;"
        "${CMAKE_SOURCE_DIR}//built/Release/ObjectDLL/ObjectShared;"
        "${CMAKE_SOURCE_DIR}//libs/ServerDir/Release"
    ">"
)

