// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoEspacial.h"
#include "NaveTerrestre.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "EstadoTerrestre.h"
#include "EstadoAereo.h"
#include "ProyectilE.h"
#include "Engine/World.h"
// Sets default values
AEstadoEspacial::AEstadoEspacial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

void AEstadoEspacial::EstadoActual()
{
    UE_LOG(LogTemp, Warning, TEXT("Estado Actual: Espacial"));

}
void AEstadoEspacial::EstadoTerrestre()
{
    if (NaveE)
    {
        NaveE->SetEstadoTerrestre();
        UE_LOG(LogTemp, Warning, TEXT("Cambiando al estado terrestre desde el estado espacial"));
    }
}

void AEstadoEspacial::EstadoAereo()
{
    if (NaveE)
    {
        NaveE->SetEstadoAereo();
        UE_LOG(LogTemp, Warning, TEXT("Cambiando al estado aéreo desde el estado espacial"));
    }
}

void AEstadoEspacial::EstadoEspacial()
{
    if (NaveE)
    {
        TargetLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 614);
        bIsMoving = true;
    }
}

void AEstadoEspacial::setNaveTerrestre(ANaveTerrestre* nave)
{
    NaveE = nave;
}