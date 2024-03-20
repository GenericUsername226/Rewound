// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverMode.h"

void AGameOverMode::StartPlay()
{
	Super::StartPlay(); // Calls base function

	// C Assert
	// If this fails throw an error
	check(GEngine != nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Starting Game Over Screen")));

	ChangeMenuWidget(UserWidgetPrefab);
}

void AGameOverMode::ChangeMenuWidget(TSubclassOf<UGameOverWidget> NewWidgetClass)
{
	// 1. If we have one, remove it
	if (CurrentWidget != nullptr) {
		CurrentWidget->RemoveFromParent();
		CurrentWidget = nullptr;
	}

	// 2. If we don't one, add it the viewport
	if (NewWidgetClass != nullptr) {
		CurrentWidget = CreateWidget<UGameOverWidget>(GetWorld(), NewWidgetClass);
		CurrentWidget->AddToViewport();
	}
}
