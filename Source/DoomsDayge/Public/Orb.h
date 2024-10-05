// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Orb.generated.h"

UCLASS()
class DOOMSDAYGE_API AOrb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOrb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* OrbMesh;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* CollisionComponent;

	virtual void NotifyHit(
		UPrimitiveComponent* MyComp,
		AActor* Other,
		UPrimitiveComponent* OtherComp,
		bool bSelfMoved,
		FVector HitLocation,
		FVector HitNormal,
		FVector NormalImpulse,
		const FHitResult& Hit) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
