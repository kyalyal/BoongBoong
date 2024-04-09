// Copyright Epic Games, Inc. All Rights Reserved.


#include "BoongGameModeBase.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"

void ABoongGameModeBase::ChangeMainLevel()
{
    //상기 LSK_Test_Start_Level // 건주Main_Circit
    UGameplayStatics::OpenLevel(this, "Main_Circit");
}

void ABoongGameModeBase::ChangeStartLevel()
{
    UGameplayStatics::OpenLevel(this,"LSK_Test_Start_Level");
}

void ABoongGameModeBase::ReSpawn()
{
    
    
     
}
//제한시간 타이머를 실행한다.
void ABoongGameModeBase::StartTimer()
{
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ABoongGameModeBase::CalculateTimer, 1.0f, true, 1.0f);
}
//타이머 핸들을 멈추거나 초기화할 때 사용한다.
 void ABoongGameModeBase::StopPlayerTimer()
 {
     GetWorldTimerManager().ClearTimer(TimerHandle);
 }

 //타이머의 시간을 계산하여 분과 초의 변수에 값을 삽입한다.
 void ABoongGameModeBase::CalculateTimer()
 {
     // 총제한 시간이 1초씩 감소한다.
     PlayTime--;

     // 분과 초 계산하여 변수에 삽입한다.
     PlayTimeMin = PlayTime / 60;
     PlayTimeSec = PlayTime % 60;
     UE_LOG(LogTemp, Log, TEXT("Remaining Time: %02d:%02d"), PlayTimeMin, PlayTimeSec);
     // 타이머 종료 시 TimeUp을 호출하고 타이머 핸들을 초기화한다.
     if (PlayTime <= 0)
     {
         TimeUp();
         StopPlayerTimer();
     }
 }

 void ABoongGameModeBase::TimeUp()
 {

 }

 void ABoongGameModeBase::BeginPlay()
 {    
     Super::BeginPlay();
     
 }
