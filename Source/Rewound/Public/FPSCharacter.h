// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Projectile.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReverseTimeDelegate, bool, bReverseTime);

UCLASS()
class REWOUND_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AProjectile> ProjectileClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Handles input for moving forward and backward.
	UFUNCTION()
	void MoveForward(float Value);

	// Handles input for moving right and left.
	UFUNCTION()
	void MoveRight(float Value);

	//Start Jump
	UFUNCTION()
	void StartJump();

	//StopsJump
	UFUNCTION()
	void StopJump();

	//Camera
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPSCameraComponent;

	//Arms
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* FPSMesh;

	//Makes gun shoot
	UFUNCTION()
	void Fire();

	//Muzzle offset from camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;


	void Sprint();


	void StopSprinting();

	float Health = 100;
	const float MaxHealth = 100;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	void StartReversingTime();
	void StopReversingTime();

public:

	//Reversing Time

	FReverseTimeDelegate ReverseTimeDelegate;
};
