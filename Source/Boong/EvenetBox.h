// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EvenetBox.generated.h"

UCLASS()
class BOONG_API AEvenetBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEvenetBox();

protected:
	// ���� ���۽� ȣ��
	virtual void BeginPlay() override;

	// ������Ʈ �ʱ�ȭ �� �� ȣ��
	virtual void PostInitializeComponents() override;



public:	


	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent> TriggerBox;


private:

	UFUNCTION()
	void OnPlayerBeginOverlap
		(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OnPlayerEndOverlap(
		class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

};
