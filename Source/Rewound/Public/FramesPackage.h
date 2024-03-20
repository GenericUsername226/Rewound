// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math/Vector2D.h"
#include "Math/Vector.h"
#include "Math/Rotator.h"

/*
class REWOUND_API FramesPackage
{
public:
	FramesPackage();
	~FramesPackage();
	
};*/
struct FFramePackage
{
	FORCEINLINE FFramePackage();
	FORCEINLINE FFramePackage(FVector InLocation, FRotator InRotation, FVector InLinearVelocity, FVector InAngularVelocity, float InDeltaTime);

	FVector Location;
	FRotator Rotation;
	FVector LinearVelocity;
	FVector AngularVelocity;

	bool bIsPlayerPawn;
	FVector2D MouseXY;

	float DeltaTime;
};

FFramePackage::FFramePackage()
{

}

FFramePackage::FFramePackage(FVector InLocation, FRotator InRotation, FVector InLinearVelocity, FVector InAngularVelocity, float InDeltaTime):
	Location(InLocation), Rotation(InRotation), LinearVelocity(InLinearVelocity), AngularVelocity(InAngularVelocity), DeltaTime(InDeltaTime)
{

}
