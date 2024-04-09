// Copyright Epic Games, Inc. All Rights Reserved.


#include "BoongGameModeBase.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"

void ABoongGameModeBase::ChangeMainLevel()
{
    //��� LSK_Test_Start_Level // ����Main_Circit
    UGameplayStatics::OpenLevel(this, "Main_Circit");
}

void ABoongGameModeBase::ChangeStartLevel()
{
    UGameplayStatics::OpenLevel(this,"LSK_Test_Start_Level");
}

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
     // Ÿ�̸� ���� �� TimeUp�� ȣ���ϰ� Ÿ�̸� �ڵ��� �ʱ�ȭ�Ѵ�.
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
