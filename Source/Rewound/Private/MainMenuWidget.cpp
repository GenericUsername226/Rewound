// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

void UMainMenuWidget::NativeConstruct()
{
	if (PlayGame)
	{
		PlayGame->OnClicked.AddDynamic(this, &UMainMenuWidget::PlayGameOnClicked);
	}
	if (QuitGame)
	{
		QuitGame->OnClicked.AddDynamic(this, &UMainMenuWidget::QuitGameOnClicked);
	}
}

void UMainMenuWidget::PlayGameOnClicked()
{
	UGameplayStatics::OpenLevel(this, FName("Level"), true);
}

void UMainMenuWidget::QuitGameOnClicked()
{
	APlayerController* SpecificPlayer = GetWorld()->GetFirstPlayerController();
	UKismetSystemLibrary::QuitGame(GetWorld(), SpecificPlayer, EQuitPreference::Quit, true);
}
