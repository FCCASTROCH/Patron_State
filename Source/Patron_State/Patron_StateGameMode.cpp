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
   
    NaveTerrestre = GetWorld()->SpawnActor<ANaveTerrestre>(FVector(1000.0f, 0.0f, 215.0f), FRotator::ZeroRotator);

    NaveTerrestre->Inicializar(0.0f);
}

void APatron_StateGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    TiempoTranscurrido += DeltaTime;
    if (TiempoTranscurrido >= 10.0f)
    {
     //   AlternarEstados();
        TiempoTranscurrido = 0.0f;
    }
}

//void APatron_StateGameMode::AlternarEstados()
//{
//    if (NaveTerrestre)
//    {
//        FString CurrentState = NaveTerrestre->GetCurrentState();
//
//        if (CurrentState == "ninguno")
//        {
//            NaveTerrestre->GetEstadoTerrestre();
//            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Cambiando al estado terrestre"));
//        }
//        else if (CurrentState == "Terrestre")
//        {
//            NaveTerrestre->GetEstadoAereo();
//            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Cambiando al estado aereo"));
//        }
//        else if (CurrentState == "Aereo")
//        {
//            NaveTerrestre->GetEstadoEspacial();
//            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Cambiando al estado espacial"));
//        }
//        else if (CurrentState == "Espacial")
//        {
//            NaveTerrestre->GetEstadoTerrestre();
//            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Cambiando al estado terrestre"));
//        }
//    }
//}
