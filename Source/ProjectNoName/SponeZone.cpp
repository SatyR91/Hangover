// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectNoName.h"
#include "SponeZone.h"


// Sets default values
ASponeZone::ASponeZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    this->SponeZoneComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("sponeZoneCompenent"));
    this->SponeZoneComponent->bGenerateOverlapEvents = true;
    this->SponeZoneComponent->OnComponentBeginOverlap.AddDynamic(this, &ASponeZone::TriggerEnter);
    
    this->RootComponent = this->SponeZoneComponent;
}

// Called when the game starts or when spawned
void ASponeZone::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASponeZone::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASponeZone::TriggerEnter(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) {
    UE_LOG(LogTemp, Warning, TEXT("Yep"));
    
    
}
