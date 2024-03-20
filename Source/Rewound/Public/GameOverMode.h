// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameOverWidget.h"
#include "GameOverMode.generated.h"

/**
 * 
 */
UCLASS()
class REWOUND_API AGameOverMode : public AGameModeBase
{
	GENERATED_BODY()
	

public:

	virtual void StartPlay() override;

	UPROPERTY(EditAnywhere, Category = "GUI")
	TSubclassOf<UGameOverWidget> UserWidgetPrefab;

	UFUNCTION(BlueprintCallable, Category = "GUI")
	void ChangeMenuWidget(TSubclassOf<UGameOverWidget> NewWidgetClass);

	UPROPERTY()
	UGameOverWidget* CurrentWidget;
};
