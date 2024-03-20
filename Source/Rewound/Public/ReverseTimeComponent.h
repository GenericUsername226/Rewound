// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FramesPackage.h"
#include "GameFramework/Actor.h"
#include "ReverseTimeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class REWOUND_API UReverseTimeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UReverseTimeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void SetReversingTime(bool InReversingTime);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Reversing time when true, collecting when false
	bool bReversingTime;

	//out of time data, cannot continue reversing
	bool bOutOfData;

	//Actual time since starting reverse time
	float RunningTime;

	//Running count of the Frame Package Delta Time
	float LeftReverseRunningTime;
	float RightReverseRunningTime;

	//Total amount of time recorded in FramePackage
	float RecordedTime;

	TDoubleLinkedList<FFramePackage> StoredFrames;

	void SetActorVariables(FVector Location, FRotator Rotation, FVector LinearVel, FVector AngularVel);
};
