// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BoongGameInstance.generated.h"


//삼인칭 C++
//플러그인으로 C++코딩이 되어있는 차의 블루프린트.


// 상기widget 기어 속도
// 상기widget 기어 속도


//죽었을때

/**
 * 
 */
UCLASS()
class BOONG_API UBoongGameInstance : public UGameInstance
{
public:
	// 선택한 자동차 저장 변수

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString CarName;
	// 플레이어 레벨

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 PlayerLevel;
	// 플레이어 체력

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 Score = 100;

	GENERATED_BODY()

	// 보기만 하는거
	// 캐릭터 받아올 변수
	// 가비지..
	
};
