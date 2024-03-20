// Copyright Epic Games, Inc. All Rights Reserved.

#include "RewoundGameMode.h"
#include "RewoundCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARewoundGameMode::ARewoundGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Script/Engine.Blueprint'/Game/Blueprints/Bp_FPSCharacter.Bp_FPSCharacter'"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
