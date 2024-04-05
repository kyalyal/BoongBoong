// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EvenetBox.h"
#include "StopBox.generated.h"

/**
 * 
 */
UCLASS()
class BOONG_API AStopBox : public AEvenetBox
{
	GENERATED_BODY()


public:

	//UFUNCTION()
	//	virtual void OnPlayerBeginOverlap(
	//		UPrimitiveComponent* OverlappedComp,
	//		AActor* OtherActor,
	//		UPrimitiveComponent* OtherComp,
	//		int32 OtherBodyIndex,
	//		bool bFromSweep,
	//		const FHitResult& SweepResult) override;

	////곂친 후 벗어날 시
	//UFUNCTION()
	//	virtual void OnPlayerEndOverlap(
	//		class UPrimitiveComponent* OverlappedComp,
	//		class AActor* OtherActor,
	//		class UPrimitiveComponent* OtherComp,
	//		int32 OtherBodyIndex) override;
	
};
