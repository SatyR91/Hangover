// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectNoName.h"
#include "MainUserWidget.h"

void UMainUserWidget::Init() {
    this->GoldTextDisplay = Cast<UTextBlock>(this->GetWidgetFromName(TEXT("TextBlock_GoldHUD")));
    this->LevelTextDisplay = Cast<UTextBlock>(this->GetWidgetFromName(TEXT("TextBlock_LevelHUD")));
    this->ScoreTextDisplay = Cast<UTextBlock>(this->GetWidgetFromName(TEXT("TextBlock_ScoreHUD")));
    this->NbWaveTextDisplay = Cast<UTextBlock>(this->GetWidgetFromName(TEXT("TextBlock_NbWaveHUD")));
    this->EnnemisTextDisplay = Cast<UTextBlock>(this->GetWidgetFromName(TEXT("TextBlock_EnnemiesHUD")));
    
    if (this->GoldTextDisplay == nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("WARNING: fail init ref on MainUserWidget (this->GoldTextDisplay)"));
    }
    if (this->LevelTextDisplay == nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("WARNING: fail init ref on MainUserWidget (this->LevelTextDisplay)"));
    }
    if (this->ScoreTextDisplay == nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("WARNING: fail init ref on MainUserWidget (this->ScoreTextDisplay)"));
    }
    if (this->NbWaveTextDisplay == nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("WARNING: fail init ref on MainUserWidget (this->NbWaveTextDisplay)"));
    }
    if (this->EnnemisTextDisplay == nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("WARNING: fail init ref on MainUserWidget (this->EnnemisTextDisplay)"));
    }
}

void UMainUserWidget::SetGoldText(FString text) {
    if (this->GoldTextDisplay != nullptr) {
        this->GoldTextDisplay->SetText(FText::FromString(text));
    }
}

void UMainUserWidget::SetLevelText(FString text) {
    if (this->LevelTextDisplay != nullptr) {
        this->LevelTextDisplay->SetText(FText::FromString(text));
    }
}

void UMainUserWidget::SetScoreText(FString text) {
    if (this->ScoreTextDisplay != nullptr) {
        FString str = TEXT("SCORE: ");
        str += text;
        this->ScoreTextDisplay->SetText(FText::FromString(str));
    }
}

void UMainUserWidget::SetNbWaveText(FString text) {
    if (this->NbWaveTextDisplay != nullptr) {
        this->NbWaveTextDisplay->SetText(FText::FromString(text));
    }
}

void UMainUserWidget::SetEnemiesText(FString inLife, FString total) {
    if (this->EnnemisTextDisplay != nullptr) {
        FString str = inLife + "/" + total;
        this->EnnemisTextDisplay->SetText(FText::FromString(str));
    }
}
