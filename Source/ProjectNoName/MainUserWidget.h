// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/UMG/Public/Components/Image.h"
#include "Runtime/UMG/Public/Components/ProgressBar.h"
#include "MainUserWidget.generated.h"

UCLASS(BlueprintType, Blueprintable)
class PROJECTNONAME_API UMainUserWidget: public UUserWidget
{
    GENERATED_BODY()
    
public:
    void Init();
    void SetGoldText(FString text);
    void SetLevelProgress(int current, int total);
    void SetLevelText(FString text);
    void SetLifeDisplay(double life); // 0 -> 100
    void SetScoreText(FString text);
    void SetNbWaveText(FString text);
    void SetEnemiesText(FString inLife, FString total);
    
    
private:
    UTextBlock* GoldTextDisplay;
    UProgressBar* LevelProgressDisplay;
    UTextBlock* LevelTextDisplay;
    TArray<UImage*> LifeLevelDisplay;
    UTextBlock* ScoreTextDisplay;
    UTextBlock* NbWaveTextDisplay;
    UTextBlock* EnnemisTextDisplay;
};
