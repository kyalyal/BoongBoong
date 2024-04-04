// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BoongGameInstance.generated.h"


//Player 자동차 식별 변수만들기
//Player Level 
//Player 생명
//삼인칭 C++
//플러그인으로 C++코딩이 되어있는 차의 블루프린트.


// 상기widget 기어 속도


//죽었을때

/**
 * 
 */
UCLASS()
class BOONG_API UBoongGameInstance : public UGameInstance
{
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString CarName;
	int32 PlayerLevel;
	int32 PlayerLife = 100;

	GENERATED_BODY()

	// 보기만 하는거
	// 캐릭터 받아올 변수
	// 가비지..
	
};
