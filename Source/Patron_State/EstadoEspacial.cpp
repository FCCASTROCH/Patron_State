// Fill out your copyright notice in the Description page of Project Settings.

#include "EstadoEspacial.h"
#include "NaveTerrestre.h"

#include "Engine/Engine.h"
// Sets default values
AEstadoEspacial::AEstadoEspacial()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    
    //bCanFire = true; // Permitir disparos al principio
    TargetLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 614);
    bIsMoving = true;
    TiempoDisparo = 4.0f;
    MoveSpeed = 40.0f;
}

// Called when the game starts or when spawned
void AEstadoEspacial::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AEstadoEspacial::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (bIsMoving && NaveE)
    {
        FVector CurrentLocation = NaveE->GetActorLocation();
        FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
        NaveE->SetActorLocation(NewLocation);

        if (CurrentLocation.Equals(TargetLocation, 1.0f))
        {
            bIsMoving = false;
        }
    }

}

void AEstadoEspacial::SetNaveTerrestre(ANaveTerrestre* _Nave)
{
    NaveE = Cast<ANaveTerrestre>(_Nave);
  /*  NaveE->EstablecerEstados(NaveE->GetEstadoEspacial());*/
}

void AEstadoEspacial::Disparar()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Disparando"));
}

//}