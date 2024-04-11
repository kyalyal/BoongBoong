// Copyright Epic Games, Inc. All Rights Reserved.


#include "BoongGameModeBase.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

//���η����� ��ȯ�Ѵ�.
void ABoongGameModeBase::ChangeMainLevel()
{
    //��� LSK_Test_Start_Level // ����Main_Circit
    UGameplayStatics::OpenLevel(this, "Main_Circit");
}
//ó�����۷����� ��ȯ�Ѵ�.
void ABoongGameModeBase::ChangeStartLevel()
{
    UGameplayStatics::OpenLevel(this,"LSK_Test_Start_Level");
}
//�÷��̾� ����
void ABoongGameModeBase::ReSpawn()
{
    
}
//���ѽð� Ÿ�̸Ӹ� �����Ѵ�.
void ABoongGameModeBase::StartTimer()
{
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ABoongGameModeBase::CalculateTimer, 1.0f, true, 1.0f);
}
//Ÿ�̸� �ڵ��� ���߰ų� �ʱ�ȭ�� �� ����Ѵ�.
 void ABoongGameModeBase::StopPlayerTimer()
 {
     GetWorldTimerManager().ClearTimer(TimerHandle);
 }

 //Ÿ�̸��� �ð��� ����Ͽ� �а� ���� ������ ���� �����Ѵ�.
 void ABoongGameModeBase::CalculateTimer()
 {
     // ������ �ð��� 1�ʾ� �����Ѵ�.
     PlayTime--;

     // �а� �� ����Ͽ� ������ �����Ѵ�.
     PlayTimeMin = PlayTime / 60;
     PlayTimeSec = PlayTime % 60;
     UE_LOG(LogTemp, Log, TEXT("Remaining Time: %02d:%02d"), PlayTimeMin, PlayTimeSec);
     // Ÿ�̸� ���� �� �ǰ�ó���ϰ� Ÿ�̸� �ڵ��� �ʱ�ȭ�Ѵ�.
     if (PlayTime <= 0) 
     {
         TestDisqualification();
         StopPlayerTimer();
     }
 }
 //PlayTime�� 10������ �ʱ�ȭ�Ѵ�.
 void ABoongGameModeBase::ResetPlayTime()
 {
     PlayTime = 600;
 }

 //5���� ������ �ǰ� �ǰ����� 60������ �������� �ǰ�ó���� �ȴ�.
 void ABoongGameModeBase::MinusPlayerScore()
 {
     PlayerScore -= 5;
     if (PlayerScore < 60) 
     {
         TestDisqualification();
         StopPlayerTimer();
     }

 }

 //�÷��̾��� ������ 100������ ���µȴ�.
 void ABoongGameModeBase::ResetPlayerScore()
 {
     PlayerScore = 100;
 }

 //�������� ���޽� �÷��̾ �հ����� ���հ����� �Ǵ��Ѵ�. 
 void ABoongGameModeBase::JudgePass()
 {
     StopPlayerTimer();
     if (PlayerScore >= 80) //���� 80���� ������ ���
     {
         PlayerPass();
     }
     else //�ƴҰ�� ���հ�ó��
     {
         PlayerFail();
     }
 }
 //#�������Ʈ�� �ش� UI�� �����ͼ� �����ؾ���
 //�÷��̾ �հ� ���� ��
 void ABoongGameModeBase::PlayerPass()
 {
    
 }
 //�÷��̾ ���հ� ���� ��
 void ABoongGameModeBase::PlayerFail()
 {

 }

 //���� �ǰ�ó���� �Ǿ��� ��
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
