# Microsoft Developer Studio Project File - Name="ClientShellShared" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=CLIENTSHELLSHARED - WIN32 FINAL
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ClientShellShared.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ClientShellShared.mak" CFG="CLIENTSHELLSHARED - WIN32 FINAL"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ClientShellShared - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ClientShellShared - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "ClientShellShared - Win32 Final" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "ClientShellShared"
# PROP Scc_LocalPath "..\..\.."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ClientShellShared - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Built\Release\ClientShellDLL\ClientShellShared"
# PROP Intermediate_Dir "..\..\Built\Release\ClientShellDLL\ClientShellShared"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\clientres\shared" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\libs\ltguimgr" /I "..\..\..\libs\regmgr" /I "..\\" /I "..\..\libs\serverdir" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_CLIENTBUILD" /D "NOPS2" /D "MEMTRACK_CLIENT" /Yu"stdafx.h" /FD /Zm1000 /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "ClientShellShared - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\Built\Debug\ClientShellDLL\ClientShellShared"
# PROP Intermediate_Dir "..\..\Built\Debug\ClientShellDLL\ClientShellShared"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I ".\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\clientres\shared" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\libs\ltguimgr" /I "..\..\..\libs\regmgr" /I "..\\" /I "..\..\libs\serverdir" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_CLIENTBUILD" /D "NOPS2" /D "MEMTRACK_CLIENT" /FR /Yu"stdafx.h" /FD /GZ /Zm1000 /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "ClientShellShared - Win32 Final"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Final"
# PROP BASE Intermediate_Dir "Final"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Built\Final\ClientShellDLL\ClientShellShared"
# PROP Intermediate_Dir "..\..\Built\Final\ClientShellDLL\ClientShellShared"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\clientres\shared" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\libs\ltguimgr" /I "..\..\..\libs\regmgr" /I "..\\" /I "..\..\libs\serverdir" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_CLIENTBUILD" /D "NOPS2" /D "_FINAL" /Yu"stdafx.h" /FD /Zm1000 /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\clientres\shared" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\libs\ltguimgr" /I "..\..\..\libs\regmgr" /I "..\\" /I "..\..\libs\serverdir" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_CLIENTBUILD" /D "NOPS2" /D "_FINAL" /D "MEMTRACK_CLIENT" /Yu"stdafx.h" /FD /Zm1000 /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "ClientShellShared - Win32 Release"
# Name "ClientShellShared - Win32 Debug"
# Name "ClientShellShared - Win32 Final"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ActivateObjectFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ActivateTypeMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\Animator.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\AssertMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\AttachButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\BaseLineSystemFX.cpp
# End Source File
# Begin Source File

SOURCE=.\BaseMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\BaseParticleSystemFX.cpp
# End Source File
# Begin Source File

SOURCE=.\BasePolyDrawFX.cpp
# End Source File
# Begin Source File

SOURCE=.\BaseScaleFX.cpp
# End Source File
# Begin Source File

SOURCE=.\BaseScreen.cpp
# End Source File
# Begin Source File

SOURCE=.\BeamFX.cpp
# End Source File
# Begin Source File

SOURCE=.\BodyFX.cpp
# End Source File
# Begin Source File

SOURCE=.\BulletTrailFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ButeListReader.cpp
# End Source File
# Begin Source File

SOURCE=.\CameraOffsetMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ChainedFX.cpp
# End Source File
# Begin Source File

SOURCE=.\CharacterFX.cpp
# End Source File
# Begin Source File

SOURCE=.\CheatMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\client_physics.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientFXDB.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientFXMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientInfoMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientMultiplayerMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientSaveLoadMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ClientServerShared.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientSoundMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientTrackedNodeContext.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientTrackedNodeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientUtilities.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientWeapon.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientWeaponMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientWeaponUtils.cpp
# End Source File
# Begin Source File

SOURCE=.\CMoveMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\CommonUtilities.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\CRC32.cpp
# End Source File
# Begin Source File

SOURCE=.\Credits.cpp
# End Source File
# Begin Source File

SOURCE=.\CursorMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\DamageFXMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\DamageTypes.cpp
# End Source File
# Begin Source File

SOURCE=.\DeathFX.cpp
# End Source File
# Begin Source File

SOURCE=.\DebrisFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\DebrisMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\DebugLine.cpp
# End Source File
# Begin Source File

SOURCE=.\DebugLineFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\DebugNew.cpp
# End Source File
# Begin Source File

SOURCE=.\DoomsdayPieceFX.cpp
# End Source File
# Begin Source File

SOURCE=.\DynamicLightFX.cpp
# End Source File
# Begin Source File

SOURCE=.\DynamicOccluderVolumeFX.cpp
# End Source File
# Begin Source File

SOURCE=.\ExplosionFX.cpp
# End Source File
# Begin Source File

SOURCE=.\FireFX.cpp
# End Source File
# Begin Source File

SOURCE=.\FlashLight.cpp
# End Source File
# Begin Source File

SOURCE=.\FullScreenTint.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\FXButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\FXStructs.cpp
# End Source File
# Begin Source File

SOURCE=.\GadgetDisabler.cpp
# End Source File
# Begin Source File

SOURCE=.\GadgetTargetFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\GameAlloc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\GameButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\GameClientShell.cpp
# End Source File
# Begin Source File

SOURCE=.\GameSettings.cpp
# End Source File
# Begin Source File

SOURCE=.\GibFX.cpp
# End Source File
# Begin Source File

SOURCE=.\GlobalClientMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\GlobalMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\HeadBobMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\HitBox.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDBar.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDChatInput.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDDamage.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDDecision.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDDisplayMeter.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDDistance.cpp
# End Source File
# Begin Source File

SOURCE=..\TO2\HUDHealth.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDMessage.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDMessageQueue.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDMeter.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDMissionText.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDPaused.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDPopup.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDRadar.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDScores.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDSubtitles.cpp
# End Source File
# Begin Source File

SOURCE=.\HUDTransmission.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltbaseclass.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\IntelItemList.cpp
# End Source File
# Begin Source File

SOURCE=.\InterfaceMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\InterfaceResMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\InterfaceSurfMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\InterfaceTimer.cpp
# End Source File
# Begin Source File

SOURCE=.\IpMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\JumpVolumeFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\KeyMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\LaserBeam.cpp
# End Source File
# Begin Source File

SOURCE=.\LaserTriggerFX.cpp
# End Source File
# Begin Source File

SOURCE=.\LayoutMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\LeanMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\LensFlareFX.cpp
# End Source File
# Begin Source File

SOURCE=.\LightFX.cpp
# End Source File
# Begin Source File

SOURCE=.\LightGroupFX.cpp
# End Source File
# Begin Source File

SOURCE=.\LightningFX.cpp
# End Source File
# Begin Source File

SOURCE=.\LightScaleMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\LineSystemFX.cpp
# End Source File
# Begin Source File

SOURCE=.\LoadingScreen.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\LTEulerAngles.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltmodule.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltobjref.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltquatbase.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\MarkSFX.cpp
# End Source File
# Begin Source File

SOURCE=.\MenuIntel.cpp
# End Source File
# Begin Source File

SOURCE=.\MenuInventory.cpp
# End Source File
# Begin Source File

SOURCE=.\MenuKeys.cpp
# End Source File
# Begin Source File

SOURCE=.\MenuMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\MenuMission.cpp
# End Source File
# Begin Source File

SOURCE=.\MenuPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\MenuSystem.cpp
# End Source File
# Begin Source File

SOURCE=.\MessageBox.cpp
# End Source File
# Begin Source File

SOURCE=.\MineFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\MissionButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\MissionMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ModelButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\Music.cpp
# End Source File
# Begin Source File

SOURCE=.\MuzzleFlashFX.cpp
# End Source File
# Begin Source File

SOURCE=.\MuzzleFlashParticleFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\NetDefs.cpp
# End Source File
# Begin Source File

SOURCE=.\NodeController.cpp
# End Source File
# Begin Source File

SOURCE=.\NodeLinesFX.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjectiveControl.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjSpriteFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ParsedMsg.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticleExplosionFX.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticleShowerFX.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticleSystemFX.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticleTrailFX.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticleTrailSegmentFX.cpp
# End Source File
# Begin Source File

SOURCE=.\PerformanceMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\PerformanceTest.cpp
# End Source File
# Begin Source File

SOURCE=.\PickupItemFX.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerCamera.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerLureFX.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerSoundFX.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerStats.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerVehicleFX.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerViewAttachmentMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\PolyDebrisFX.cpp
# End Source File
# Begin Source File

SOURCE=.\PolyGridFX.cpp
# End Source File
# Begin Source File

SOURCE=.\PolyLineFX.cpp
# End Source File
# Begin Source File

SOURCE=.\PopupMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\PopupText.cpp
# End Source File
# Begin Source File

SOURCE=.\ProfileMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ProfileUtils.cpp
# End Source File
# Begin Source File

SOURCE=.\ProjectileFX.cpp
# End Source File
# Begin Source File

SOURCE=.\PVFXMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\RadarObjectFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\RadarTypeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\RagDoll.cpp
# End Source File
# Begin Source File

SOURCE=.\RagDollConstraint.cpp
# End Source File
# Begin Source File

SOURCE=.\RandomSparksFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SaveLoadMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ScatterFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ScmdConsole.cpp
# End Source File
# Begin Source File

SOURCE=.\ScmdConsoleDriver_CShell.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenPostload.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenPreload.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenSpriteMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenTintMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\Searcher.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SearchItemMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\SearchLightFX.cpp
# End Source File
# Begin Source File

SOURCE=.\SFXMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SharedFXStructs.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SharedMission.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SharedScoring.cpp
# End Source File
# Begin Source File

SOURCE=.\ShellCasingFX.cpp
# End Source File
# Begin Source File

SOURCE=.\SkillControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SkillsButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\SmokeFX.cpp
# End Source File
# Begin Source File

SOURCE=.\SnowFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SoundButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SoundFilterMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\SoundFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SoundMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\Sparam.cpp
# End Source File
# Begin Source File

SOURCE=.\SpecialFXList.cpp
# End Source File
# Begin Source File

SOURCE=.\sprinklesfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\stacktrace.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SteamFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SurfaceFunctions.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SurfaceMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\TargetMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TeamMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TemplateList.cpp
# End Source File
# Begin Source File

SOURCE=.\TextureFXMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\TimedText.cpp
# End Source File
# Begin Source File

SOURCE=.\TracerFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TrackedNode.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TrackedNodeContext.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TrackedNodeControlFn.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TrackedNodeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\TransitionFXMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\TriggerFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TriggerTypeMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\UberAssert.cpp
# End Source File
# Begin Source File

SOURCE=.\VehicleMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\VersionMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\VisionModeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\VKDefs.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\WaveFn.cpp
# End Source File
# Begin Source File

SOURCE=.\WeaponChooser.cpp
# End Source File
# Begin Source File

SOURCE=.\WeaponFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\WeaponMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\WeatherFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\WinUtil.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ActivateObjectFX.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ActivateTypeMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ActivationData.h
# End Source File
# Begin Source File

SOURCE=.\BaseLineSystemFX.h
# End Source File
# Begin Source File

SOURCE=.\BaseMenu.h
# End Source File
# Begin Source File

SOURCE=.\BaseParticleSystemFX.h
# End Source File
# Begin Source File

SOURCE=.\BasePolyDrawFX.h
# End Source File
# Begin Source File

SOURCE=.\BaseScaleFX.h
# End Source File
# Begin Source File

SOURCE=.\BaseScreen.h
# End Source File
# Begin Source File

SOURCE=.\BeamFX.h
# End Source File
# Begin Source File

SOURCE=.\BodyFX.h
# End Source File
# Begin Source File

SOURCE=.\BulletTrailFX.h
# End Source File
# Begin Source File

SOURCE=.\CameraFX.h
# End Source File
# Begin Source File

SOURCE=.\CameraOffsetMgr.h
# End Source File
# Begin Source File

SOURCE=.\ChainedFX.h
# End Source File
# Begin Source File

SOURCE=.\CharacterFX.h
# End Source File
# Begin Source File

SOURCE=.\CheatMgr.h
# End Source File
# Begin Source File

SOURCE=.\client_physics.h
# End Source File
# Begin Source File

SOURCE=.\ClientButeMgr.h
# End Source File
# Begin Source File

SOURCE=.\ClientFXDB.h
# End Source File
# Begin Source File

SOURCE=.\ClientFXMgr.h
# End Source File
# Begin Source File

SOURCE=.\ClientInfoMgr.h
# End Source File
# Begin Source File

SOURCE=.\ClientMultiplayerMgr.h
# End Source File
# Begin Source File

SOURCE=.\ClientSaveLoadMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ClientServerShared.h
# End Source File
# Begin Source File

SOURCE=.\ClientSoundMgr.h
# End Source File
# Begin Source File

SOURCE=.\ClientTrackedNodeContext.h
# End Source File
# Begin Source File

SOURCE=.\ClientTrackedNodeMgr.h
# End Source File
# Begin Source File

SOURCE=.\ClientUtilities.h
# End Source File
# Begin Source File

SOURCE=.\ClientWeapon.h
# End Source File
# Begin Source File

SOURCE=.\ClientWeaponAllocator.h
# End Source File
# Begin Source File

SOURCE=.\ClientWeaponBase.h
# End Source File
# Begin Source File

SOURCE=.\ClientWeaponMgr.h
# End Source File
# Begin Source File

SOURCE=.\ClientWeaponNone.h
# End Source File
# Begin Source File

SOURCE=.\ClientWeaponUtils.h
# End Source File
# Begin Source File

SOURCE=.\ClientWeaponUtils.h
# End Source File
# Begin Source File

SOURCE=.\CMoveMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\CRC32.h
# End Source File
# Begin Source File

SOURCE=.\Credits.h
# End Source File
# Begin Source File

SOURCE=.\CursorMgr.h
# End Source File
# Begin Source File

SOURCE=.\DamageFXMgr.h
# End Source File
# Begin Source File

SOURCE=.\DeathFX.h
# End Source File
# Begin Source File

SOURCE=.\DebrisFX.h
# End Source File
# Begin Source File

SOURCE=.\DebugLineFX.h
# End Source File
# Begin Source File

SOURCE=.\DoomsdayPieceFX.h
# End Source File
# Begin Source File

SOURCE=.\DynamicLightFX.h
# End Source File
# Begin Source File

SOURCE=.\ExplosionFX.h
# End Source File
# Begin Source File

SOURCE=.\FastList.h
# End Source File
# Begin Source File

SOURCE=.\FireFX.h
# End Source File
# Begin Source File

SOURCE=.\FlashLight.h
# End Source File
# Begin Source File

SOURCE=.\FullScreenTint.h
# End Source File
# Begin Source File

SOURCE=.\GadgetDisabler.h
# End Source File
# Begin Source File

SOURCE=.\GadgetTargetFX.h
# End Source File
# Begin Source File

SOURCE=.\GameButes.h
# End Source File
# Begin Source File

SOURCE=.\GameClientShell.h
# End Source File
# Begin Source File

SOURCE=.\GameSettings.h
# End Source File
# Begin Source File

SOURCE=.\GibFX.h
# End Source File
# Begin Source File

SOURCE=.\GlobalClientMgr.h
# End Source File
# Begin Source File

SOURCE=.\HeadBobMgr.h
# End Source File
# Begin Source File

SOURCE=.\HitBox.h
# End Source File
# Begin Source File

SOURCE=.\HUDBar.h
# End Source File
# Begin Source File

SOURCE=.\HUDChatInput.h
# End Source File
# Begin Source File

SOURCE=.\HUDDamage.h
# End Source File
# Begin Source File

SOURCE=.\HUDDecision.h
# End Source File
# Begin Source File

SOURCE=.\HUDDisplayMeter.h
# End Source File
# Begin Source File

SOURCE=.\HUDDistance.h
# End Source File
# Begin Source File

SOURCE=..\TO2\HUDHealth.h
# End Source File
# Begin Source File

SOURCE=.\HUDItem.h
# End Source File
# Begin Source File

SOURCE=.\HUDMessage.h
# End Source File
# Begin Source File

SOURCE=.\HUDMessageQueue.h
# End Source File
# Begin Source File

SOURCE=.\HUDMeter.h
# End Source File
# Begin Source File

SOURCE=.\HUDMgr.h
# End Source File
# Begin Source File

SOURCE=.\HUDMissionText.h
# End Source File
# Begin Source File

SOURCE=.\HUDPaused.h
# End Source File
# Begin Source File

SOURCE=.\HUDPopup.h
# End Source File
# Begin Source File

SOURCE=.\HUDRadar.h
# End Source File
# Begin Source File

SOURCE=.\HUDScores.h
# End Source File
# Begin Source File

SOURCE=.\HUDSubtitles.h
# End Source File
# Begin Source File

SOURCE=.\HUDTransmission.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltbaseclass.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ImpactType.h
# End Source File
# Begin Source File

SOURCE=.\IntelItemList.h
# End Source File
# Begin Source File

SOURCE=.\InterfaceMgr.h
# End Source File
# Begin Source File

SOURCE=.\InterfaceResMgr.h
# End Source File
# Begin Source File

SOURCE=.\InterfaceSurfMgr.h
# End Source File
# Begin Source File

SOURCE=.\InterfaceTimer.h
# End Source File
# Begin Source File

SOURCE=.\IpMgr.h
# End Source File
# Begin Source File

SOURCE=.\JumpVolumeFX.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\KeyMgr.h
# End Source File
# Begin Source File

SOURCE=.\LaserBeam.h
# End Source File
# Begin Source File

SOURCE=.\LaserTriggerFX.h
# End Source File
# Begin Source File

SOURCE=.\LayoutMgr.h
# End Source File
# Begin Source File

SOURCE=.\LeanMgr.h
# End Source File
# Begin Source File

SOURCE=.\LensFlareFX.h
# End Source File
# Begin Source File

SOURCE=.\LightFX.h
# End Source File
# Begin Source File

SOURCE=.\LightGroupFX.h
# End Source File
# Begin Source File

SOURCE=.\LightningFX.h
# End Source File
# Begin Source File

SOURCE=.\LightScaleMgr.h
# End Source File
# Begin Source File

SOURCE=.\LineSystemFX.h
# End Source File
# Begin Source File

SOURCE=.\LoadingScreen.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\LTEulerAngles.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltmodule.h
# End Source File
# Begin Source File

SOURCE=.\MarkSFX.h
# End Source File
# Begin Source File

SOURCE=.\MenuEnum.h
# End Source File
# Begin Source File

SOURCE=.\MenuIntel.h
# End Source File
# Begin Source File

SOURCE=.\MenuInventory.h
# End Source File
# Begin Source File

SOURCE=.\MenuKeys.h
# End Source File
# Begin Source File

SOURCE=.\MenuMgr.h
# End Source File
# Begin Source File

SOURCE=.\MenuMission.h
# End Source File
# Begin Source File

SOURCE=.\MenuPlayer.h
# End Source File
# Begin Source File

SOURCE=.\MenuSystem.h
# End Source File
# Begin Source File

SOURCE=.\MessageBox.h
# End Source File
# Begin Source File

SOURCE=.\MineFX.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\MissionButeMgr.h
# End Source File
# Begin Source File

SOURCE=.\MissionMgr.h
# End Source File
# Begin Source File

SOURCE=.\Music.h
# End Source File
# Begin Source File

SOURCE=.\MuzzleFlashFX.h
# End Source File
# Begin Source File

SOURCE=.\MuzzleFlashParticleFX.h
# End Source File
# Begin Source File

SOURCE=.\NodeController.h
# End Source File
# Begin Source File

SOURCE=.\NodeLinesFX.h
# End Source File
# Begin Source File

SOURCE=.\ObjectiveControl.h
# End Source File
# Begin Source File

SOURCE=.\ObjSpriteFX.h
# End Source File
# Begin Source File

SOURCE=.\Overlays.h
# End Source File
# Begin Source File

SOURCE=.\ParticleExplosionFX.h
# End Source File
# Begin Source File

SOURCE=.\ParticleShowerFX.h
# End Source File
# Begin Source File

SOURCE=.\ParticleSystemFX.h
# End Source File
# Begin Source File

SOURCE=.\ParticleTrailFX.h
# End Source File
# Begin Source File

SOURCE=.\ParticleTrailSegmentFX.h
# End Source File
# Begin Source File

SOURCE=.\PerformanceEnum.h
# End Source File
# Begin Source File

SOURCE=.\PerformanceMgr.h
# End Source File
# Begin Source File

SOURCE=.\PerformanceTest.h
# End Source File
# Begin Source File

SOURCE=.\PickupItemFX.h
# End Source File
# Begin Source File

SOURCE=.\plasma.h
# End Source File
# Begin Source File

SOURCE=.\PlayerCamera.h
# End Source File
# Begin Source File

SOURCE=.\PlayerLureFX.h
# End Source File
# Begin Source File

SOURCE=.\PlayerMgr.h
# End Source File
# Begin Source File

SOURCE=.\PlayerSoundFX.h
# End Source File
# Begin Source File

SOURCE=.\PlayerStats.h
# End Source File
# Begin Source File

SOURCE=.\PlayerVehicleFX.h
# End Source File
# Begin Source File

SOURCE=.\PlayerViewAttachmentMgr.h
# End Source File
# Begin Source File

SOURCE=.\PolyDebrisFX.h
# End Source File
# Begin Source File

SOURCE=.\PolyGridFX.h
# End Source File
# Begin Source File

SOURCE=.\PolyLineFX.h
# End Source File
# Begin Source File

SOURCE=.\PopupMgr.h
# End Source File
# Begin Source File

SOURCE=.\PopupText.h
# End Source File
# Begin Source File

SOURCE=.\ProfileMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ProfileUtils.h
# End Source File
# Begin Source File

SOURCE=.\ProjectileFX.h
# End Source File
# Begin Source File

SOURCE=.\PVFXMgr.h
# End Source File
# Begin Source File

SOURCE=.\RadarObjectFX.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\RadarTypeMgr.h
# End Source File
# Begin Source File

SOURCE=.\RagDoll.h
# End Source File
# Begin Source File

SOURCE=.\RagDollConstraint.h
# End Source File
# Begin Source File

SOURCE=.\RagDollNode.h
# End Source File
# Begin Source File

SOURCE=.\RandomSparksFX.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SaveLoadMgr.h
# End Source File
# Begin Source File

SOURCE=.\ScatterFX.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ScmdConsole.h
# End Source File
# Begin Source File

SOURCE=.\ScmdConsoleDriver_CShell.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ScmdShared.h
# End Source File
# Begin Source File

SOURCE=.\ScreenCommands.h
# End Source File
# Begin Source File

SOURCE=.\ScreenEnum.h
# End Source File
# Begin Source File

SOURCE=.\ScreenMgr.h
# End Source File
# Begin Source File

SOURCE=.\ScreenPostload.h
# End Source File
# Begin Source File

SOURCE=.\ScreenPreload.h
# End Source File
# Begin Source File

SOURCE=.\ScreenSpriteMgr.h
# End Source File
# Begin Source File

SOURCE=.\ScreenTintMgr.h
# End Source File
# Begin Source File

SOURCE=.\Searcher.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SearchItemMgr.h
# End Source File
# Begin Source File

SOURCE=.\SearchLightFX.h
# End Source File
# Begin Source File

SOURCE=.\SFXMgr.h
# End Source File
# Begin Source File

SOURCE=.\SharedDefs.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SharedMission.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SharedScoring.h
# End Source File
# Begin Source File

SOURCE=.\ShellCasingFX.h
# End Source File
# Begin Source File

SOURCE=.\SkillControl.h
# End Source File
# Begin Source File

SOURCE=.\SmokeFX.h
# End Source File
# Begin Source File

SOURCE=.\SnowFX.h
# End Source File
# Begin Source File

SOURCE=.\SoundFX.h
# End Source File
# Begin Source File

SOURCE=.\Sparam.h
# End Source File
# Begin Source File

SOURCE=.\SpecialFX.h
# End Source File
# Begin Source File

SOURCE=.\SpecialFXList.h
# End Source File
# Begin Source File

SOURCE=.\sprinklesfx.h
# End Source File
# Begin Source File

SOURCE=.\stack.h
# End Source File
# Begin Source File

SOURCE=.\StandardCreator.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SteamFX.h
# End Source File
# Begin Source File

SOURCE=.\SystemDependant.h
# End Source File
# Begin Source File

SOURCE=.\TargetMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TeamMgr.h
# End Source File
# Begin Source File

SOURCE=.\TextureFXMgr.h
# End Source File
# Begin Source File

SOURCE=.\TimedText.h
# End Source File
# Begin Source File

SOURCE=.\TracerFX.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TrackedNodeContext.h
# End Source File
# Begin Source File

SOURCE=.\TriggerFX.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TriggerTypeMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\UberAssert.h
# End Source File
# Begin Source File

SOURCE=.\VarTrack.h
# End Source File
# Begin Source File

SOURCE=.\VehicleMgr.h
# End Source File
# Begin Source File

SOURCE=.\VisionModeMgr.h
# End Source File
# Begin Source File

SOURCE=.\VKDefs.h
# End Source File
# Begin Source File

SOURCE=.\VolumeBrushFX.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\WaveFn.h
# End Source File
# Begin Source File

SOURCE=.\WeaponChooser.h
# End Source File
# Begin Source File

SOURCE=.\WeaponFX.h
# End Source File
# Begin Source File

SOURCE=.\WeaponStringDefs.h
# End Source File
# Begin Source File

SOURCE=.\WeatherFX.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\WinUtil.h
# End Source File
# End Group
# End Target
# End Project
