// Copyright Epic Games, Inc. All Rights Reserved.


#include "BoongGameModeBase.h"

#include "Kismet/GameplayStatics.h"

void ABoongGameModeBase::ChangeMainLevel()
{
    //상기 LSK_Test_Start_Level // 건주Main_Circit
    ChangeLevelScene("Main_Circit");
}

void ABoongGameModeBase::ChangeStartLevel()
{
    ChangeLevelScene("LSK_Test_Start_Level");
}

void ABoongGameModeBase::ReSpawn()
{

    
     
}

void ABoongGameModeBase::ChangeLevelScene(FName LevelName)
 {
  
        UGameplayStatics::OpenLevel(this, LevelName);
     
 }

 void ABoongGameModeBase::StopPlayerTimer()
 {
 }

 void ABoongGameModeBase::SetTimerPlusPlayTime()
 {
    
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
