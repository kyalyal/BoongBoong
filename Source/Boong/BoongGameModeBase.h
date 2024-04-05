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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float PlayTime = 0.f; // �÷��� Ÿ�� �ð�

	float CountDownTime = 0.f; // ī��Ʈ Ÿ�� �ð�

	bool BoolStopPlayerTime = false; // �÷��� Ÿ���� ���ߴ� BOOLŸ�� ����
public :
	//���η����� ��ȯ�Ѵ�.
	UFUNCTION(BlueprintCallable)
		virtual void ChangeMainLevel();
	//ó�����۷����� ��ȯ�Ѵ�.
	UFUNCTION(BlueprintCallable)
		virtual void ChangeStartLevel();
	//�÷��̾� �����
	virtual void ReSpawn();

	//Level�� �ٲٱ� ���۾����� ���ξ����� �̵�
	virtual void ChangeLevelScene(FName LevelName);

	//�÷��̾��� �ð��� ���߱�
	virtual void StopPlayerTimer();

	//SetTimer�Լ��� 0.1���� ���� PlusPlayTime�� ȣ���Ѵ�.
	virtual void SetTimerPlusPlayTime();

	//�÷��̾� �ð��� �귯��
	virtual void PlusPlayTimer();

	//ī��Ÿ�� Ÿ���� �����
	virtual void CountDownTimer();

protected:
	virtual void BeginPlay() override;
	
private:

};
