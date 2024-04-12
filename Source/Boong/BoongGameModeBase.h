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
	int32 PlayerScore = 100; // �÷��̾� ����

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	int32 PlayTime = 600;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	int32 PlayTimeMin = 0; // �÷��� Ÿ�� �ð�

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerValue")
	int32 PlayTimeSec = 0;

	int32 Speed = 0;//īƮ �ӷ�
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
	
	UFUNCTION(BlueprintCallable)
	//Ÿ�̸� �ڵ��� ���߰ų� �ʱ�ȭ�� �� ����Ѵ�.
	virtual void StopPlayerTimer();
	
	UFUNCTION(BlueprintCallable)
	//Ÿ�̸��� �ð��� ����Ͽ� �а� ���� ������ ���� �����Ѵ�.
	virtual void CalculateTimer();

	//PlayTime�� 10������ �ʱ�ȭ�Ѵ�.
	virtual void ResetPlayTime();
	
	UFUNCTION(BlueprintCallable)
	//�÷��̾��� ������ 5�� ������ �ȴ�.
	virtual void MinusPlayerScore();

	UFUNCTION(BlueprintCallable)
	//�÷��̾��� ������ 100������ ���µȴ�.
	virtual void ResetPlayerScore();

	UFUNCTION(BlueprintCallable)
	//�������� ���޽� �÷��̾ �հ����� ���հ����� �Ǵ��Ѵ�. 
	virtual void JudgePass();

	UFUNCTION(BlueprintCallable)
	//�÷��̾ �հ� ���� ��
	virtual void PlayerPass();

	UFUNCTION(BlueprintCallable)
	//�÷��̾ ���հ� ���� ��
	virtual void PlayerFail();
	
	UFUNCTION(BlueprintCallable)
	//�ǰ�ó���� �Ǿ��� ��
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
