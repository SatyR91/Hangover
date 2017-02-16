// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/Slate/Public/Widgets/Text/STextBlock.h"
#include "MainUserWidget.generated.h"

UCLASS(BlueprintType, Blueprintable)
class PROJECTNONAME_API UMainUserWidget: public UUserWidget
{
    GENERATED_BODY()
    
    
    
public:
    void Init();
    void SetGoldText(FString text);
    void SetLevelText(FString text);
    void SetScoreText(FString text);
    void SetNbWaveText(FString text);
    void SetEnemiesText(FString inLife, FString total);
    
    
private:
    UTextBlock* GoldTextDisplay;
    UTextBlock* LevelTextDisplay;
    UTextBlock* ScoreTextDisplay;
    UTextBlock* NbWaveTextDisplay;
    UTextBlock* EnnemisTextDisplay;
};
