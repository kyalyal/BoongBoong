// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"


//Player �ڵ��� �ĺ� ���������
//Player Level 
//Player ����
//����Ī C++
//�÷��������� C++�ڵ��� �Ǿ��ִ� ���� �������Ʈ.


// ���widget ��� �ӵ�


//�׾�����


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
	
	//�޸� ������ �ϰų�, �������Ʈ���� �޾Ƽ� ����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString MyName;


	FORCEINLINE void GetMyName();

};
