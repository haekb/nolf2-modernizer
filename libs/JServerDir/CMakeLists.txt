project(JServerDir CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "Exceptions.h"
    "framework.h"
    "Helpers.h"
    "ISocket.h"
    "JServerDir.h"
    "pch.h"
    "Peer.h"
    "TCPSocket.h"
    "UDPSocket.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "dllmain.cpp"
    "JServerDir.cpp"
    "pch.cpp"
    "Peer.cpp"
    "TCPSocket.cpp"
    "UDPSocket.cpp"
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

add_precompiled_header(${PROJECT_NAME} "pch.h" "pch.cpp")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE JServerDir)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    INTERPROCEDURAL_OPTIMIZATION_FINAL         "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_FINALDE       "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_FINALES       "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_FINALFR       "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_FINALIT       "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_FINALMFCDLL   "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_RELEASE       "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_RELEASEMFCDLL "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_TEMPLATE      "TRUE"
)
################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/sdk/inc;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../lith;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../stdlith;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../Game/Shared;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../Game/Libs/ServerDir;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../STLPort-STD"
)

################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:"
        "_DEBUG"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "_DEBUG"
    ">"
    "$<$<CONFIG:Final>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:FinalES>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Release>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Template>:"
        "NDEBUG"
    ">"
    "WIN32;"
    "JSERVERDIR_EXPORTS;"
    "_WINDOWS;"
    "_USRDLL;"
    "_CRT_SECURE_NO_WARNINGS;"
    "NOPS2;"
    "__STL_DONT_REDEFINE_STD;"
    "UNICODE;"
    "_UNICODE"
)

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:
            /Od;
            ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY}
        >
        $<$<CONFIG:DebugMFCDLL>:
            /Od;
            ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY}
        >
        $<$<CONFIG:Final>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        $<$<CONFIG:FinalDE>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        $<$<CONFIG:FinalES>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        $<$<CONFIG:FinalFR>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        $<$<CONFIG:FinalIT>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        $<$<CONFIG:FinalMFCDLL>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        $<$<CONFIG:Release>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        $<$<CONFIG:ReleaseMFCDLL>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        $<$<CONFIG:Template>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        /sdl;
        /W3;
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:
            /INCREMENTAL
        >
        $<$<CONFIG:DebugMFCDLL>:
            /INCREMENTAL
        >
        $<$<CONFIG:Final>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalDE>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalES>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalFR>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalIT>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:FinalMFCDLL>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Release>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:ReleaseMFCDLL>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Template>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        /DEBUG;
        /SUBSYSTEM:WINDOWS
    )
endif()

################################################################################
# Post build events
################################################################################
add_custom_command_if(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMANDS
    COMMAND         $<CONFIG:Debug> call "D:\\GameDev\\nolf2-modernizer\\Game\\_server_dir_debug.bat"
    COMMAND   $<CONFIG:DebugMFCDLL> call "D:\\GameDev\\nolf2-modernizer\\Game\\_server_dir_debug.bat"
)

################################################################################
# Dependencies
################################################################################
set(ADDITIONAL_LIBRARY_DEPENDENCIES
    "Lib_Lith;"
    "Lib_StdLith;"
    "ClientShellShared;"
    "Ws2_32"
)
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

target_link_directories(${PROJECT_NAME} PUBLIC
    "$<$<CONFIG:Debug>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/debug/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:DebugMFCDLL>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/debug/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:FinalDE>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:FinalES>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:FinalFR>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:FinalIT>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:FinalMFCDLL>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:Release>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:ReleaseMFCDLL>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:Template>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
)

