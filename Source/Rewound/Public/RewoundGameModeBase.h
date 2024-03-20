// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Logging/StructuredLog.h"
#include "FPSUserwidget.h"
#include "RewoundGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class REWOUND_API ARewoundGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	virtual void StartPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GUI")
	TSubclassOf<UFPSUserWidget> UserWidgetPrefab;

	UFUNCTION(BlueprintCallable, Category = "GUI")
	void ChangeMenuWidget(TSubclassOf<UFPSUserWidget> NewWidgetClass);

	UPROPERTY()
	UFPSUserWidget* CurrentWidget;
};
