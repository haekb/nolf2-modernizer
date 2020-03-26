project(ClientShellDLL CXX)

################################################################################
# Source groups
################################################################################
set(Discord
    "../../../libs/discord_game_sdk/cpp/achievement_manager.cpp"
    "../../../libs/discord_game_sdk/cpp/achievement_manager.h"
    "../../../libs/discord_game_sdk/cpp/activity_manager.cpp"
    "../../../libs/discord_game_sdk/cpp/activity_manager.h"
    "../../../libs/discord_game_sdk/cpp/application_manager.cpp"
    "../../../libs/discord_game_sdk/cpp/application_manager.h"
    "../../../libs/discord_game_sdk/cpp/core.cpp"
    "../../../libs/discord_game_sdk/cpp/core.h"
    "../../../libs/discord_game_sdk/cpp/discord.h"
    "../../../libs/discord_game_sdk/cpp/event.h"
    "../../../libs/discord_game_sdk/cpp/ffi.h"
    "../../../libs/discord_game_sdk/cpp/image_manager.cpp"
    "../../../libs/discord_game_sdk/cpp/image_manager.h"
    "../../../libs/discord_game_sdk/cpp/lobby_manager.cpp"
    "../../../libs/discord_game_sdk/cpp/lobby_manager.h"
    "../../../libs/discord_game_sdk/cpp/network_manager.cpp"
    "../../../libs/discord_game_sdk/cpp/network_manager.h"
    "../../../libs/discord_game_sdk/cpp/overlay_manager.cpp"
    "../../../libs/discord_game_sdk/cpp/overlay_manager.h"
    "../../../libs/discord_game_sdk/cpp/relationship_manager.cpp"
    "../../../libs/discord_game_sdk/cpp/relationship_manager.h"
    "../../../libs/discord_game_sdk/cpp/storage_manager.cpp"
    "../../../libs/discord_game_sdk/cpp/storage_manager.h"
    "../../../libs/discord_game_sdk/cpp/store_manager.cpp"
    "../../../libs/discord_game_sdk/cpp/store_manager.h"
    "../../../libs/discord_game_sdk/cpp/types.cpp"
    "../../../libs/discord_game_sdk/cpp/types.h"
    "../../../libs/discord_game_sdk/cpp/user_manager.cpp"
    "../../../libs/discord_game_sdk/cpp/user_manager.h"
    "../../../libs/discord_game_sdk/cpp/voice_manager.cpp"
    "../../../libs/discord_game_sdk/cpp/voice_manager.h"
)
source_group("Discord" FILES ${Discord})

set(Headers
    "../../../Engine/sdk/inc/iltbaseclass.h"
    "../../../Engine/sdk/inc/ltmodule.h"
    "../../../Engine/sdk/inc/ltobjref.h"
    "../../Libs/ServerDir/IServerDir.h"
    "../../Shared/LTPoly.h"
    "../../Shared/TO2/TO2MissionButeMgr.h"
    "../../Shared/TO2/TO2VersionMgr.h"
    "HUDAir.h"
    "HUDAmmo.h"
    "HUDCarrying.h"
    "HUDChooser.h"
    "HUDCompass.h"
    "HUDCrosshair.h"
    "HUDDamageDir.h"
    "HUDDoomsday.h"
    "HUDFramerate.h"
    "HUDHiding.h"
    "HUDHidingBar.h"
    "HUDObjectives.h"
    "HUDProgressBar.h"
    "HUDRadio.h"
    "HUDRespawn.h"
    "ScreenAudio.h"
    "ScreenConfigure.h"
    "ScreenControls.h"
    "ScreenCrosshair.h"
    "ScreenDisplay.h"
    "ScreenEndCoopMission.h"
    "ScreenEndDMMission.h"
    "ScreenEndMission.h"
    "ScreenFailure.h"
    "ScreenGame.h"
    "ScreenHost.h"
    "ScreenHostDDOptions.h"
    "ScreenHostDMOptions.h"
    "ScreenHostLevels.h"
    "ScreenHostMission.h"
    "ScreenHostOptions.h"
    "ScreenHostTDMOptions.h"
    "ScreenHostWeapons.h"
    "ScreenJoin.h"
    "ScreenJoinLAN.h"
    "ScreenJoystick.h"
    "ScreenKeyboard.h"
    "ScreenLoad.h"
    "ScreenMain.h"
    "ScreenMouse.h"
    "ScreenMulti.h"
    "ScreenOptions.h"
    "ScreenPerformance.h"
    "ScreenPlayer.h"
    "ScreenPlayerSkills.h"
    "ScreenPlayerTeam.h"
    "ScreenProfile.h"
    "ScreenSave.h"
    "ScreenSingle.h"
    "ScreenTeam.h"
    "Stdafx.h"
    "TO2GameClientShell.h"
    "TO2HUDMgr.h"
    "TO2InterfaceMgr.h"
    "TO2LayoutMgr.h"
    "TO2PlayerMgr.h"
    "TO2PlayerStats.h"
    "TO2ScreenMgr.h"
)
source_group("Headers" FILES ${Headers})

set(Source
    "../../../Engine/sdk/inc/iltbaseclass.cpp"
    "../../../Engine/sdk/inc/ltmodule.cpp"
    "../../../Engine/sdk/inc/ltobjref.cpp"
    "../../../Engine/sdk/inc/ltquatbase.cpp"
    "../../Shared/TO2/TO2MissionButeMgr.cpp"
    "../../Shared/TO2/TO2VersionMgr.cpp"
    "GlobalsInit.cpp"
    "HUDAir.cpp"
    "HUDAmmo.cpp"
    "HUDCarrying.cpp"
    "HUDChooser.cpp"
    "HUDCompass.cpp"
    "HUDCrosshair.cpp"
    "HUDDamageDir.cpp"
    "HUDDoomsday.cpp"
    "HUDFramerate.cpp"
    "HUDHiding.cpp"
    "HUDHidingBar.cpp"
    "HUDObjectives.cpp"
    "HUDProgressBar.cpp"
    "HUDRadio.cpp"
    "HUDRespawn.cpp"
    "ScreenAudio.cpp"
    "ScreenConfigure.cpp"
    "ScreenControls.cpp"
    "ScreenCrosshair.cpp"
    "ScreenDisplay.cpp"
    "ScreenEndCoopMission.cpp"
    "ScreenEndDMMission.cpp"
    "ScreenEndMission.cpp"
    "ScreenFailure.cpp"
    "ScreenGame.cpp"
    "ScreenHost.cpp"
    "ScreenHostDDOptions.cpp"
    "ScreenHostDMOptions.cpp"
    "ScreenHostLevels.cpp"
    "ScreenHostMission.cpp"
    "ScreenHostOptions.cpp"
    "ScreenHostTDMOptions.cpp"
    "ScreenHostWeapons.cpp"
    "ScreenJoin.cpp"
    "ScreenJoinLAN.cpp"
    "ScreenJoystick.cpp"
    "ScreenKeyboard.cpp"
    "ScreenLoad.cpp"
    "ScreenMain.cpp"
    "ScreenMouse.cpp"
    "ScreenMulti.cpp"
    "ScreenOptions.cpp"
    "ScreenPerformance.cpp"
    "ScreenPlayer.cpp"
    "ScreenPlayerSkills.cpp"
    "ScreenPlayerTeam.cpp"
    "ScreenProfile.cpp"
    "ScreenSave.cpp"
    "ScreenSingle.cpp"
    "ScreenTeam.cpp"
    "Stdafx.cpp"
    "TO2ClientWeaponAllocator.cpp"
    "TO2ClientWeaponAllocator.h"
    "TO2GameClientShell.cpp"
    "TO2HUDMgr.cpp"
    "TO2InterfaceMgr.cpp"
    "TO2LayoutMgr.cpp"
    "TO2PlayerMgr.cpp"
    "TO2PlayerStats.cpp"
    "TO2ScreenMgr.cpp"
)
source_group("Source" FILES ${Source})

set(ALL_FILES
    ${Discord}
    ${Headers}
    ${Source}
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
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG           "CShell"
        TARGET_NAME_FINAL           "CShell"
        TARGET_NAME_RELEASE         "CShell"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG MFC DLL   "CShell"
        TARGET_NAME_DEBUG           "CShell"
        TARGET_NAME_FINAL DE        "CShell"
        TARGET_NAME_FINAL ES        "CShell"
        TARGET_NAME_FINAL FR        "CShell"
        TARGET_NAME_FINAL IT        "CShell"
        TARGET_NAME_FINAL MFC DLL   "CShell"
        TARGET_NAME_FINAL           "CShell"
        TARGET_NAME_RELEASE MFC DLL "CShell"
        TARGET_NAME_RELEASE         "CShell"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/ClientShellDll/TO2"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ClientShellDll/TO2"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/ClientShellDll/TO2"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/ClientShellDll/TO2"
        OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Debug/ClientShellDll/TO2"
        OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ClientShellDll/TO2"
        OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ClientShellDll/TO2"
        OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ClientShellDll/TO2"
        OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ClientShellDll/TO2"
        OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ClientShellDll/TO2"
        OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Final/ClientShellDll/TO2"
        OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/ClientShellDll/TO2"
        OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/../../Built/Release/ClientShellDll/TO2"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ClientShellDll/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ClientShellDll/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Release/ClientShellDll/TO2"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ClientShellDll/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_DEBUG           "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Debug/ClientShellDll/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_FINAL DE        "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ClientShellDll/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_FINAL ES        "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ClientShellDll/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_FINAL FR        "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ClientShellDll/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_FINAL IT        "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ClientShellDll/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_FINAL MFC DLL   "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ClientShellDll/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_FINAL           "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Final/ClientShellDll/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE MFC DLL "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Release/ClientShellDll/TO2"
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE         "${CMAKE_CURRENT_SOURCE_DIR}/./../../Built/Release/ClientShellDll/TO2"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG           "CShell"
        ARCHIVE_OUTPUT_NAME_FINAL           "CShell"
        ARCHIVE_OUTPUT_NAME_RELEASE         "CShell"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_NAME_DEBUG MFC DLL   "CShell"
        ARCHIVE_OUTPUT_NAME_DEBUG           "CShell"
        ARCHIVE_OUTPUT_NAME_FINAL DE        "CShell"
        ARCHIVE_OUTPUT_NAME_FINAL ES        "CShell"
        ARCHIVE_OUTPUT_NAME_FINAL FR        "CShell"
        ARCHIVE_OUTPUT_NAME_FINAL IT        "CShell"
        ARCHIVE_OUTPUT_NAME_FINAL MFC DLL   "CShell"
        ARCHIVE_OUTPUT_NAME_FINAL           "CShell"
        ARCHIVE_OUTPUT_NAME_RELEASE MFC DLL "CShell"
        ARCHIVE_OUTPUT_NAME_RELEASE         "CShell"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/LTGUIMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/SDL2-2.0.10/include;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../config;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/discord_game_sdk/cpp"
        ">"
        "$<$<CONFIG:Final>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/LTGUIMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir"
        ">"
        "$<$<CONFIG:Release>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/LTGUIMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/SDL2-2.0.10/include;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../config;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/discord_game_sdk/cpp"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/LTGUIMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/SDL2-2.0.10/include;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../config;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/discord_game_sdk/cpp"
        ">"
        "$<$<CONFIG:Debug>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/LTGUIMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/SDL2-2.0.10/include;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../config;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/discord_game_sdk/cpp"
        ">"
        "$<$<CONFIG:Final DE>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/LTGUIMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir"
        ">"
        "$<$<CONFIG:Final ES>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/LTGUIMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir"
        ">"
        "$<$<CONFIG:Final FR>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/LTGUIMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir"
        ">"
        "$<$<CONFIG:Final IT>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/LTGUIMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/LTGUIMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir"
        ">"
        "$<$<CONFIG:Final>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-4.0/stlport;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/LTGUIMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/LTGUIMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/SDL2-2.0.10/include;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../config;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/discord_game_sdk/cpp"
        ">"
        "$<$<CONFIG:Release>:"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/.;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPORT-4.0/STLPORT_NO;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../ClientShellShared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../ClientRes/TO2;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Shared;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/sdk/inc;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/stdlith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/ButeMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/CryptMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/lith;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/MFCStub;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/LTGUIMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/RegMgr;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/wonapi;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../Libs/ServerDir;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/STLPort-STD;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/SDL2-2.0.10/include;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../config;"
            "${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/discord_game_sdk/cpp"
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
            "_CLIENTBUILD;"
            "WIN32;"
            "_WINDOWS;"
            "NOPS2;"
            "MEMTRACK_CLIENT;"
            "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS;"
            "_CRT_SECURE_NO_WARNINGS;"
            "NDISCORDBUILD"
        ">"
        "$<$<CONFIG:Final>:"
            "NDEBUG;"
            "_CLIENTBUILD;"
            "WIN32;"
            "_WINDOWS;"
            "_NOLFBUILD;"
            "NO_PRAGMA_LIBS;"
            "NOPS2;"
            "_FINAL;"
            "MEMTRACK_CLIENT"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG;"
            "_CLIENTBUILD;"
            "WIN32;"
            "_WINDOWS;"
            "_NOLFBUILD;"
            "NO_PRAGMA_LIBS;"
            "NOPS2;"
            "MEMTRACK_CLIENT;"
            "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS;"
            "_CRT_SECURE_NO_WARNINGS;"
            "NDISCORDBUILD"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug MFC DLL>:"
            "_DEBUG;"
            "_CLIENTBUILD;"
            "WIN32;"
            "_WINDOWS;"
            "NOPS2;"
            "MEMTRACK_CLIENT;"
            "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS;"
            "_CRT_SECURE_NO_WARNINGS;"
            "NDISCORDBUILD"
        ">"
        "$<$<CONFIG:Debug>:"
            "_DEBUG;"
            "_CLIENTBUILD;"
            "WIN32;"
            "_WINDOWS;"
            "NOPS2;"
            "MEMTRACK_CLIENT;"
            "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS;"
            "_CRT_SECURE_NO_WARNINGS;"
            "NDISCORDBUILD"
        ">"
        "$<$<CONFIG:Final DE>:"
            "NDEBUG;"
            "_CLIENTBUILD;"
            "WIN32;"
            "_WINDOWS;"
            "_NOLFBUILD;"
            "NO_PRAGMA_LIBS;"
            "NOPS2;"
            "_FINAL;"
            "MEMTRACK_CLIENT"
        ">"
        "$<$<CONFIG:Final ES>:"
            "NDEBUG;"
            "_CLIENTBUILD;"
            "WIN32;"
            "_WINDOWS;"
            "_NOLFBUILD;"
            "NO_PRAGMA_LIBS;"
            "NOPS2;"
            "_FINAL;"
            "MEMTRACK_CLIENT"
        ">"
        "$<$<CONFIG:Final FR>:"
            "NDEBUG;"
            "_CLIENTBUILD;"
            "WIN32;"
            "_WINDOWS;"
            "_NOLFBUILD;"
            "NO_PRAGMA_LIBS;"
            "NOPS2;"
            "_FINAL;"
            "MEMTRACK_CLIENT"
        ">"
        "$<$<CONFIG:Final IT>:"
            "NDEBUG;"
            "_CLIENTBUILD;"
            "WIN32;"
            "_WINDOWS;"
            "_NOLFBUILD;"
            "NO_PRAGMA_LIBS;"
            "NOPS2;"
            "_FINAL;"
            "MEMTRACK_CLIENT"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "NDEBUG;"
            "_CLIENTBUILD;"
            "WIN32;"
            "_WINDOWS;"
            "_NOLFBUILD;"
            "NO_PRAGMA_LIBS;"
            "NOPS2;"
            "_FINAL;"
            "MEMTRACK_CLIENT"
        ">"
        "$<$<CONFIG:Final>:"
            "NDEBUG;"
            "_CLIENTBUILD;"
            "WIN32;"
            "_WINDOWS;"
            "_NOLFBUILD;"
            "NO_PRAGMA_LIBS;"
            "NOPS2;"
            "_FINAL;"
            "MEMTRACK_CLIENT"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "NDEBUG;"
            "_CLIENTBUILD;"
            "WIN32;"
            "_WINDOWS;"
            "_NOLFBUILD;"
            "NO_PRAGMA_LIBS;"
            "NOPS2;"
            "MEMTRACK_CLIENT;"
            "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS;"
            "_CRT_SECURE_NO_WARNINGS;"
            "NDISCORDBUILD"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG;"
            "_CLIENTBUILD;"
            "WIN32;"
            "_WINDOWS;"
            "_NOLFBUILD;"
            "NO_PRAGMA_LIBS;"
            "NOPS2;"
            "MEMTRACK_CLIENT;"
            "_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS;"
            "_CRT_SECURE_NO_WARNINGS;"
            "NDISCORDBUILD"
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
                /RTC1;
                /MDd;
                /Gy;
                /W3;
                /Zi;
                /wd4996;
                /Zm1000;
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
                /Zc:forScope-;
                /Y-
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
                /RTC1;
                /MDd;
                /Gy;
                /W3;
                /Zi;
                /wd4996;
                /Zm1000;
                /Zc:forScope-;
                /Y-
            >
            $<$<CONFIG:Debug>:
                /Od;
                /RTC1;
                /MDd;
                /Gy;
                /W3;
                /Zi;
                /wd4996;
                /Zm1000;
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
                /Zc:forScope-;
                /Y-
            >
            $<$<CONFIG:Release>:
                /O2;
                /GF;
                /MD;
                /Gy;
                /W3;
                ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
                /Zm1000;
                /Zc:forScope-;
                /Y-
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
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug MFC DLL>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
        )
    endif()
    source_file_compile_options(../../../Engine/sdk/inc/iltbaseclass.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug MFC DLL>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
        )
    endif()
    source_file_compile_options(../../../Engine/sdk/inc/ltmodule.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug MFC DLL>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
        )
    endif()
    source_file_compile_options(../../../Engine/sdk/inc/ltobjref.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug MFC DLL>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final DE>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final ES>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final FR>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final IT>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final MFC DLL>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Release MFC DLL>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000;/Y-"
            ">"
        )
    endif()
    source_file_compile_options(../../../Engine/sdk/inc/ltquatbase.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(../../Shared/TO2/TO2MissionButeMgr.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(../../Shared/TO2/TO2VersionMgr.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(GlobalsInit.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(HUDAir.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(HUDAmmo.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(HUDCarrying.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(HUDChooser.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(HUDCompass.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(HUDCrosshair.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(HUDDamageDir.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(HUDDoomsday.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(HUDHiding.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(HUDHidingBar.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(HUDObjectives.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(HUDProgressBar.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(HUDRadio.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(HUDRespawn.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenAudio.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenConfigure.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenControls.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenCrosshair.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenDisplay.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenEndCoopMission.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenEndDMMission.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenEndMission.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenFailure.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenGame.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenHost.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenHostDDOptions.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenHostDMOptions.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenHostLevels.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenHostMission.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenHostOptions.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenHostTDMOptions.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenHostWeapons.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenJoin.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenJoinLAN.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenJoystick.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenKeyboard.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenLoad.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenMain.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenMouse.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenMulti.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenOptions.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenPerformance.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenPlayer.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenPlayerSkills.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenPlayerTeam.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenProfile.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenSave.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenSingle.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(ScreenTeam.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(Stdafx.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(TO2ClientWeaponAllocator.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(TO2GameClientShell.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(TO2HUDMgr.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(TO2InterfaceMgr.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(TO2LayoutMgr.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(TO2PlayerMgr.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(TO2PlayerStats.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Debug>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Final>:"
                "/Zm1000;/Zm1000"
            ">"
            "$<$<CONFIG:Release>:"
                "/Zm1000;/Zm1000"
            ">"
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    endif()
    source_file_compile_options(TO2ScreenMgr.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug MFC DLL>:
                /DEBUG:FULL
            >
            $<$<CONFIG:Debug>:
                /NOLOGO;
                /DEBUG;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL
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
                /NODEFAULTLIB:LIBCMTD;
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL:NO
            >
            $<$<CONFIG:Release MFC DLL>:
                /DEBUG:FULL
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
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
                /NODEFAULTLIB:LIBCMTD;
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL:NO
            >
            $<$<CONFIG:Final ES>:
                /NODEFAULTLIB:LIBCMTD;
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL:NO
            >
            $<$<CONFIG:Final FR>:
                /NODEFAULTLIB:LIBCMTD;
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL:NO
            >
            $<$<CONFIG:Final IT>:
                /NODEFAULTLIB:LIBCMTD;
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL:NO
            >
            $<$<CONFIG:Final MFC DLL>:
                /NODEFAULTLIB:LIBCMTD;
                /NOLOGO;
                /DEBUG:FULL;
                /SUBSYSTEM:WINDOWS;
                /INCREMENTAL:NO
            >
            $<$<CONFIG:Final>:
                /NODEFAULTLIB:LIBCMTD;
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
endif()

################################################################################
# Post build events
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    add_custom_command_if(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMANDS
        COMMAND           $<CONFIG:Debug> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    add_custom_command_if(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMANDS
        COMMAND   $<CONFIG:Debug MFC DLL> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
        COMMAND           $<CONFIG:Debug> call "D:\\GameDev\\nolf2-modernizer\\Game\\_after_build_debug.bat"
    )
endif()

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
    ClientRes
    LTGUIMgr
    ClientShellShared
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    ButeMgr
    CryptMgr
    Lib_Lith
    MFCStub
    RegMgr
    Lib_StdLith
    ClientRes
    LTGUIMgr
    ClientShellShared
)

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "$<$<CONFIG:Debug>:"
            "winmm;"
            "wsock32;"
            "ButeMgr;"
            "ClientShellShared;"
            "cryptmgr;"
            "Lib_Lith;"
            "Lib_StdLith;"
            "ltguimgr;"
            "MFCStub;"
            "regmgr;"
            "ServerDir;"
            "SDL2;"
            "SDL2main;"
            "discord_game_sdk.dll"
        ">"
        "$<$<CONFIG:Final>:"
            "winmm;"
            "odbc32;"
            "odbccp32"
        ">"
        "$<$<CONFIG:Release>:"
            "winmm;"
            "wsock32;"
            "ButeMgr;"
            "ClientShellShared;"
            "cryptmgr;"
            "Lib_Lith;"
            "Lib_StdLith;"
            "ltguimgr;"
            "MFCStub;"
            "regmgr;"
            "ServerDir;"
            "SDL2;"
            "SDL2main;"
            "discord_game_sdk.dll"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "$<$<CONFIG:Debug MFC DLL>:"
            "winmm;"
            "wsock32;"
            "ButeMgr;"
            "ClientShellShared;"
            "cryptmgr;"
            "Lib_Lith;"
            "Lib_StdLith;"
            "ltguimgr;"
            "MFCStub;"
            "regmgr;"
            "ServerDir;"
            "SDL2;"
            "SDL2main;"
            "discord_game_sdk.dll"
        ">"
        "$<$<CONFIG:Debug>:"
            "winmm;"
            "wsock32;"
            "ButeMgr;"
            "ClientShellShared;"
            "cryptmgr;"
            "Lib_Lith;"
            "Lib_StdLith;"
            "ltguimgr;"
            "MFCStub;"
            "regmgr;"
            "ServerDir;"
            "SDL2;"
            "SDL2main;"
            "discord_game_sdk.dll"
        ">"
        "$<$<CONFIG:Final DE>:"
            "winmm;"
            "odbc32;"
            "odbccp32"
        ">"
        "$<$<CONFIG:Final ES>:"
            "winmm;"
            "odbc32;"
            "odbccp32"
        ">"
        "$<$<CONFIG:Final FR>:"
            "winmm;"
            "odbc32;"
            "odbccp32"
        ">"
        "$<$<CONFIG:Final IT>:"
            "winmm;"
            "odbc32;"
            "odbccp32"
        ">"
        "$<$<CONFIG:Final MFC DLL>:"
            "winmm;"
            "odbc32;"
            "odbccp32"
        ">"
        "$<$<CONFIG:Final>:"
            "winmm;"
            "odbc32;"
            "odbccp32"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "winmm;"
            "wsock32;"
            "ButeMgr;"
            "ClientShellShared;"
            "cryptmgr;"
            "Lib_Lith;"
            "Lib_StdLith;"
            "ltguimgr;"
            "MFCStub;"
            "regmgr;"
            "ServerDir;"
            "SDL2;"
            "SDL2main;"
            "discord_game_sdk.dll"
        ">"
        "$<$<CONFIG:Release>:"
            "winmm;"
            "wsock32;"
            "ButeMgr;"
            "ClientShellShared;"
            "cryptmgr;"
            "Lib_Lith;"
            "Lib_StdLith;"
            "ltguimgr;"
            "MFCStub;"
            "regmgr;"
            "ServerDir;"
            "SDL2;"
            "SDL2main;"
            "discord_game_sdk.dll"
        ">"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_link_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug>:"
            "${CMAKE_SOURCE_DIR}//../libs/SDL2-2.0.10/lib/x86;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/ButeMgr;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/cryptmgr;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_Lith;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_StdLith;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/MFCStub;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/regmgr;"
            "${CMAKE_SOURCE_DIR}//built/debug/libs/ltguimgr;"
            "${CMAKE_SOURCE_DIR}//built/debug/ClientShellDLL/ClientShellShared;"
            "${CMAKE_SOURCE_DIR}//libs/ServerDir/debug;"
            "${CMAKE_SOURCE_DIR}/../libs/discord_game_sdk/lib/x86;"
            "D:/GameDev/no-one-lives-forever-2-source/libs/discord_game_sdk/lib/x86"
        ">"
        "$<$<CONFIG:Release>:"
            "${CMAKE_SOURCE_DIR}//../libs/SDL2-2.0.10/lib/x86;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/ButeMgr;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/cryptmgr;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/MFCStub;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/regmgr;"
            "${CMAKE_SOURCE_DIR}//built/Release/libs/ltguimgr;"
            "${CMAKE_SOURCE_DIR}//built/Release/ClientShellDLL/ClientShellShared;"
            "${CMAKE_SOURCE_DIR}//libs/ServerDir/Release;"
            "${CMAKE_SOURCE_DIR}/../libs/discord_game_sdk/lib/x86;"
            "D:/GameDev/no-one-lives-forever-2-source/libs/discord_game_sdk/lib/x86"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_link_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug MFC DLL>:"
            "${CMAKE_SOURCE_DIR}//../libs/SDL2-2.0.10/lib/x86;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/ButeMgr;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/cryptmgr;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_Lith;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_StdLith;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/MFCStub;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/regmgr;"
            "${CMAKE_SOURCE_DIR}//built/debug/libs/ltguimgr;"
            "${CMAKE_SOURCE_DIR}//built/debug/ClientShellDLL/ClientShellShared;"
            "${CMAKE_SOURCE_DIR}//libs/ServerDir/debug;"
            "${CMAKE_SOURCE_DIR}/../libs/discord_game_sdk/lib/x86;"
            "D:/GameDev/no-one-lives-forever-2-source/libs/discord_game_sdk/lib/x86"
        ">"
        "$<$<CONFIG:Debug>:"
            "${CMAKE_SOURCE_DIR}//../libs/SDL2-2.0.10/lib/x86;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/ButeMgr;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/cryptmgr;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_Lith;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/Lib_StdLith;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/MFCStub;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Debug/regmgr;"
            "${CMAKE_SOURCE_DIR}//built/debug/libs/ltguimgr;"
            "${CMAKE_SOURCE_DIR}//built/debug/ClientShellDLL/ClientShellShared;"
            "${CMAKE_SOURCE_DIR}//libs/ServerDir/debug;"
            "${CMAKE_SOURCE_DIR}/../libs/discord_game_sdk/lib/x86;"
            "D:/GameDev/no-one-lives-forever-2-source/libs/discord_game_sdk/lib/x86"
        ">"
        "$<$<CONFIG:Release MFC DLL>:"
            "${CMAKE_SOURCE_DIR}//../libs/SDL2-2.0.10/lib/x86;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/ButeMgr;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/cryptmgr;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/MFCStub;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/regmgr;"
            "${CMAKE_SOURCE_DIR}//built/Release/libs/ltguimgr;"
            "${CMAKE_SOURCE_DIR}//built/Release/ClientShellDLL/ClientShellShared;"
            "${CMAKE_SOURCE_DIR}//libs/ServerDir/Release;"
            "${CMAKE_SOURCE_DIR}/../libs/discord_game_sdk/lib/x86;"
            "D:/GameDev/no-one-lives-forever-2-source/libs/discord_game_sdk/lib/x86"
        ">"
        "$<$<CONFIG:Release>:"
            "${CMAKE_SOURCE_DIR}//../libs/SDL2-2.0.10/lib/x86;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/ButeMgr;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/cryptmgr;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_Lith;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/Lib_StdLith;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/MFCStub;"
            "${CMAKE_SOURCE_DIR}/../libs/built/Release/regmgr;"
            "${CMAKE_SOURCE_DIR}//built/Release/libs/ltguimgr;"
            "${CMAKE_SOURCE_DIR}//built/Release/ClientShellDLL/ClientShellShared;"
            "${CMAKE_SOURCE_DIR}//libs/ServerDir/Release;"
            "${CMAKE_SOURCE_DIR}/../libs/discord_game_sdk/lib/x86;"
            "D:/GameDev/no-one-lives-forever-2-source/libs/discord_game_sdk/lib/x86"
        ">"
    )
endif()

