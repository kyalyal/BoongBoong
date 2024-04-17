// Copyright Epic Games, Inc. All Rights Reserved.


#include "BoongGameModeBase.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"



void ABoongGameModeBase::ChangeMainLevel()
{
    UGameplayStatics::OpenLevel(this, "Main_Circit");
}

void ABoongGameModeBase::ChangeStartLevel()
{
    UGameplayStatics::OpenLevel(this,"LSK_Test_Start_Level");
}

void ABoongGameModeBase::ReSpawn()
{
    
}

void ABoongGameModeBase::StartTimer()
{
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ABoongGameModeBase::CalculateTimer, 1.0f, true, 1.0f);
}

 void ABoongGameModeBase::StopPlayerTimer()
 {
     GetWorldTimerManager().ClearTimer(TimerHandle);
 }

 void ABoongGameModeBase::CalculateTimer()
 {
     PlayTime--;
     PlayTimeMin = PlayTime / 60;
     PlayTimeSec = PlayTime % 60;
     UE_LOG(LogTemp, Log, TEXT("Remaining Time: %02d:%02d"), PlayTimeMin, PlayTimeSec);

     if (PlayTime <= 0) 
     {
         StopPlayerTimer();
     }
 }

 void ABoongGameModeBase::ResetPlayTime()
 {
     PlayTime = 600;
 }


 void ABoongGameModeBase::MinusPlayerScore()
 {
     PlayerScore -= 5;
     if (PlayerScore < 60) 
     {
         StopPlayerTimer();
     }

 }


 void ABoongGameModeBase::ResetPlayerScore()
 {
     PlayerScore = 100;
 }


 void ABoongGameModeBase::JudgePass()
 {
     StopPlayerTimer();
     if (PlayerScore >= 80) 
     {
         PlayerPass();
     }
     else 
     {
         PlayerFail();
     }
 }


 void ABoongGameModeBase::PlayerPass()
 {

 }
 void ABoongGameModeBase::PlayerFail()
 {

 }

 
 void ABoongGameModeBase::TestTest(TSubclassOf<UUserWidget> newWidgetClass)
 {

     CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), newWidgetClass);
     CurrentWidget->AddToViewport();
 }

 void ABoongGameModeBase::BeginPlay()
 {    
     Super::BeginPlay();
     
 }
