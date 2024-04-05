// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BoongGameInstance.generated.h"


//����Ī C++
//�÷��������� C++�ڵ��� �Ǿ��ִ� ���� �������Ʈ.


// ���widget ��� �ӵ�
// ���widget ��� �ӵ�


//�׾�����

/**
 * 
 */
UCLASS()
class BOONG_API UBoongGameInstance : public UGameInstance
{
public:
	// ������ �ڵ��� ���� ����

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString CarName;
	// �÷��̾� ����

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 PlayerLevel;
	// �÷��̾� ü��

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 Score = 100;

	GENERATED_BODY()

	// ���⸸ �ϴ°�
	// ĳ���� �޾ƿ� ����
	// ������..
	
};
