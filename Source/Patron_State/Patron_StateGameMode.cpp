// Copyright Epic Games, Inc. All Rights Reserved.

#include "Patron_StateGameMode.h"
#include "Patron_StatePawn.h"
#include "NaveTerrestre.h"
#include "EstadoTerrestre.h"
#include "EstadoAereo.h"
#include "EstadoEspacial.h"
#include "Escaner.h"
#include "Estrategia1.h"
#include "Estrategia2.h"
#include "Estrategia3.h"
#include "NaveTerrestreEspecial.h"
#include "NaveTerrestreModificado.h"
#include "NaveEspecial.h"
#include "Engine/World.h"
APatron_StateGameMode::APatron_StateGameMode()
{
	// set default pawn class to our character class
    PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = APatron_StatePawn::StaticClass();
    VidaPromedio = 0.0f; // Variable para controlar la vida promedio de las naves
    CurrentStrategyIndex = 0;
    ElapsedTime = 0.0f;
}
void APatron_StateGameMode::BeginPlay()
{
    Super::BeginPlay();
    //declarar
    Estartega3 = GetWorld()->SpawnActor<AEstrategia3>(AEstrategia3::StaticClass());
    Estartega2 = GetWorld()->SpawnActor<AEstrategia2>(AEstrategia2::StaticClass());
    startega1 = GetWorld()->SpawnActor<AEstrategia1>(AEstrategia1::StaticClass());
    

    naveEspecial = GetWorld()->SpawnActor<ANaveEspecial>(ANaveEspecial::StaticClass());
    naveEspecial->SetActorLocation(FVector(100.0f, 100.0f, 300.0f));
   

    //state
    Nave = GetWorld()->SpawnActor<ANaveTerrestre>(ANaveTerrestre::StaticClass());
    Nave->SetActorLocation(FVector(-800.0f, 500.0f, 200.0f));


  

}
void APatron_StateGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //Estados de la nave
    Nave->Manejar();
    Nave->Volar();
    Nave->Navegar();
    Nave->Disparar();
    //estrategias de la nave
    naveEspecial->CambiarEstrategia(Estartega3);
 
  /*  naveEspecial->CambiarEstrategia(Estartega2);
    naveEspecial->CambiarEstrategia(startega1);*/
    naveEspecial->EjecutarEstrategia();

}

void APatron_StateGameMode::CambiarYEjecutarEstrategia()
{
    switch (CurrentStrategyIndex)
    {
    case 0:
        naveEspecial->CambiarEstrategia(Estartega3);
        break;
    case 1:
        naveEspecial->CambiarEstrategia(Estartega2);
        break;
    case 2:
        naveEspecial->CambiarEstrategia(startega1);
        break;
    }    
}




//
void APatron_StateGameMode::cambiarEstrategia2()
{
    naveM->CambiarEstrategia(Estartega2);
    naveM->EjecutarEstrategia();
}

void APatron_StateGameMode::cambiarEstrategia3()
{
    naveM->CambiarEstrategia(Estartega3);
    naveM->EjecutarEstrategia();
}

void APatron_StateGameMode::cambiarEstrategia1()
{
    naveM->CambiarEstrategia(startega1);
    naveM->EjecutarEstrategia();
}

