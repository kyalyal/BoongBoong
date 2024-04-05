// Fill out your copyright notice in the Description page of Project Settings.


#include "EvenetBox.h"

// Sets default values
AEvenetBox::AEvenetBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER")); //Hash
	RootComponent = TriggerBox;
	TriggerBox->SetBoxExtent(FVector(100.f, 100.f, 100.f));


	TriggerBox->SetCollisionProfileName(TEXT("BoongCollision"));
}

// Called when the game starts or when spawned
void AEvenetBox::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEvenetBox::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AEvenetBox::OnPlayerBeginOverlap);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AEvenetBox::OnPlayerEndOverlap);

}



void AEvenetBox::OnPlayerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("BeginOverlap"));

	OnComplete.Broadcast();
}

void AEvenetBox::OnPlayerEndOverlap(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Log, TEXT("EndOverlap"));
}


