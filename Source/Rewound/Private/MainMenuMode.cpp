// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuMode.h"

void AMainMenuMode::StartPlay()
{
	Super::StartPlay(); // Calls base function

	// C Assert
	// If this fails throw an error
	check(GEngine != nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Starting MainMenu")));

	ChangeMenuWidget(UserWidgetPrefab);
}

void AMainMenuMode::ChangeMenuWidget(TSubclassOf<UMainMenuWidget> NewWidgetClass)
{
		// 1. If we have one, remove it
		if (CurrentWidget != nullptr) {
			CurrentWidget->RemoveFromParent();
			CurrentWidget = nullptr;
		}

		// 2. If we don't one, add it the viewport
		if (NewWidgetClass != nullptr) {
			CurrentWidget = CreateWidget<UMainMenuWidget>(GetWorld(), NewWidgetClass);
			CurrentWidget->AddToViewport();
		}
}
