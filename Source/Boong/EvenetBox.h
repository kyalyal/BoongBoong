// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EvenetBox.generated.h"


//블루프린트와 연결되는 델리게이트
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCompleteSignature);


UCLASS()
class BOONG_API AEvenetBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEvenetBox();

protected:
	// 레벨 시작시 호출
	virtual void BeginPlay() override;

	// 컴포넌트 초기화 된 후 호출
	virtual void PostInitializeComponents() override;



public:	

	
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent> TriggerBox;

public:


	//블루프린트에 델리게이트 노출
	UPROPERTY(BlueprintAssignable)
	FOnCompleteSignature OnComplete;


private:


	//곂칠 시
	UFUNCTION()
	virtual void OnPlayerBeginOverlap
		(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	//곂친 후 벗어날 시
	UFUNCTION()
	virtual void OnPlayerEndOverlap(
		class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

};
