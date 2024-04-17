// Copyright Epic Games, Inc. All Rights Reserved.


#include "BoongGameModeBase.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

ABoongGameModeBase::ABoongGameModeBase()
{

    

}


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
    // = deadui 
 }
 void ABoongGameModeBase::PlayerFail()
 {
     //TSubclassOf<UUserWidget> widget = Find
     //Test()
     //TestTest(MyWidget);
 }

 void ABoongGameModeBase::TestCode()
 {
     ///Script/UMGEditor.WidgetBlueprint'/Game/SW/Blueprint/DeadUi.DeadUi'
     FStringClassReference MyWidget = (TEXT("/ Script / UMGEditor.WidgetBlueprint'/Game/SW/Blueprint/DeadUi.DeadUi_C'"));
     
     UClass* SwWidget = MyWidget.TryLoadClass<UUserWidget>();
     
     if(MyWidget.TryLoadClass<UUserWidget>() == nullptr) {

     UE_LOG(LogTemp, Log, TEXT("HELLO"));
     }

     if (SwWidget)
     {
         UUserWidget* blackLinesWidget = CreateWidget<UUserWidget>(GetWorld(), SwWidget);
         if (blackLinesWidget)
             blackLinesWidget->AddToViewport();
     }
 }


 


 void ABoongGameModeBase::BeginPlay()
 {    
     Super::BeginPlay();
     /*
     FStringClassReference MyWidget = (TEXT("WidgetBlueprint'/Game/SW/Blueprint/DeadUi_C'"));

     UClass* SwWidget = MyWidget.TryLoadClass<UUserWidget>();

     if (SwWidget)
     {
         UUserWidget* blackLinesWidget = CreateWidget<UUserWidget>(GetWorld(), SwWidget);
         if (blackLinesWidget)
             blackLinesWidget->AddToViewport();
     }*/
     
 }
