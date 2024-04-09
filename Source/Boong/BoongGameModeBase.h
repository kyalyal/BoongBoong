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
	int32 Speed = 0;//īƮ �ӷ�

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	int32 PlayTime = 600;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	int32 PlayTimeMin = 0; // �÷��� Ÿ�� �ð�

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	int32 PlayTimeSec = 0;

	FTimerHandle TimerHandle; //���ѽð� Ÿ�̸Ӹ� �ĺ��ϱ� ���� �ڵ�
public :
	//���η����� ��ȯ�Ѵ�.
	UFUNCTION(BlueprintCallable)
	virtual void ChangeMainLevel();
	//ó�����۷����� ��ȯ�Ѵ�.
	UFUNCTION(BlueprintCallable)
	virtual void ChangeStartLevel();
	//�÷��̾� �����
	virtual void ReSpawn();

	////���ѽð� Ÿ�̸Ӹ� �����Ѵ�.
	UFUNCTION(BlueprintCallable)
	virtual void StartTimer();
	
	//Ÿ�̸� �ڵ��� ���߰ų� �ʱ�ȭ�� �� ����Ѵ�.
	virtual void StopPlayerTimer();
	
	//Ÿ�̸��� �ð��� ����Ͽ� �а� ���� ������ ���� �����Ѵ�.
	virtual void CalculateTimer();
	
	//���ѽð��� ����Ǿ��� ��� �߻�
	virtual void TimeUp();
protected:
	virtual void BeginPlay() override;

	
private:
	
};
