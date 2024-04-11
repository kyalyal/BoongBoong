// Copyright Epic Games, Inc. All Rights Reserved.


#include "BoongGameModeBase.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

//메인레벨로 전환한다.
void ABoongGameModeBase::ChangeMainLevel()
{
    //상기 LSK_Test_Start_Level // 건주Main_Circit
    UGameplayStatics::OpenLevel(this, "Main_Circit");
}
//처음시작레벨로 전환한다.
void ABoongGameModeBase::ChangeStartLevel()
{
    UGameplayStatics::OpenLevel(this,"LSK_Test_Start_Level");
}
//플레이어 생성
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
     // 타이머 종료 시 실격처리하고 타이머 핸들을 초기화한다.
     if (PlayTime <= 0) 
     {
         TestDisqualification();
         StopPlayerTimer();
     }
 }
 //PlayTime을 10분으로 초기화한다.
 void ABoongGameModeBase::ResetPlayTime()
 {
     PlayTime = 600;
 }

 //5점이 감점이 되고 실격점수 60점보다 낮아지면 실격처리가 된다.
 void ABoongGameModeBase::MinusPlayerScore()
 {
     PlayerScore -= 5;
     if (PlayerScore < 60) 
     {
         TestDisqualification();
         StopPlayerTimer();
     }

 }

 //플레이어의 점수가 100점으로 리셋된다.
 void ABoongGameModeBase::ResetPlayerScore()
 {
     PlayerScore = 100;
 }

 //도착선에 도달시 플레이어가 합격인지 불합격인지 판단한다. 
 void ABoongGameModeBase::JudgePass()
 {
     StopPlayerTimer();
     if (PlayerScore >= 80) //점수 80점이 넘으면 통과
     {
         PlayerPass();
     }
     else //아닐경우 불합격처리
     {
         PlayerFail();
     }
 }
 //#블루프린트로 해당 UI를 가져와서 설정해야함
 //플레이어가 합격 했을 때
 void ABoongGameModeBase::PlayerPass()
 {
    
 }
 //플레이어가 불합격 했을 때
 void ABoongGameModeBase::PlayerFail()
 {

 }

 //시험 실격처리가 되었을 때
 void ABoongGameModeBase::TestDisqualification()
 {

 }
 /*
 void ABoongGameModeBase::TestTest()
 {
     CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), MainWidget);
     CurrentWidget->AddToViewport();
 }*/
 void ABoongGameModeBase::BeginPlay()
 {    
     Super::BeginPlay();
     
 }
