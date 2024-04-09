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
	int32 Speed = 0;//카트 속력

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	int32 PlayTime = 600;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	int32 PlayTimeMin = 0; // 플레이 타임 시간

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	int32 PlayTimeSec = 0;

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
	
	//타이머 핸들을 멈추거나 초기화할 때 사용한다.
	virtual void StopPlayerTimer();
	
	//타이머의 시간을 계산하여 분과 초의 변수에 값을 삽입한다.
	virtual void CalculateTimer();
	
	//제한시간이 종료되었을 경우 발생
	virtual void TimeUp();
protected:
	virtual void BeginPlay() override;

	
private:
	
};
