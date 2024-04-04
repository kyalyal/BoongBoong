// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"


//Player 자동차 식별 변수만들기
//Player Level 
//Player 생명
//삼인칭 C++
//플러그인으로 C++코딩이 되어있는 차의 블루프린트.


// 상기widget 기어 속도


//죽었을때


UCLASS()
class BOONG_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	
	//메모리 관리를 하거나, 블루프린트에서 받아서 쓸때
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString MyName;


	FORCEINLINE void GetMyName();

};
