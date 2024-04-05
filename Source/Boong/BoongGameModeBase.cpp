// Copyright Epic Games, Inc. All Rights Reserved.


#include "BoongGameModeBase.h"

 void ABoongGameModeBase::ReSpawn()
{

    
     
}

 void ABoongGameModeBase::ChangeMainLevel()
 {
     //상기 LSK_Test_Start_Level // 건주Main_Circit
     ChangeLevelScene("Main_Circit");
 }

 void ABoongGameModeBase::ChangeStartLevel()
 {
     ChangeLevelScene("LSK_Test_Start_Level");
 }

 void ABoongGameModeBase::StopPlayerTimer()
 {
 }

 void ABoongGameModeBase::SetTimerPlusPlayTime()
 {
     //GetWorldTimerManager().SetTimer(TimerHandle, this, &ABoongGameModeBase::PlusPlayTimer, 0.1f, true);
 }

 void ABoongGameModeBase::PlusPlayTimer()
 {
    
 }

 void ABoongGameModeBase::CountDownTimer()
 {
 }

 void ABoongGameModeBase::BeginPlay()
 {
     //Super::BeginPlay();
 }
