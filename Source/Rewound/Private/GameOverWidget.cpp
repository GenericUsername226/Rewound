// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

void UGameOverWidget::NativeConstruct()
{
	if (PlayGame)
	{
		PlayGame->OnClicked.AddDynamic(this, &UGameOverWidget::PlayGameOnClicked);
	}
	if (QuitGame)
	{
		QuitGame->OnClicked.AddDynamic(this, &UGameOverWidget::QuitGameOnClicked);
	}
}

void UGameOverWidget::PlayGameOnClicked()
{
	UGameplayStatics::OpenLevel(this, FName("Level"), true);
}

void UGameOverWidget::QuitGameOnClicked()
{
	APlayerController* SpecificPlayer = GetWorld()->GetFirstPlayerController();
	UKismetSystemLibrary::QuitGame(GetWorld(), SpecificPlayer, EQuitPreference::Quit, true);
}
