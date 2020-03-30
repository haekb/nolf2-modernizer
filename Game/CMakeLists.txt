cmake_minimum_required(VERSION 3.13.0 FATAL_ERROR)

set(CMAKE_SYSTEM_VERSION 10.0 CACHE STRING "" FORCE)

project(TO2-Game CXX)

################################################################################
# Set target arch type if empty. Visual studio solution generator provides it.
################################################################################
if(NOT CMAKE_VS_PLATFORM_NAME)
    set(CMAKE_VS_PLATFORM_NAME "x86")
endif()
message("${CMAKE_VS_PLATFORM_NAME} architecture in use")

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86"))
    message("${CMAKE_VS_PLATFORM_NAME} arch is not supported, switching to x86!")
    set(CMAKE_VS_PLATFORM_NAME "x86")
endif()

################################################################################
# Global configuration types
################################################################################
set(CMAKE_CONFIGURATION_TYPES
    "Debug"
    "DebugMFCDLL"
    "Final"
    "FinalDE"
    "FinalES"
    "FinalFR"
    "FinalIT"
    "FinalMFCDLL"
    "Release"
    "ReleaseMFCDLL"
    "Template"
    CACHE STRING "" FORCE
)

################################################################################
# Global compiler options
################################################################################
if(MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_CXX_FLAGS "")
    set(CMAKE_CXX_FLAGS_DEBUG "")
    set(CMAKE_CXX_FLAGS_DEBUGMFCDLL "")
    set(CMAKE_CXX_FLAGS_FINAL "")
    set(CMAKE_CXX_FLAGS_FINALDE "")
    set(CMAKE_CXX_FLAGS_FINALES "")
    set(CMAKE_CXX_FLAGS_FINALFR "")
    set(CMAKE_CXX_FLAGS_FINALIT "")
    set(CMAKE_CXX_FLAGS_FINALMFCDLL "")
    set(CMAKE_CXX_FLAGS_RELEASE "")
    set(CMAKE_CXX_FLAGS_RELEASEMFCDLL "")
    set(CMAKE_CXX_FLAGS_TEMPLATE "")
endif()

################################################################################
# Global linker options
################################################################################
if(MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_EXE_LINKER_FLAGS "")
    set(CMAKE_MODULE_LINKER_FLAGS "")
    set(CMAKE_SHARED_LINKER_FLAGS "")
    set(CMAKE_STATIC_LINKER_FLAGS "")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUGMFCDLL "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_DEBUGMFCDLL "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_DEBUGMFCDLL "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_DEBUGMFCDLL "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_FINAL "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_FINAL "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_FINAL "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_FINAL "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_FINALDE "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_FINALDE "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_FINALDE "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_FINALDE "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_FINALES "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_FINALES "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_FINALES "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_FINALES "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_FINALFR "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_FINALFR "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_FINALFR "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_FINALFR "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_FINALIT "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_FINALIT "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_FINALIT "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_FINALIT "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_FINALMFCDLL "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_FINALMFCDLL "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_FINALMFCDLL "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_FINALMFCDLL "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASEMFCDLL "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_RELEASEMFCDLL "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASEMFCDLL "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_RELEASEMFCDLL "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_TEMPLATE "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_TEMPLATE "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_TEMPLATE "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_TEMPLATE "${CMAKE_STATIC_LINKER_FLAGS}")
endif()

################################################################################
# Nuget packages function stub.
################################################################################
function(use_package TARGET PACKAGE VERSION)
    message(WARNING "No implementation of use_package. Create yours. "
                    "Package \"${PACKAGE}\" with version \"${VERSION}\" "
                    "for target \"${TARGET}\" is ignored!")
endfunction()

################################################################################
# Common utils
################################################################################
include(CMake/Utils.cmake)

################################################################################
# Additional Global Settings(add specific info there)
################################################################################
include(CMake/GlobalSettingsInclude.cmake OPTIONAL)

################################################################################
# Use solution folders feature
################################################################################
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################################################################
# Sub-projects
################################################################################
add_subdirectory(../libs/ButeMgr ${CMAKE_BINARY_DIR}/ButeMgr)
add_subdirectory(../libs/CryptMgr ${CMAKE_BINARY_DIR}/CryptMgr)
add_subdirectory(../libs/JServerDir ${CMAKE_BINARY_DIR}/JServerDir)
add_subdirectory(../libs/lith ${CMAKE_BINARY_DIR}/Lib_Lith)
add_subdirectory(../libs/MFCStub ${CMAKE_BINARY_DIR}/MFCStub)
add_subdirectory(../libs/RegMgr ${CMAKE_BINARY_DIR}/RegMgr)
add_subdirectory(../libs/RegMgr32 ${CMAKE_BINARY_DIR}/regmgr32)
add_subdirectory(../libs/stdlith ${CMAKE_BINARY_DIR}/Lib_StdLith)
add_subdirectory(Autorun)
add_subdirectory(AutoRun2)
add_subdirectory(ClientFxDLL)
add_subdirectory(ClientRes/TO2)
add_subdirectory(CLIENTSHELLDLL/ClientShellShared)
add_subdirectory(ClientShellDLL/TO2)
add_subdirectory(Launcher/TO2)
add_subdirectory(Libs/LTGUIMgr)
add_subdirectory(ObjectDLL/ObjectShared)
add_subdirectory(ObjectDLL/TO2)
add_subdirectory(ServerApp)
add_subdirectory(ServerRes/TO2)



























project(Game CXX)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "Header.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "Hello.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "MakeFileProj"
)
################################################################################
# Output directory
################################################################################
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG         "${CMAKE_CURRENT_SOURCE_DIR}/./Debug/"
    OUTPUT_DIRECTORY_DEBUGMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./Debug/"
    OUTPUT_DIRECTORY_FINAL         "${CMAKE_CURRENT_SOURCE_DIR}/./Final/"
    OUTPUT_DIRECTORY_FINALDE       "${CMAKE_CURRENT_SOURCE_DIR}/./Game___Win32_Final_DE/"
    OUTPUT_DIRECTORY_FINALES       "${CMAKE_CURRENT_SOURCE_DIR}/./Game___Win32_Final_ES/"
    OUTPUT_DIRECTORY_FINALFR       "${CMAKE_CURRENT_SOURCE_DIR}/./Game___Win32_Final_FR/"
    OUTPUT_DIRECTORY_FINALIT       "${CMAKE_CURRENT_SOURCE_DIR}/./Game___Win32_Final_IT/"
    OUTPUT_DIRECTORY_FINALMFCDLL   "${CMAKE_CURRENT_SOURCE_DIR}/./Final/"
    OUTPUT_DIRECTORY_RELEASE       "${CMAKE_CURRENT_SOURCE_DIR}/./Release/"
    OUTPUT_DIRECTORY_RELEASEMFCDLL "${CMAKE_CURRENT_SOURCE_DIR}/./Release/"
)
################################################################################
# Compile definitions
################################################################################

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        ${DEFAULT_CXX_RUNTIME_LIBRARY};
        ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        /DEBUG:FULL
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
    JServerDir
    Object
    ClientRes
    ObjectShared
    ServerRes
    ButeMgr
    CryptMgr
    ClientFxDLL
    ClientShellShared
    ClientShellDLL
)

