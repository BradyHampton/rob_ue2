// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "Components/TextBlock.h"

	
	int counter;

void UMyUserWidget::UpdateScore(int32 Count) {
	counter += Count;
	if (ScoreText) {
		ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %i"), counter)));
	}

}