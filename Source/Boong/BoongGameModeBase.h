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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float PlayTime = 0f; // 플레이 타임 시간
	float CountDownTime = 0f; // 카운트 타임 시간
	bool BoolStopPlayerTime = false; // 플레이 타임을 멈추는 BOOL타입 변수
public :
	//플레이어 재생성
	virtual void ReSpawn();
	
	//Level을 바꾸기 시작씬에서 메인씬으로 이동
	virtual void ChangeLevelScene();
	
	//플레이어의 시간을 멈추기
	virtual void StopPlayerTimer();
	
	//SetTimer함수를 0.1동안 마다 PlusPlayTime을 호출한다.
	virtual void SetTimerPlusPlayTime();
	
	//플레이어 시간이 흘러감
	virtual void PlusPlayTimer();
	
	//카운타운 타임이 진행됨
	virtual void CountDownTimer();

protected:
	virtual void BeginPlay() override;
	
private:

};
