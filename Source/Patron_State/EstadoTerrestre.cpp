// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoTerrestre.h"
#include "NaveTerrestre.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "EstadoTerrestre.h"
#include "EstadoAereo.h"
#include "ProyectilE.h"
#include "Engine/World.h"

AEstadoTerrestre::AEstadoTerrestre()
{
    PrimaryActorTick.bCanEverTick = true;
    TargetLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 154);
    bIsMoving = false;
    MoveSpeed = 10.0f;
}

void AEstadoTerrestre::BeginPlay()
{
    Super::BeginPlay();
}

void AEstadoTerrestre::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsMoving && NaveT)
    {
        FVector CurrentLocation = NaveT->GetActorLocation();
        FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
        NaveT->SetActorLocation(NewLocation);

        if (CurrentLocation.Equals(TargetLocation, 1.0f))
        {
            bIsMoving = false;
        }
    }
}

void AEstadoTerrestre::EstadoActual()
{
    UE_LOG(LogTemp, Warning, TEXT("Estado Actual: Terrestre"));
}
void AEstadoTerrestre::EstadoTerrestre()
{
    if (NaveT)
    {
        TargetLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 154);
        bIsMoving = true;
    }
}

void AEstadoTerrestre::EstadoAereo()
{
    if (NaveT)
    {
        NaveT->SetEstadoAereo();
      //  UE_LOG(LogTemp, Warning, TEXT("Cambiando al estado aéreo desde el estado terrestre"));
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Cambiando al estado aereo desde el estado terrestre"));


    }
}


void AEstadoTerrestre::EstadoEspacial()
{
    if (NaveT)
    {
        NaveT->SetEstadoEspacial();
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Cambiando al estado espacial desde el estado terrestre"));
        //UE_LOG(LogTemp, Warning, TEXT("Cambiando al estado espacial desde el estado terrestre"));
    }
}

void AEstadoTerrestre::setNaveTerrestre(ANaveTerrestre* nave)
{
    NaveT = nave;
}