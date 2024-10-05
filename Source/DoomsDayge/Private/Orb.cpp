// Fill out your copyright notice in the Description page of Project Settings.


#include "Orb.h"
#include "PlayerCharacter.h"

// Sets default values
AOrb::AOrb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	OrbMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OrbMesh"));
	SetRootComponent(OrbMesh);

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetupAttachment(OrbMesh);
}

void AOrb::NotifyHit(
	UPrimitiveComponent* MyComp,
	AActor* Other,
	UPrimitiveComponent* OtherComp,
	bool bSelfMoved,
	FVector HitLocation,
	FVector HitNormal,
	FVector NormalImpulse,
	const FHitResult& Hit)
{
	if (Other && Other->IsA(APlayerCharacter::StaticClass()))
	{
		APlayerCharacter* Character = Cast<APlayerCharacter>(Other);
		if (Character)
		{
			Character->CollectOrb();
			Destroy();
		}
	}
}	

// Called when the game starts or when spawned
void AOrb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOrb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}