# Microsoft Developer Studio Project File - Name="ObjectShared" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=ObjectShared - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ObjectShared.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ObjectShared.mak" CFG="ObjectShared - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ObjectShared - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ObjectShared - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "ObjectShared - Win32 Final" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "ObjectShared"
# PROP Scc_LocalPath "..\..\.."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ObjectShared - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Built\Release\ObjectDll\ObjectShared"
# PROP Intermediate_Dir "..\..\Built\Release\ObjectDll\ObjectShared"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\..\libs\regmgr" /I "..\..\libs" /I "..\..\libs\serverdir" /D "NDEBUG" /D "_LIB" /D "_NOLFBUILD" /D "USE_INTEL_COMPILER" /D "WIN32" /D "_WINDOWS" /D "NOPS2" /D "_SERVERBUILD" /D "_NO_AI_ASSERT" /D "MEMTRACK_SERVER" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "ObjectShared - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\Built\Debug\ObjectDll\ObjectShared"
# PROP Intermediate_Dir "..\..\Built\Debug\ObjectDll\ObjectShared"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I ".\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\..\libs\regmgr" /I "..\..\libs" /I "..\..\libs\serverdir" /D "_DEBUG" /D "_LIB" /D "WIN32" /D "_WINDOWS" /D "NOPS2" /D "_SERVERBUILD" /D "_NO_AI_ASSERT" /D "MEMTRACK_SERVER" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "ObjectShared - Win32 Final"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Final"
# PROP BASE Intermediate_Dir "Final"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Built\Final\ObjectDll\ObjectShared"
# PROP Intermediate_Dir "..\..\Built\Final\ObjectDll\ObjectShared"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\..\libs\regmgr" /I "..\..\libs" /I "..\..\libs\serverdir" /D "NDEBUG" /D "_LIB" /D "_NOLFBUILD" /D "USE_INTEL_COMPILER" /D "WIN32" /D "_WINDOWS" /D "NOPS2" /D "_SERVERBUILD" /D "_NO_AI_ASSERT" /D "_FINAL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I ".\\" /I "..\..\..\libs\STLPORT-4.0\STLPORT" /I "..\..\shared" /I "..\..\..\Engine\sdk\inc" /I "..\..\..\libs\stdlith" /I "..\..\..\libs\butemgr" /I "..\..\..\libs\cryptmgr" /I "..\..\..\libs\lith" /I "..\..\..\libs\mfcstub" /I "..\..\..\libs\regmgr" /I "..\..\libs" /I "..\..\libs\serverdir" /D "NDEBUG" /D "_LIB" /D "_NOLFBUILD" /D "USE_INTEL_COMPILER" /D "WIN32" /D "_WINDOWS" /D "NOPS2" /D "_SERVERBUILD" /D "_NO_AI_ASSERT" /D "_FINAL" /D "MEMTRACK_SERVER" /Yu"stdafx.h" /FD /c
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

# Name "ObjectShared - Win32 Release"
# Name "ObjectShared - Win32 Debug"
# Name "ObjectShared - Win32 Final"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\Shared\ActivateTypeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ActiveWorldModel.cpp
# End Source File
# Begin Source File

SOURCE=.\AI.cpp
# End Source File
# Begin Source File

SOURCE=.\AIAssert.cpp
# End Source File
# Begin Source File

SOURCE=.\AIBrain.cpp
# End Source File
# Begin Source File

SOURCE=.\AIButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\AICentralKnowledgeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\AIClassFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAbstract.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAbstractSearch.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAbstractStimulated.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAbstractTargeted.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAbstractUseObject.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAlarm.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAnimate.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalApprehend.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAssassinate.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttack.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackFromCover.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackfromRandomVantage.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackfromRoofVantage.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackfromVantage.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackFromView.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackMelee.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackProne.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackProp.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackRanged.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackRangedDynamic.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalCatch.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalCharge.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalChase.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalCheckBody.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalCover.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalDeflect.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalDisappearReappear.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalDisappearReappearEvasive.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalDistress.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalDramaDeath.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalDrawWeapon.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalExitLevel.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalFlee.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalFollow.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalFollowFootprint.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalGetBackup.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalGoto.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalGuard.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalHolsterWeapon.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalInvestigate.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalLoveKitty.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalLunge.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalMenace.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalMountedFlashlight.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalObstruct.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalPatrol.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalProximityCommand.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalPsychoChase.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalReclassifyToEnemy.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalRespondToAlarm.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalRespondToBackup.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalResurrecting.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalRetreat.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalSearch.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalSentryChallenge.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalSentryMark.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalSerumDeath.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalSleep.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalSniper.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalSpecialDamage.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalTail.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalTalk.cpp
# End Source File
# Begin Source File

SOURCE=.\AIGoalWork.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHuman.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanState.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateApprehend.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateAttackMove.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateAttackProne.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateCatch.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateDeflect.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateDisappearReappear.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateLaunch.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateObstruct.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateResurrecting.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateSentryChallenge.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateSniper.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanStrategyShootStream.cpp
# End Source File
# Begin Source File

SOURCE=.\AIHumanStrategyToggleLights.cpp
# End Source File
# Begin Source File

SOURCE=.\AIInformationVolumeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\AIMovement.cpp
# End Source File
# Begin Source File

SOURCE=.\AIMovementModifier.cpp
# End Source File
# Begin Source File

SOURCE=.\AINode.cpp
# End Source File
# Begin Source File

SOURCE=.\AINodeDisturbance.cpp
# End Source File
# Begin Source File

SOURCE=.\AINodeGuard.cpp
# End Source File
# Begin Source File

SOURCE=.\AINodeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\AINodeSensing.cpp
# End Source File
# Begin Source File

SOURCE=.\AIPath.cpp
# End Source File
# Begin Source File

SOURCE=.\AIPathKnowledgeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\AIPathMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\AIRegion.cpp
# End Source File
# Begin Source File

SOURCE=.\AIRegionMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\AISenseRecorderAbstract.cpp
# End Source File
# Begin Source File

SOURCE=.\AISenseRecorderGame.cpp
# End Source File
# Begin Source File

SOURCE=.\AISounds.cpp
# End Source File
# Begin Source File

SOURCE=.\AISpatialRepresentationMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\AIState.cpp
# End Source File
# Begin Source File

SOURCE=.\AIStimulusMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\AITarget.cpp
# End Source File
# Begin Source File

SOURCE=.\AITypes.cpp
# End Source File
# Begin Source File

SOURCE=.\AIUtils.cpp
# End Source File
# Begin Source File

SOURCE=.\AIVolume.cpp
# End Source File
# Begin Source File

SOURCE=.\AIVolumeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\AIVolumeNeighbor.cpp
# End Source File
# Begin Source File

SOURCE=.\Alarm.cpp
# End Source File
# Begin Source File

SOURCE=.\AmmoBox.cpp
# End Source File
# Begin Source File

SOURCE=.\AnimationLex.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\AnimationLex.l

!IF  "$(CFG)" == "ObjectShared - Win32 Release"

# PROP Ignore_Default_Tool 1
USERDEP__ANIMA="AnimationParse.y"	"AnimationLexSymbols.h"	
# Begin Custom Build
InputPath=.\AnimationLex.l

"AnimationLex.o" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	..\..\flex -Pyyanimation -oAnimationLex.o AnimationLex.l

# End Custom Build

!ELSEIF  "$(CFG)" == "ObjectShared - Win32 Debug"

# PROP Ignore_Default_Tool 1
USERDEP__ANIMA="AnimationParse.y"	"AnimationLexSymbols.h"	
# Begin Custom Build
InputPath=.\AnimationLex.l

"AnimationLex.o" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	..\..\flex -Pyyanimation -oAnimationLex.o AnimationLex.l

# End Custom Build

!ELSEIF  "$(CFG)" == "ObjectShared - Win32 Final"

# PROP Ignore_Default_Tool 1
USERDEP__ANIMA="AnimationParse.y"	"AnimationLexSymbols.h"	
# Begin Custom Build
InputPath=.\AnimationLex.l

"AnimationLex.o" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	..\..\flex -Pyyanimation -oAnimationLex.o AnimationLex.l

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AnimationMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\AnimationParse.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\AnimationParse.y

!IF  "$(CFG)" == "ObjectShared - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build
InputPath=.\AnimationParse.y

BuildCmds= \
	..\..\bison --defines -v --verbose -pyyanimation -oAnimationParse.o AnimationParse.y \
	if exist AnimationLexSymbols.h del AnimationLexSymbols.h \
	ren AnimationParse.o.h AnimationLexSymbols.h \
	ren AnimationParse.o AnimationParse.o \
	del AnimationParse.o.output \
	

"AnimationParse.o" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"AnimationLexSymbols.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "ObjectShared - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build
InputPath=.\AnimationParse.y

BuildCmds= \
	..\..\bison --defines -v --verbose -pyyanimation -oAnimationParse.o AnimationParse.y \
	if exist AnimationLexSymbols.h del AnimationLexSymbols.h \
	ren AnimationParse.o.h AnimationLexSymbols.h \
	ren AnimationParse.o AnimationParse.o \
	del AnimationParse.o.output \
	

"AnimationParse.o" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"AnimationLexSymbols.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "ObjectShared - Win32 Final"

# PROP Ignore_Default_Tool 1
# Begin Custom Build
InputPath=.\AnimationParse.y

BuildCmds= \
	..\..\bison --defines -v --verbose -pyyanimation -oAnimationParse.o AnimationParse.y \
	if exist AnimationLexSymbols.h del AnimationLexSymbols.h \
	ren AnimationParse.o.h AnimationLexSymbols.h \
	ren AnimationParse.o AnimationParse.o \
	del AnimationParse.o.output \
	

"AnimationParse.o" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"AnimationLexSymbols.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AnimationParser.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\Animator.cpp
# End Source File
# Begin Source File

SOURCE=.\AnimatorPlayer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\AssertMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\AttachButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\Attachments.cpp
# End Source File
# Begin Source File

SOURCE=.\BanIPMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\Body.cpp
# End Source File
# Begin Source File

SOURCE=.\BodyState.cpp
# End Source File
# Begin Source File

SOURCE=.\Bombable.cpp
# End Source File
# Begin Source File

SOURCE=.\Breakable.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ButeListReader.cpp
# End Source File
# Begin Source File

SOURCE=.\ButeTools.cpp
# End Source File
# Begin Source File

SOURCE=.\Camera.cpp
# End Source File
# Begin Source File

SOURCE=.\Character.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\CharacterAlignment.cpp
# End Source File
# Begin Source File

SOURCE=.\CharacterHitBox.cpp
# End Source File
# Begin Source File

SOURCE=.\CharacterMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientLightFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ClientServerShared.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientSFX.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientWeaponSFX.cpp
# End Source File
# Begin Source File

SOURCE=.\CollectiveRelationMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\CommandButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\CommandMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\CommandObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\CommonUtilities.cpp
# End Source File
# Begin Source File

SOURCE=.\Controller.cpp
# End Source File
# Begin Source File

SOURCE=.\CoopMissionMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\CRC32.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\DamageTypes.cpp
# End Source File
# Begin Source File

SOURCE=.\DeathMatchMissionMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\DeathScene.cpp
# End Source File
# Begin Source File

SOURCE=.\DebrisFuncs.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\DebrisMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\DebugLine.cpp
# End Source File
# Begin Source File

SOURCE=.\DebugLineSystem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\DebugNew.cpp
# End Source File
# Begin Source File

SOURCE=.\DecisionObject.cpp
# End Source File
# Begin Source File

SOURCE=.\Destructible.cpp
# End Source File
# Begin Source File

SOURCE=.\DestructibleModel.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialogue.cpp
# End Source File
# Begin Source File

SOURCE=.\DisplayMeter.cpp
# End Source File
# Begin Source File

SOURCE=.\DisplayTimer.cpp
# End Source File
# Begin Source File

SOURCE=.\DoomsDayDevice.cpp
# End Source File
# Begin Source File

SOURCE=.\DoomsDayMissionMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\DoomsDayPiece.cpp
# End Source File
# Begin Source File

SOURCE=.\Door.cpp
# End Source File
# Begin Source File

SOURCE=.\DoorKnob.cpp
# End Source File
# Begin Source File

SOURCE=.\DynamicOccluderVolume.cpp
# End Source File
# Begin Source File

SOURCE=.\Editable.cpp
# End Source File
# Begin Source File

SOURCE=.\EventCounter.cpp
# End Source File
# Begin Source File

SOURCE=.\ExitTrigger.cpp
# End Source File
# Begin Source File

SOURCE=.\Explosion.cpp
# End Source File
# Begin Source File

SOURCE=.\Fire.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\FXButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\FXStructs.cpp
# End Source File
# Begin Source File

SOURCE=.\GadgetTarget.cpp
# End Source File
# Begin Source File

SOURCE=.\GadgetTargetMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\GameAlloc.cpp
# End Source File
# Begin Source File

SOURCE=.\GameBase.cpp
# End Source File
# Begin Source File

SOURCE=.\GameBaseLite.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\GameButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\GameServerShell.cpp
# End Source File
# Begin Source File

SOURCE=.\GameStartPoint.cpp
# End Source File
# Begin Source File

SOURCE=.\GearItems.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\GlobalMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\GlobalServerMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\Group.cpp
# End Source File
# Begin Source File

SOURCE=.\HHWeaponModel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltbaseclass.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\Intelligence.cpp
# End Source File
# Begin Source File

SOURCE=.\IntelMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\InventoryButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\JumpVolume.cpp
# End Source File
# Begin Source File

SOURCE=.\Key.cpp
# End Source File
# Begin Source File

SOURCE=.\KeyData.cpp
# End Source File
# Begin Source File

SOURCE=.\KeyFramer.cpp
# End Source File
# Begin Source File

SOURCE=.\KeyItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\KeyMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\KeyPad.cpp
# End Source File
# Begin Source File

SOURCE=.\LaserTrigger.cpp
# End Source File
# Begin Source File

SOURCE=.\LightGroup.cpp
# End Source File
# Begin Source File

SOURCE=.\Lightning.cpp
# End Source File
# Begin Source File

SOURCE=.\LiteObjectMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\Lock.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltengineobjects.cpp
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

SOURCE=.\Mine.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\MissionButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ModelButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ModItem.cpp
# End Source File
# Begin Source File

SOURCE=.\MusicMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\NetDefs.cpp
# End Source File
# Begin Source File

SOURCE=.\NodeLine.cpp
# End Source File
# Begin Source File

SOURCE=.\NoPlayerTrigger.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjectiveSprite.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjectRelationMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjectRemover.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjectTemplateMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ParsedMsg.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticleSystem.cpp
# End Source File
# Begin Source File

SOURCE=.\PickupItem.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerLure.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerObj.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerTracker.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerTrigger.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerVehicle.cpp
# End Source File
# Begin Source File

SOURCE=.\Point.cpp
# End Source File
# Begin Source File

SOURCE=.\PolyGrid.cpp
# End Source File
# Begin Source File

SOURCE=.\PolyGridModifier.cpp
# End Source File
# Begin Source File

SOURCE=.\PowerArmor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ProfileUtils.cpp
# End Source File
# Begin Source File

SOURCE=.\Projectile.cpp
# End Source File
# Begin Source File

SOURCE=.\ProjectileTypes.cpp
# End Source File
# Begin Source File

SOURCE=.\Prop.cpp
# End Source File
# Begin Source File

SOURCE=.\PropType.cpp
# End Source File
# Begin Source File

SOURCE=.\PropTypeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\RadarObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\RadarTypeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\RandomSpawner.cpp
# End Source File
# Begin Source File

SOURCE=.\RelationButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\RelationMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\RotatingDoor.cpp
# End Source File
# Begin Source File

SOURCE=.\RotatingSwitch.cpp
# End Source File
# Begin Source File

SOURCE=.\RotatingWorldModel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SaveLoadMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ScaleSprite.cpp
# End Source File
# Begin Source File

SOURCE=.\Scanner.cpp
# End Source File
# Begin Source File

SOURCE=.\ScatterVolume.cpp
# End Source File
# Begin Source File

SOURCE=.\ScmdServer.cpp
# End Source File
# Begin Source File

SOURCE=.\ScreenShake.cpp
# End Source File
# Begin Source File

SOURCE=.\Searchable.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SearchItemMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\SearchLight.cpp
# End Source File
# Begin Source File

SOURCE=.\SearchProp.cpp
# End Source File
# Begin Source File

SOURCE=.\SecurityCamera.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerAssetMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerMark.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerMissionMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerSaveLoadMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerSoundFX.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerSoundMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerSpecialFX.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerTrackedNodeContext.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerTrackedNodeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\ServerUtilities.cpp
# End Source File
# Begin Source File

SOURCE=.\SFXFuncs.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SharedFXStructs.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SharedMission.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SharedMovement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SharedScoring.cpp
# End Source File
# Begin Source File

SOURCE=.\SinglePlayerMissionMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\Skills.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SkillsButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\SlidingDoor.cpp
# End Source File
# Begin Source File

SOURCE=.\SlidingSwitch.cpp
# End Source File
# Begin Source File

SOURCE=.\SlidingWorldModel.cpp
# End Source File
# Begin Source File

SOURCE=.\SnowVolume.cpp
# End Source File
# Begin Source File

SOURCE=.\SoundButeFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SoundButeMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SoundFilterMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SoundMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\Sparam.cpp
# End Source File
# Begin Source File

SOURCE=.\Spawner.cpp
# End Source File
# Begin Source File

SOURCE=.\Speaker.cpp
# End Source File
# Begin Source File

SOURCE=.\SpinningWorldModel.cpp
# End Source File
# Begin Source File

SOURCE=.\Sprinkles.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\stacktrace.cpp
# End Source File
# Begin Source File

SOURCE=.\StartupCommand.cpp
# End Source File
# Begin Source File

SOURCE=.\Stdafx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Steam.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SurfaceFunctions.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SurfaceMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\Switch.cpp
# End Source File
# Begin Source File

SOURCE=.\TeamDeathMatchMissionMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TeamMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\TeleportPoint.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TemplateList.cpp
# End Source File
# Begin Source File

SOURCE=.\TextureFX.cpp
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

SOURCE=.\TransitionAggregate.cpp
# End Source File
# Begin Source File

SOURCE=.\TransitionArea.cpp
# End Source File
# Begin Source File

SOURCE=.\TransitionMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\Trigger.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TriggerTypeMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\UberAssert.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\VersionMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\VolumeBrush.cpp
# End Source File
# Begin Source File

SOURCE=.\VolumeBrushTypes.cpp
# End Source File
# Begin Source File

SOURCE=.\VolumeEffect.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\WaveFn.cpp
# End Source File
# Begin Source File

SOURCE=.\Weapon.cpp
# End Source File
# Begin Source File

SOURCE=.\WeaponItems.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\WeaponMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\Weapons.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\WinUtil.cpp
# End Source File
# Begin Source File

SOURCE=.\WorldModel.cpp
# End Source File
# Begin Source File

SOURCE=.\WorldModelDebris.cpp
# End Source File
# Begin Source File

SOURCE=.\WorldProperties.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\Shared\ActivateTypeMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ActivationData.h
# End Source File
# Begin Source File

SOURCE=.\ActiveWorldModel.h
# End Source File
# Begin Source File

SOURCE=.\AI.h
# End Source File
# Begin Source File

SOURCE=.\AIAssert.h
# End Source File
# Begin Source File

SOURCE=.\AIBrain.h
# End Source File
# Begin Source File

SOURCE=.\AIButeMgr.h
# End Source File
# Begin Source File

SOURCE=.\AICentralKnowledgeMgr.h
# End Source File
# Begin Source File

SOURCE=.\AIClassFactory.h
# End Source File
# Begin Source File

SOURCE=.\AIDataTypeEnums.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAbstract.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAbstractSearch.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAbstractStimulated.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAbstractTargeted.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAbstractUseObject.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAlarm.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAnimate.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalApprehend.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAssassinate.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttack.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackFromCover.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackFromRandomVantage.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackFromRoofVantage.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackFromVantage.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackFromView.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackMelee.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackProne.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackProp.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackRanged.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalAttackRangedDynamic.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalButeMgr.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalCatch.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalCharge.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalChase.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalCheckBody.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalCover.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalDeflect.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalDisappearReappear.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalDisappearReappearEvasive.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalDistress.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalDramaDeath.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalDrawWeapon.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalExitLevel.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalFlee.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalFollow.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalFollowFootprint.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalGetBackup.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalGoto.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalGuard.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalHolsterWeapon.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalInvestigate.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalLoveKitty.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalLunge.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalMenace.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalMgr.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalMountedFlashlight.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalObstruct.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalPatrol.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalProximityCommand.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalPsychoChase.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalReclassifyToEnemy.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalRespondToAlarm.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalRespondToBackup.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalResurrecting.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalRetreat.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalSearch.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalSentryChallenge.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalSentryMark.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalSerumDeath.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalSleep.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalSniper.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalSpecialDamage.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalTail.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalTalk.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalTypeEnums.h
# End Source File
# Begin Source File

SOURCE=.\AIGoalWork.h
# End Source File
# Begin Source File

SOURCE=.\AIHuman.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanState.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateApprehend.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateAttackMove.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateAttackProne.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateCatch.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateDeflect.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateDisappearReappear.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateLaunch.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateObstruct.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateResurrecting.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateSentryChallenge.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanStateSniper.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanStrategy.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanStrategyShootStream.h
# End Source File
# Begin Source File

SOURCE=.\AIHumanStrategyToggleLights.h
# End Source File
# Begin Source File

SOURCE=.\AIInformationVolumeMgr.h
# End Source File
# Begin Source File

SOURCE=.\AIMovement.h
# End Source File
# Begin Source File

SOURCE=.\AIMovementModifier.h
# End Source File
# Begin Source File

SOURCE=.\AINode.h
# End Source File
# Begin Source File

SOURCE=.\AINodeDisturbance.h
# End Source File
# Begin Source File

SOURCE=.\AINodeGuard.h
# End Source File
# Begin Source File

SOURCE=.\AINodeMgr.h
# End Source File
# Begin Source File

SOURCE=.\AINodeSensing.h
# End Source File
# Begin Source File

SOURCE=.\AINodeTypeEnums.h
# End Source File
# Begin Source File

SOURCE=.\AIPath.h
# End Source File
# Begin Source File

SOURCE=.\AIPathKnowledgeMgr.h
# End Source File
# Begin Source File

SOURCE=.\AIPathMgr.h
# End Source File
# Begin Source File

SOURCE=.\AIRegion.h
# End Source File
# Begin Source File

SOURCE=.\AIRegionMgr.h
# End Source File
# Begin Source File

SOURCE=.\AISenseRecorderAbstract.h
# End Source File
# Begin Source File

SOURCE=.\AISenseRecorderGame.h
# End Source File
# Begin Source File

SOURCE=.\AISenseTypeEnums.h
# End Source File
# Begin Source File

SOURCE=.\AISensing.h
# End Source File
# Begin Source File

SOURCE=.\AISounds.h
# End Source File
# Begin Source File

SOURCE=.\AISoundTypeEnums.h
# End Source File
# Begin Source File

SOURCE=.\AISpatialRepresentationMgr.h
# End Source File
# Begin Source File

SOURCE=.\AIState.h
# End Source File
# Begin Source File

SOURCE=.\AIStateTypeEnums.h
# End Source File
# Begin Source File

SOURCE=.\AIStimulusMgr.h
# End Source File
# Begin Source File

SOURCE=.\AIStimulusTypeEnums.h
# End Source File
# Begin Source File

SOURCE=.\AIStrategy.h
# End Source File
# Begin Source File

SOURCE=.\AIStrategyTypeEnums.h
# End Source File
# Begin Source File

SOURCE=.\AITarget.h
# End Source File
# Begin Source File

SOURCE=.\AITypes.h
# End Source File
# Begin Source File

SOURCE=.\AIUtils.h
# End Source File
# Begin Source File

SOURCE=.\AIVolume.h
# End Source File
# Begin Source File

SOURCE=.\AIVolumeMgr.h
# End Source File
# Begin Source File

SOURCE=.\AIVolumeNeighbor.h
# End Source File
# Begin Source File

SOURCE=.\AIVolumeTypeEnums.h
# End Source File
# Begin Source File

SOURCE=.\Alarm.h
# End Source File
# Begin Source File

SOURCE=.\Alarm.h
# End Source File
# Begin Source File

SOURCE=.\AmmoBox.h
# End Source File
# Begin Source File

SOURCE=.\AnimationLex.h
# End Source File
# Begin Source File

SOURCE=.\AnimationMgr.h
# End Source File
# Begin Source File

SOURCE=.\AnimationMovement.h
# End Source File
# Begin Source File

SOURCE=.\AnimationMovementEnums.h
# End Source File
# Begin Source File

SOURCE=.\AnimationParse.h
# End Source File
# Begin Source File

SOURCE=.\AnimationParser.h
# End Source File
# Begin Source File

SOURCE=.\AnimationProp.h
# End Source File
# Begin Source File

SOURCE=.\AnimationPropEnums.h
# End Source File
# Begin Source File

SOURCE=.\AnimationPropGroupEnums.h
# End Source File
# Begin Source File

SOURCE=.\AnimationPropStrings.h
# End Source File
# Begin Source File

SOURCE=.\AnimationStd.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\Animator.h
# End Source File
# Begin Source File

SOURCE=.\AnimatorPlayer.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\AssertMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\AttachButeMgr.h
# End Source File
# Begin Source File

SOURCE=.\Attachments.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\AutoMessage.h
# End Source File
# Begin Source File

SOURCE=.\BanIPMgr.h
# End Source File
# Begin Source File

SOURCE=.\Body.h
# End Source File
# Begin Source File

SOURCE=.\BodyState.h
# End Source File
# Begin Source File

SOURCE=.\Bombable.h
# End Source File
# Begin Source File

SOURCE=.\Bouncer.h
# End Source File
# Begin Source File

SOURCE=.\Breakable.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ButeListReader.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ButeListReader.h
# End Source File
# Begin Source File

SOURCE=.\ButeTools.h
# End Source File
# Begin Source File

SOURCE=.\Camera.h
# End Source File
# Begin Source File

SOURCE=.\CDynArray.h
# End Source File
# Begin Source File

SOURCE=.\Character.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\CharacterAlignment.h
# End Source File
# Begin Source File

SOURCE=.\CharacterHitBox.h
# End Source File
# Begin Source File

SOURCE=.\CharacterMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\CheatDefs.h
# End Source File
# Begin Source File

SOURCE=.\ClientDeathSFX.h
# End Source File
# Begin Source File

SOURCE=.\ClientFX.h
# End Source File
# Begin Source File

SOURCE=.\ClientLightFX.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ClientServerShared.h
# End Source File
# Begin Source File

SOURCE=.\ClientSFX.h
# End Source File
# Begin Source File

SOURCE=.\ClientWeaponSFX.h
# End Source File
# Begin Source File

SOURCE=.\CollectiveRelationMgr.h
# End Source File
# Begin Source File

SOURCE=.\CommandButeMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\CommandIDs.h
# End Source File
# Begin Source File

SOURCE=.\CommandMgr.h
# End Source File
# Begin Source File

SOURCE=.\CommandObject.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\CommonUtilities.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ContainerCodes.h
# End Source File
# Begin Source File

SOURCE=.\Controller.h
# End Source File
# Begin Source File

SOURCE=.\CoopMissionMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\CRC32.h
# End Source File
# Begin Source File

SOURCE=.\CVarTrack.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\DamageTypes.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\DamageTypesEnum.h
# End Source File
# Begin Source File

SOURCE=.\DeathMatchMissionMgr.h
# End Source File
# Begin Source File

SOURCE=.\DeathScene.h
# End Source File
# Begin Source File

SOURCE=.\DebrisFuncs.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\DebrisMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\DebrisTypes.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\DebugLine.h
# End Source File
# Begin Source File

SOURCE=.\DebugLineSystem.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\DebugMgr.h
# End Source File
# Begin Source File

SOURCE=.\DecisionObject.h
# End Source File
# Begin Source File

SOURCE=.\DEditColors.h
# End Source File
# Begin Source File

SOURCE=.\Destructible.h
# End Source File
# Begin Source File

SOURCE=.\DestructibleModel.h
# End Source File
# Begin Source File

SOURCE=.\Dialogue.h
# End Source File
# Begin Source File

SOURCE=.\DisplayMeter.h
# End Source File
# Begin Source File

SOURCE=.\DisplayTimer.h
# End Source File
# Begin Source File

SOURCE=.\DoomsDayDevice.h
# End Source File
# Begin Source File

SOURCE=.\DoomsDayMissionMgr.h
# End Source File
# Begin Source File

SOURCE=.\DoomsDayPiece.h
# End Source File
# Begin Source File

SOURCE=.\Door.h
# End Source File
# Begin Source File

SOURCE=.\DoorKnob.h
# End Source File
# Begin Source File

SOURCE=.\Editable.h
# End Source File
# Begin Source File

SOURCE=.\EventCounter.h
# End Source File
# Begin Source File

SOURCE=.\ExitTrigger.h
# End Source File
# Begin Source File

SOURCE=.\Explosion.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\FastHeap.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\FastStack.h
# End Source File
# Begin Source File

SOURCE=.\Fire.h
# End Source File
# Begin Source File

SOURCE=.\Fixture.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\FXButeMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\FxDefs.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\FxFlags.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\FXStructs.h
# End Source File
# Begin Source File

SOURCE=.\GadgetTarget.h
# End Source File
# Begin Source File

SOURCE=.\GadgetTargetMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\GadgetTargetTypes.h
# End Source File
# Begin Source File

SOURCE=.\GameBase.h
# End Source File
# Begin Source File

SOURCE=.\GameBaseLite.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\GameButeMgr.h
# End Source File
# Begin Source File

SOURCE=.\GameServerShell.h
# End Source File
# Begin Source File

SOURCE=.\GameStartPoint.h
# End Source File
# Begin Source File

SOURCE=.\GearItems.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\GibTypes.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\GlobalMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\Globals.h
# End Source File
# Begin Source File

SOURCE=.\GlobalServerMgr.h
# End Source File
# Begin Source File

SOURCE=.\Group.h
# End Source File
# Begin Source File

SOURCE=.\HHWeaponModel.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\HierarchicalButeMgr.h
# End Source File
# Begin Source File

SOURCE=.\IHitBoxUser.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ImpactType.h
# End Source File
# Begin Source File

SOURCE=.\Intelligence.h
# End Source File
# Begin Source File

SOURCE=.\IntelMgr.h
# End Source File
# Begin Source File

SOURCE=.\InventoryButeMgr.h
# End Source File
# Begin Source File

SOURCE=.\Joint.h
# End Source File
# Begin Source File

SOURCE=.\JumpVolume.h
# End Source File
# Begin Source File

SOURCE=.\Key.h
# End Source File
# Begin Source File

SOURCE=.\KeyData.h
# End Source File
# Begin Source File

SOURCE=.\KeyFramer.h
# End Source File
# Begin Source File

SOURCE=.\KeyItem.h
# End Source File
# Begin Source File

SOURCE=.\KeyPad.h
# End Source File
# Begin Source File

SOURCE=.\LaserTrigger.h
# End Source File
# Begin Source File

SOURCE=.\LightGroup.h
# End Source File
# Begin Source File

SOURCE=.\Lightning.h
# End Source File
# Begin Source File

SOURCE=.\LiteObjectMgr.h
# End Source File
# Begin Source File

SOURCE=.\Lock.h
# End Source File
# Begin Source File

SOURCE=.\Mine.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ModelButeMgr.h
# End Source File
# Begin Source File

SOURCE=.\ModItem.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\MsgIDs.h
# End Source File
# Begin Source File

SOURCE=.\MusicMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\NetDefs.h
# End Source File
# Begin Source File

SOURCE=.\NodeLine.h
# End Source File
# Begin Source File

SOURCE=.\NoPlayerTrigger.h
# End Source File
# Begin Source File

SOURCE=.\ObjectiveSprite.h
# End Source File
# Begin Source File

SOURCE=.\ObjectMsgs.h
# End Source File
# Begin Source File

SOURCE=.\ObjectRelationMgr.h
# End Source File
# Begin Source File

SOURCE=.\ObjectRemover.h
# End Source File
# Begin Source File

SOURCE=.\ObjectTemplateMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ParsedMsg.h
# End Source File
# Begin Source File

SOURCE=.\ParticleSystem.h
# End Source File
# Begin Source File

SOURCE=.\PickupItem.h
# End Source File
# Begin Source File

SOURCE=.\PlayerButes.h
# End Source File
# Begin Source File

SOURCE=.\PlayerLure.h
# End Source File
# Begin Source File

SOURCE=.\PlayerObj.h
# End Source File
# Begin Source File

SOURCE=.\PlayerTracker.h
# End Source File
# Begin Source File

SOURCE=.\PlayerTrigger.h
# End Source File
# Begin Source File

SOURCE=.\PlayerVehicle.h
# End Source File
# Begin Source File

SOURCE=.\Point.h
# End Source File
# Begin Source File

SOURCE=.\PolyGrid.h
# End Source File
# Begin Source File

SOURCE=.\PowerArmor.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ProfileUtils.h
# End Source File
# Begin Source File

SOURCE=.\Projectile.h
# End Source File
# Begin Source File

SOURCE=.\ProjectileTypes.h
# End Source File
# Begin Source File

SOURCE=.\Prop.h
# End Source File
# Begin Source File

SOURCE=.\PropType.h
# End Source File
# Begin Source File

SOURCE=.\PropTypeMgr.h
# End Source File
# Begin Source File

SOURCE=.\RadarObject.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\RadarTypeMgr.h
# End Source File
# Begin Source File

SOURCE=.\RandomSpawner.h
# End Source File
# Begin Source File

SOURCE=.\RelationButeMgr.h
# End Source File
# Begin Source File

SOURCE=.\RelationChangeObserver.h
# End Source File
# Begin Source File

SOURCE=.\RelationMgr.h
# End Source File
# Begin Source File

SOURCE=.\RotatingDoor.h
# End Source File
# Begin Source File

SOURCE=.\RotatingSwitch.h
# End Source File
# Begin Source File

SOURCE=.\RotatingWorldModel.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SaveLoadMgr.h
# End Source File
# Begin Source File

SOURCE=.\ScaleSprite.h
# End Source File
# Begin Source File

SOURCE=.\Scanner.h
# End Source File
# Begin Source File

SOURCE=.\ScatterVolume.h
# End Source File
# Begin Source File

SOURCE=.\ScmdServer.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\ScmdShared.h
# End Source File
# Begin Source File

SOURCE=.\ScreenShake.h
# End Source File
# Begin Source File

SOURCE=.\Searchable.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SearchItemMgr.h
# End Source File
# Begin Source File

SOURCE=.\SearchLight.h
# End Source File
# Begin Source File

SOURCE=.\SearchProp.h
# End Source File
# Begin Source File

SOURCE=.\SecurityCamera.h
# End Source File
# Begin Source File

SOURCE=.\ServerAppHandler.h
# End Source File
# Begin Source File

SOURCE=.\ServerAssetMgr.h
# End Source File
# Begin Source File

SOURCE=.\ServerButeMgr.h
# End Source File
# Begin Source File

SOURCE=.\ServerMark.h
# End Source File
# Begin Source File

SOURCE=.\ServerMissionMgr.h
# End Source File
# Begin Source File

SOURCE=.\ServerMissionSettings.h
# End Source File
# Begin Source File

SOURCE=.\ServerSaveLoadMgr.h
# End Source File
# Begin Source File

SOURCE=.\ServerSoundFX.h
# End Source File
# Begin Source File

SOURCE=.\ServerSoundMgr.h
# End Source File
# Begin Source File

SOURCE=.\ServerSpecialFX.h
# End Source File
# Begin Source File

SOURCE=.\ServerTrackedNodeContext.h
# End Source File
# Begin Source File

SOURCE=.\ServerTrackedNodeMgr.h
# End Source File
# Begin Source File

SOURCE=.\ServerUtilities.h
# End Source File
# Begin Source File

SOURCE=.\SFXFuncs.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SFXMsgIds.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SharedBaseFXStructs.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SharedFXStructs.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SharedMission.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SharedMovement.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SharedScoring.h
# End Source File
# Begin Source File

SOURCE=.\SinglePlayerMissionMgr.h
# End Source File
# Begin Source File

SOURCE=.\Skills.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SkillsButeMgr.h
# End Source File
# Begin Source File

SOURCE=.\SlidingDoor.h
# End Source File
# Begin Source File

SOURCE=.\SlidingSwitch.h
# End Source File
# Begin Source File

SOURCE=.\SlidingWorldModel.h
# End Source File
# Begin Source File

SOURCE=.\SnowVolume.h
# End Source File
# Begin Source File

SOURCE=.\SoundButeFX.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SoundButeMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SoundFilterMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SoundMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SoundTypes.h
# End Source File
# Begin Source File

SOURCE=.\Sparam.h
# End Source File
# Begin Source File

SOURCE=.\Spawner.h
# End Source File
# Begin Source File

SOURCE=.\Speaker.h
# End Source File
# Begin Source File

SOURCE=.\SpinningWorldModel.h
# End Source File
# Begin Source File

SOURCE=.\Sprinkles.h
# End Source File
# Begin Source File

SOURCE=.\StartupCommand.h
# End Source File
# Begin Source File

SOURCE=.\Stdafx.h
# End Source File
# Begin Source File

SOURCE=.\Steam.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SurfaceFunctions.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\SurfaceMgr.h
# End Source File
# Begin Source File

SOURCE=.\Switch.h
# End Source File
# Begin Source File

SOURCE=.\TeamDeathMatchMissionMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TeamMgr.h
# End Source File
# Begin Source File

SOURCE=.\TeleportPoint.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TemplateList.h
# End Source File
# Begin Source File

SOURCE=.\TextureFX.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\Timer.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TrackedNode.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TrackedNodeMgr.h
# End Source File
# Begin Source File

SOURCE=.\TransitionAggregate.h
# End Source File
# Begin Source File

SOURCE=.\TransitionArea.h
# End Source File
# Begin Source File

SOURCE=.\TransitionMgr.h
# End Source File
# Begin Source File

SOURCE=.\Trigger.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\TriggerTypeMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\UberAssert.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\VersionMgr.h
# End Source File
# Begin Source File

SOURCE=.\VolumeBrush.h
# End Source File
# Begin Source File

SOURCE=.\VolumeBrushTypes.h
# End Source File
# Begin Source File

SOURCE=.\VolumeEffect.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\WaveFn.h
# End Source File
# Begin Source File

SOURCE=.\Weapon.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\WeaponFXTypes.h
# End Source File
# Begin Source File

SOURCE=.\WeaponItems.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\WeaponMgr.h
# End Source File
# Begin Source File

SOURCE=.\Weapons.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\WinUtil.h
# End Source File
# Begin Source File

SOURCE=.\WorldModel.h
# End Source File
# Begin Source File

SOURCE=.\WorldModelDebris.h
# End Source File
# Begin Source File

SOURCE=.\WorldProperties.h
# End Source File
# End Group
# Begin Group "SDK"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\clientheaders.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iaggregate.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iclientshell.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltclient.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltcommon.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltcsbase.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltcursor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltcustomdraw.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltdirectmusic.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltmath.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltmessage.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltmodel.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltphysics.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltserver.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltsoundmgr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltspritecontrol.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltstream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ilttexmod.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ilttransform.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iltvideomgr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iobjectplugin.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\iservershell.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\lithtech.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltanimtracker.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltassert.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltbasedefs.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltbasetypes.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltbbox.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltbeziercurve.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltcodes.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltengineobjects.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltlink.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltmatrix.h
# End Source File
# Begin Source File

SOURCE=..\..\..\engine\sdk\inc\ltobjref.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltplane.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltpvalue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltquatbase.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltrect.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltrotation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltserverobj.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\ltvector.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Engine\sdk\inc\serverheaders.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ClassHlp.but

!IF  "$(CFG)" == "ObjectShared - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build
InputPath=.\ClassHlp.but

"$(GAME_TOOLS_DIR)\ClassHlp.but" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) $(GAME_TOOLS_DIR)

# End Custom Build

!ELSEIF  "$(CFG)" == "ObjectShared - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build
InputPath=.\ClassHlp.but

"$(GAME_TOOLS_DIR)\ClassHlp.but" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) $(GAME_TOOLS_DIR)

# End Custom Build

!ELSEIF  "$(CFG)" == "ObjectShared - Win32 Final"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build
InputPath=.\ClassHlp.but

"$(GAME_TOOLS_DIR)\ClassHlp.but" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) $(GAME_TOOLS_DIR)

# End Custom Build

!ENDIF 

# End Source File
# End Target
# End Project
