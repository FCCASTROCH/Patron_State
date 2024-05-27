// Copyright Epic Games, Inc. All Rights Reserved.

#include "Patron_StateGameMode.h"
#include "Patron_StatePawn.h"
#include "NaveTerrestre.h"
#include "EstadoTerrestre.h"
#include "EstadoAereo.h"
#include "EstadoEspacial.h"
#include "Engine/World.h"
APatron_StateGameMode::APatron_StateGameMode()
{
	// set default pawn class to our character class
    PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = APatron_StatePawn::StaticClass();
    bEstadoInicial = true; // Variable para controlar el estado inicial
    TiempoTranscurrido = 0.0f; // Variable para controlar el tiempo transcurrido

}
void APatron_StateGameMode::BeginPlay()
{
    Super::BeginPlay();
    //FVector SpawnLocation = FVector(0.0f, 0.0f, 114.0f);
    //FRotator SpawnRotation = FRotator::ZeroRotator;
    //FActorSpawnParameters SpawnParams;

    //NaveTerrestre = GetWorld()->SpawnActor<ANaveTerrestre>(ANaveTerrestre::StaticClass(), SpawnLocation, SpawnRotation, SpawnParams);

    //if (NaveTerrestre)
    //{
    //    GetWorldTimerManager().SetTimer(EstadoTimerHandle, this, &APatron_StateGameMode::AlternarEstados, 10.0f, true);
    //}
    NaveTerrestre = GetWorld()->SpawnActor<ANaveTerrestre>(ANaveTerrestre::StaticClass(),FVector(0,0,214),FRotator(0,0,0));
    if (NaveTerrestre)
    {
        NaveTerrestre->SetEstadoTerrestre();
    }
}

void APatron_StateGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    TiempoTranscurrido += DeltaTime;
    if (TiempoTranscurrido >= 10.0f)
    {
        AlternarEstados();
        TiempoTranscurrido = 0.0f;
    }
}

void APatron_StateGameMode::AlternarEstados()
{
    if (NaveTerrestre)
    {
        FString CurrentState = NaveTerrestre->GetCurrentState();

        if (CurrentState == "ninguno")
        {
            NaveTerrestre->SetEstadoTerrestre();
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Cambiando al estado terrestre"));
        }
        else if (CurrentState == "Terrestre")
        {
            NaveTerrestre->SetEstadoAereo();
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Cambiando al estado aereo"));
        }
        else if (CurrentState == "Aereo")
        {
            NaveTerrestre->SetEstadoEspacial();
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Cambiando al estado espacial"));
        }
        else if (CurrentState == "Espacial")
        {
            NaveTerrestre->SetEstadoTerrestre();
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Cambiando al estado terrestre"));
        }
    }
}
