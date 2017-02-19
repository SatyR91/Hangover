// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameModeBase.h"
#include "MainUserWidget.h"
#include "ProjectNoNameCharacter.h"
#include "ProjectNoNameGameMode.generated.h"

UCLASS(minimalapi)
class AProjectNoNameGameMode : public AGameModeBase
{
	GENERATED_BODY()

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
    
public:
	AProjectNoNameGameMode();
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
    TSubclassOf<class UUserWidget> PlayerHUDClass;
    
    UPROPERTY()
    class UMainUserWidget* CurrentWidget;
    
    UPROPERTY()
    AProjectNoNameCharacter* CurrentCharacter;
};



