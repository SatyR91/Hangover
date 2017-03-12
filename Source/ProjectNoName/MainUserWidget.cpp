// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectNoName.h"
#include "MainUserWidget.h"

void UMainUserWidget::Init() {
    this->GoldTextDisplay = Cast<UTextBlock>(this->GetWidgetFromName(TEXT("TextBlock_GoldHUD")));
    this->LevelProgressDisplay = Cast<UProgressBar>(this->GetWidgetFromName(TEXT("ProgressBar_Level")));
    this->LevelTextDisplay = Cast<UTextBlock>(this->GetWidgetFromName(TEXT("TextBlock_LevelHUD")));
    for (int i = 0; i < 5; i += 1) {
        FName name = FName(*(TEXT("Image_Life_") + FString::FromInt(i)));
        UImage* _img = Cast<UImage>(this->GetWidgetFromName(name));
        if (_img != nullptr) {
            this->LifeLevelDisplay.Add(_img);
        }
    }
    this->ScoreTextDisplay = Cast<UTextBlock>(this->GetWidgetFromName(TEXT("TextBlock_ScoreHUD")));
    this->NbWaveTextDisplay = Cast<UTextBlock>(this->GetWidgetFromName(TEXT("TextBlock_NbWaveHUD")));
    this->EnnemisTextDisplay = Cast<UTextBlock>(this->GetWidgetFromName(TEXT("TextBlock_EnnemiesHUD")));
    
    if (this->GoldTextDisplay == nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("WARNING: fail init ref on MainUserWidget (this->GoldTextDisplay)"));
    }
    if (this->LevelProgressDisplay == nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("WARNING: fail init ref on MainUserWidget (this->LevelProgressDisplay)"));
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

void UMainUserWidget::SetLevelProgress(int current, int total) {
    if (this->LevelProgressDisplay != nullptr) {
        this->LevelProgressDisplay->SetPercent(((float) current) / ((float) total));
    }
}


void UMainUserWidget::SetLevelText(FString text) {
    if (this->LevelTextDisplay != nullptr) {
        this->LevelTextDisplay->SetText(FText::FromString(text));
    }
}

void UMainUserWidget::SetLifeDisplay(double life) {
    double count = this->LifeLevelDisplay.Num();
    for (double i = 0.f; i < count; i += 1.f) {
        double min = i * 100.f / count;
        double max = (i + 1) * 100.f / count;
        double alpha = (life - min) / (max - min);
        if (alpha < 0.f) {
            alpha = 0.f;
        } else if (alpha > 1.f) {
            alpha = 1.f;
        }
        this->LifeLevelDisplay[i]->SetOpacity(alpha);
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
        FString str = inLife + " / " + total;
        this->EnnemisTextDisplay->SetText(FText::FromString(str));
    }
}
