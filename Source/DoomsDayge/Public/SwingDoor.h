// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwingDoor.generated.h"

UCLASS()
class DOOMSDAYGE_API ASwingDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwingDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "DoorFunc")
	void CloseDoor(float dt);
	UFUNCTION(BlueprintCallable, Category = "DoorFunc")
	void OpenDoor(float dt);
	UFUNCTION(BlueprintCallable, Category = "DoorFunc")
	void ToggleDoor(const FVector &ForwardVector);

	UFUNCTION()
	virtual void OverlappedBegin(UPrimitiveComponent* OverlappedComp,
		AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OverlappedEnd(UPrimitiveComponent* OverlappedComp,
		AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(VisibleAnywhere, Category="Box Comps")
	class UBoxComponent* BoxComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* Door;

	UPROPERTY(BlueprintReadWrite)
	bool Opening;
	UPROPERTY(BlueprintReadWrite)
	bool Closing;
	UPROPERTY(BlueprintReadWrite)
	bool isClosed;
	float DotP, MaxDegree, AddRotation, PosNeg, DoorCurrentRotation;

};
