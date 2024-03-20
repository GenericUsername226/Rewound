// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

/**
 * 
 */
UCLASS()
class REWOUND_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* PlayGame;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* QuitGame;

	UFUNCTION()
	void PlayGameOnClicked();

	UFUNCTION()
	void QuitGameOnClicked();
};
