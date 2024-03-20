// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameModeBase.h"
#include "Logging/StructuredLog.h"
#include "MainMenuWidget.h"
#include "MainMenuMode.generated.h"

/**
 * 
 */
UCLASS()
class REWOUND_API AMainMenuMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	virtual void StartPlay() override;

	UPROPERTY(EditAnywhere, Category = "GUI")
	TSubclassOf<UMainMenuWidget> UserWidgetPrefab;

	UFUNCTION(BlueprintCallable, Category = "GUI")
	void ChangeMenuWidget(TSubclassOf<UMainMenuWidget> NewWidgetClass);

	UPROPERTY()
	UMainMenuWidget* CurrentWidget;
};
