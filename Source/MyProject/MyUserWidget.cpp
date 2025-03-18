// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "Components/TextBlock.h"

void UMyUserWidget::UpdateScore(int32 Count) {
	if (ScoreText) {
		ScoreText->SetText(FText::FromString(TEXT("testing")));
	}
}