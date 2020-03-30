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
    INTERPROCEDURAL_OPTIMIZATION_FINAL DE        "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_FINAL ES        "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_FINAL FR        "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_FINAL IT        "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_FINAL MFC DLL   "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_FINAL           "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_RELEASE MFC DLL "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_RELEASE         "TRUE"
    INTERPROCEDURAL_OPTIMIZATION_TEMPLATE        "TRUE"
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
    "$<$<CONFIG:Debug MFC DLL>:"
        "_DEBUG"
    ">"
    "$<$<CONFIG:Debug>:"
        "_DEBUG"
    ">"
    "$<$<CONFIG:Final DE>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Final ES>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Final FR>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Final IT>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Final>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "NDEBUG"
    ">"
    "$<$<CONFIG:Release>:"
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
        $<$<CONFIG:Debug MFC DLL>:
            /Od;
            ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY}
        >
        $<$<CONFIG:Debug>:
            /Od;
            ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY}
        >
        $<$<CONFIG:Final DE>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        $<$<CONFIG:Final ES>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        $<$<CONFIG:Final FR>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        $<$<CONFIG:Final IT>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        $<$<CONFIG:Final MFC DLL>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        $<$<CONFIG:Final>:
            /O2;
            /Oi;
            ${DEFAULT_CXX_RUNTIME_LIBRARY};
            /Gy
        >
        $<$<CONFIG:Release MFC DLL>:
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
        $<$<CONFIG:Debug MFC DLL>:
            /INCREMENTAL
        >
        $<$<CONFIG:Debug>:
            /INCREMENTAL
        >
        $<$<CONFIG:Final DE>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final ES>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final FR>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final IT>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final MFC DLL>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Final>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Release MFC DLL>:
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        $<$<CONFIG:Release>:
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
    COMMAND   $<CONFIG:Debug MFC DLL> call "D:\\GameDev\\nolf2-modernizer\\Game\\_server_dir_debug.bat"
    COMMAND           $<CONFIG:Debug> call "D:\\GameDev\\nolf2-modernizer\\Game\\_server_dir_debug.bat"
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
    "$<$<CONFIG:Debug MFC DLL>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/debug/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:Debug>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/debug/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:Final DE>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:Final ES>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:Final FR>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:Final IT>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:Final MFC DLL>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:Final>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:Release MFC DLL>:"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
        "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
        "${CMAKE_SOURCE_DIR}//built/release/ClientShellDLL/ClientShellShared"
    ">"
    "$<$<CONFIG:Release>:"
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

