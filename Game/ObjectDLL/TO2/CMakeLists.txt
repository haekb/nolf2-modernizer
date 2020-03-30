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
    TARGET_NAME_DEBUG         "Object"
    TARGET_NAME_DEBUGMFCDLL   "Object"
    TARGET_NAME_FINAL         "Object"
    TARGET_NAME_FINALDE       "Object"
    TARGET_NAME_FINALES       "Object"
    TARGET_NAME_FINALFR       "Object"
    TARGET_NAME_FINALIT       "Object"
    TARGET_NAME_FINALMFCDLL   "Object"
    TARGET_NAME_RELEASE       "Object"
    TARGET_NAME_RELEASEMFCDLL "Object"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/ObjectDLL/TO2"
    OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/ObjectDLL/TO2"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ObjectDLL/TO2"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ObjectDLL/TO2"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_NAME_DEBUG         "Object"
    ARCHIVE_OUTPUT_NAME_DEBUGMFCDLL   "Object"
    ARCHIVE_OUTPUT_NAME_FINAL         "Object"
    ARCHIVE_OUTPUT_NAME_FINALDE       "Object"
    ARCHIVE_OUTPUT_NAME_FINALES       "Object"
    ARCHIVE_OUTPUT_NAME_FINALFR       "Object"
    ARCHIVE_OUTPUT_NAME_FINALIT       "Object"
    ARCHIVE_OUTPUT_NAME_FINALMFCDLL   "Object"
    ARCHIVE_OUTPUT_NAME_RELEASE       "Object"
    ARCHIVE_OUTPUT_NAME_RELEASEMFCDLL "Object"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
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
    "$<$<CONFIG:DebugMFCDLL>:"
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
    "$<$<CONFIG:FinalDE>:"
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
    "$<$<CONFIG:FinalES>:"
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
    "$<$<CONFIG:FinalFR>:"
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
    "$<$<CONFIG:FinalIT>:"
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
    "$<$<CONFIG:FinalMFCDLL>:"
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
    "$<$<CONFIG:ReleaseMFCDLL>:"
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
    "$<$<CONFIG:DebugMFCDLL>:"
        "_DEBUG;"
        "WIN32;"
        "_WINDOWS;"
        "NOPS2;"
        "_SERVERBUILD;"
        "MEMTRACK_SERVER;"
        "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS;"
        "_CRT_SECURE_NO_WARNINGS"
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
    "$<$<CONFIG:FinalDE>:"
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
    "$<$<CONFIG:FinalES>:"
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
    "$<$<CONFIG:FinalFR>:"
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
    "$<$<CONFIG:FinalIT>:"
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
    "$<$<CONFIG:FinalMFCDLL>:"
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
    "$<$<CONFIG:ReleaseMFCDLL>:"
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
        $<$<CONFIG:DebugMFCDLL>:
            /Gm;
            /Od;
            /MDd;
            /Gy;
            /W3;
            /wd4996;
            /Zm1000;
            /Zc:forScope-
        >
        $<$<CONFIG:Final>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:FinalDE>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:FinalES>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:FinalFR>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:FinalIT>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000
        >
        $<$<CONFIG:FinalMFCDLL>:
            /O2;
            /GF;
            /MD;
            /Gy;
            /W3;
            /Zm1000
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
        $<$<CONFIG:ReleaseMFCDLL>:
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
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:DebugMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
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
    source_file_compile_options(../../Shared/TO2/TO2MissionButeMgr.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:DebugMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
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
    source_file_compile_options(../../Shared/TO2/TO2VersionMgr.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:DebugMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
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
    source_file_compile_options(GlobalsInit.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:DebugMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
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
    source_file_compile_options(Stdafx.cpp ${FILE_CL_OPTIONS})
    string(CONCAT FILE_CL_OPTIONS
        "$<$<CONFIG:Debug>:"
            "/Zm1000;/Zm1000"
        ">"
        "$<$<CONFIG:DebugMFCDLL>:"
            "/Zm1000;/Zm1000"
        ">"
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
    source_file_compile_options(TO2GameServerShell.cpp ${FILE_CL_OPTIONS})
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:DebugMFCDLL>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL
        >
        $<$<CONFIG:Final>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalDE>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalES>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalFR>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalIT>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalMFCDLL>:
            /NOLOGO;
            /DEBUG:FULL;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Release>:
            /NOLOGO;
            /DEBUG;
            /SUBSYSTEM:WINDOWS;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:ReleaseMFCDLL>:
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
    COMMAND         $<CONFIG:Debug> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
    COMMAND   $<CONFIG:DebugMFCDLL> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
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
    "$<$<CONFIG:DebugMFCDLL>:"
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
    "$<$<CONFIG:Final>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:FinalES>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "odbc32;"
        "odbccp32"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
        "odbc32;"
        "odbccp32"
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
    "$<$<CONFIG:ReleaseMFCDLL>:"
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
    "$<$<CONFIG:DebugMFCDLL>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/ButeMgr;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/cryptmgr;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/MFCStub;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/regmgr;"
        "${CMAKE_SOURCE_DIR}//built/debug/ObjectDLL/ObjectShared;"
        "${CMAKE_SOURCE_DIR}//libs/ServerDir/debug"
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
    "$<$<CONFIG:ReleaseMFCDLL>:"
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

