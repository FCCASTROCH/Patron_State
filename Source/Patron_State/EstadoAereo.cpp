// Fill out your copyright notice in the Description page of Project Settings.

// EstadoAereo.cpp

#include "EstadoAereo.h"
#include "NaveTerrestre.h"

AEstadoAereo::AEstadoAereo()
{
    PrimaryActorTick.bCanEverTick = true;
    TargetLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 314.0f);
    bIsMoving = false;
    MoveSpeed = 10.0f;
}

void AEstadoAereo::BeginPlay()
{
    Super::BeginPlay();
}

void AEstadoAereo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsMoving && NaveA)
    {
        FVector CurrentLocation = NaveA->GetActorLocation();
        FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
        NaveA->SetActorLocation(NewLocation);

        if (CurrentLocation.Equals(TargetLocation, 1.0f))
        {
            bIsMoving = false;
        }
    }
}

void AEstadoAereo::EstadoActual()
{
  //  UE_LOG(LogTemp, Warning, TEXT("Estado Actual: Aéreo"));
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Estado Actual: Aereo"));
}

void AEstadoAereo::EstadoTerrestre()
{
    if (NaveA)
    {

        NaveA->SetEstadoTerrestre();
       
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Cambiando al estado terrestre desde el estado aereo"));
    }
}

void AEstadoAereo::EstadoAereo()
{
    if (NaveA)
    {
        TargetLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 300);
        bIsMoving = true;
    }
}

void AEstadoAereo::EstadoEspacial()
{
    if (NaveA)
    {
        NaveA->SetEstadoEspacial();
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Cambiando al estado espacial desde el estado aereo"));
    }
}

void AEstadoAereo::setNaveTerrestre(ANaveTerrestre* nave)
{
    //
    NaveA = nave;
}
