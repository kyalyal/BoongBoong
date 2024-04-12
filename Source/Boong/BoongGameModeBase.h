// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BoongGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BOONG_API ABoongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	int32 PlayerScore = 100; // 플레이어 점수

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	int32 PlayTime = 600;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	int32 PlayTimeMin = 0; // 플레이 타임 시간

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	int32 PlayTimeSec = 0;

	int32 Speed = 0;//카트 속력
	FTimerHandle TimerHandle; //제한시간 타이머를 식별하기 위한 핸들
public :

	//메인레벨로 전환한다.
	UFUNCTION(BlueprintCallable)
	virtual void ChangeMainLevel();

	//처음시작레벨로 전환한다.
	UFUNCTION(BlueprintCallable)
	virtual void ChangeStartLevel();

	//플레이어 재생성
	virtual void ReSpawn();

	////제한시간 타이머를 실행한다.
	UFUNCTION(BlueprintCallable)
	virtual void StartTimer();
	
	UFUNCTION(BlueprintCallable)
	//타이머 핸들을 멈추거나 초기화할 때 사용한다.
	virtual void StopPlayerTimer();
	
	UFUNCTION(BlueprintCallable)
	//타이머의 시간을 계산하여 분과 초의 변수에 값을 삽입한다.
	virtual void CalculateTimer();

	//PlayTime을 10분으로 초기화한다.
	virtual void ResetPlayTime();
	
	UFUNCTION(BlueprintCallable)
	//플레이어의 점수가 5점 감점이 된다.
	virtual void MinusPlayerScore();

	UFUNCTION(BlueprintCallable)
	//플레이어의 점수가 100점으로 리셋된다.
	virtual void ResetPlayerScore();

	UFUNCTION(BlueprintCallable)
	//도착선에 도달시 플레이어가 합격인지 불합격인지 판단한다. 
	virtual void JudgePass();

	UFUNCTION(BlueprintCallable)
	//플레이어가 합격 했을 때
	virtual void PlayerPass();

	UFUNCTION(BlueprintCallable)
	//플레이어가 불합격 했을 때
	virtual void PlayerFail();
	
	UFUNCTION(BlueprintCallable)
	//실격처리가 되었을 때
	virtual void TestDisqualification();

	
	UFUNCTION(BlueprintCallable)
	virtual void TestTest();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	class TSubclassOf<UUserWidget> MainWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	class UUserWidget* CurrentWidget;
	
protected:
	virtual void BeginPlay() override;

	
private:
	
};
