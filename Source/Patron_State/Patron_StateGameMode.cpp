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
    bEstadoInicial = true; // Variable para controlar el estado inicial
    TiempoTranscurrido = 0.0f; // Variable para controlar el tiempo transcurrido
    VidaPromedio = 0.0f; // Variable para controlar la vida promedio de las naves

}
void APatron_StateGameMode::BeginPlay()
{
    Super::BeginPlay();
   
  /*  NaveTerrestre = GetWorld()->SpawnActor<ANaveTerrestre>(ANaveTerrestre::StaticClass());
    NaveTerrestre->Inicializar();*/
       /*  Radar = GetWorld()->SpawnActor<AEscaner>(AEscaner::StaticClass());
   
        NaveModificado= GetWorld()->SpawnActor<ANaveTerrestreModificado>(ANaveTerrestreModificado::StaticClass());
        NaveModificado->EstablecerRadar(Radar);
        NaveModificado->SetActorLocation(FVector(0.0f, 500.0f, 200.0f));
        Naves.Add(NaveModificado);*/
    
      //  NaveEspecial = GetWorld()->SpawnActor< ANaveTerrestreEspecial>(ANaveTerrestreEspecial::StaticClass());
      //  NaveEspecial->QuitarSuscripcion();
      //  NaveEspecial->SetActorLocation(FVector(100.0f, 100.0f, 200.0f));
      ////  NaveEspecial->EstablecerRadar(Radar);
      //  Naves.Add(NaveEspecial);

        Radar = GetWorld()->SpawnActor<AEscaner>(AEscaner::StaticClass());

        ubicacionInicialNavesCazas = FVector(1000.0f, -150.0f, 200.0f);
        ubicacionInicialNavesTanques = FVector(800.0f, -150.0f, 200.0f);
        ubicacionInicialNavesFugaces = FVector(1200.0f, -450.0f, 200.0f);

        // Generar Naves Fugaces en las esquinas
        for (int i = 0; i < 2; i++) {
            FVector PosicionNaveActual = FVector(ubicacionInicialNavesFugaces.X, ubicacionInicialNavesFugaces.Y + i * 1200, ubicacionInicialNavesFugaces.Z);
            NaveEspecial = GetWorld()->SpawnActor<ANaveTerrestreEspecial>(PosicionNaveActual, FRotator::ZeroRotator);
            NaveEspecial->EstablecerRadar(Radar);
            Naves.Add(NaveEspecial);
        }

        // Generar Naves Tanques
        for (int i = 0; i < 2; i++) {
            FVector PosicionNaveActual = FVector(ubicacionInicialNavesTanques.X, ubicacionInicialNavesTanques.Y + i * 500, ubicacionInicialNavesTanques.Z);
            NaveModificado = GetWorld()->SpawnActor<ANaveTerrestreModificado>(PosicionNaveActual, FRotator::ZeroRotator);
            NaveModificado->EstablecerRadar(Radar);
            Naves.Add(NaveModificado);
        }
}

void APatron_StateGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    for (int i = 0; i < Naves.Num(); i++)
    {
        VidaPromedio = (Naves[i]->Vida + VidaPromedio / Naves.Num());
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Vida Promedio: %f"), VidaPromedio));
        if (VidaPromedio < 50)
        {
            Radar->SetVidaPromedio(10);
        }
        if (i == Naves.Num())
        {
            VidaPromedio = 0;
        }

    }
 /////*   TiempoTranscurrido += DeltaTime;
 ////   if (TiempoTranscurrido >= 10.0f)
 ////   {
 ////       NaveTerrestre->CurrentStateIndex = (NaveTerrestre->CurrentStateIndex + 1) % 3;
 ////       NaveTerrestre->Inicializar();
 ////       TiempoTranscurrido = 0.0f;
 ////   }*/
    //TiempoTranscurrido += DeltaTime;
    //if (TiempoTranscurrido >= 10.0f)
    //{
    // //   AlternarEstados();
    //    TiempoTranscurrido = 0.0f;
    //}
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
