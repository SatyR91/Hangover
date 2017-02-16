// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameModeBase.h"
#include "ProjectNoNameGameMode.generated.h"

UCLASS(minimalapi)
class AProjectNoNameGameMode : public AGameModeBase
{
	GENERATED_BODY()

    virtual void BeginPlay() override;
    
public:
	AProjectNoNameGameMode();
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
    TSubclassOf<class UUserWidget> PlayerHUDClass;
    
    UPROPERTY()
    class UUserWidget* CurrentWidget;
};



