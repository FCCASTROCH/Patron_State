// Copyright Epic Games, Inc. All Rights Reserved.

#include "Patron_StateGameMode.h"
#include "Patron_StatePawn.h"
#include "NaveTerrestre.h"
#include "EstadoTerrestre.h"
#include "EstadoAereo.h"
#include "EstadoEspacial.h"
#include "Escaner.h"
#include "NaveTerrestreEspecial.h"
#include "NaveTerrestreModificado.h"
#include "Engine/World.h"
APatron_StateGameMode::APatron_StateGameMode()
{
	// set default pawn class to our character class
    PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = APatron_StatePawn::StaticClass();
    VidaPromedio = 0.0f; // Variable para controlar la vida promedio de las naves
   
}
void APatron_StateGameMode::BeginPlay()
{
    Super::BeginPlay();
    crearNave();
}
void APatron_StateGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
        
        Nave->Manejar();
        Nave->Volar();
        Nave->Navegar();
        Nave->Disparar();
      
}

void APatron_StateGameMode::crearNave()
{
    Nave = GetWorld()->SpawnActor<ANaveTerrestre>(ANaveTerrestre::StaticClass());
    Nave->SetActorLocation(FVector(-800.0f, 500.0f, 200.0f));

  
  //  Nave->inicializar();
   
}

