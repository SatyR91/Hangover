// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ProjectNoName.h"
#include "ProjectNoNameGameMode.h"
#include "ProjectNoNameHUD.h"
#include "ProjectNoNameCharacter.h"
#include "Blueprint/UserWidget.h"

AProjectNoNameGameMode::AProjectNoNameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProjectNoNameHUD::StaticClass();
}

void AProjectNoNameGameMode::BeginPlay() {
    Super::BeginPlay();
    
    AProjectNoNameCharacter* CurrentCharacter = Cast<AProjectNoNameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
    
    if (this->PlayerHUDClass != nullptr) {
        this->CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), this->PlayerHUDClass);
        
        if(this->CurrentWidget != nullptr) {
            this->CurrentWidget->AddToViewport();
        }
    }
}
