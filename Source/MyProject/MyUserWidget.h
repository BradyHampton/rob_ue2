// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateScore(int32 Count);

protected:
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* ScoreText;
};
