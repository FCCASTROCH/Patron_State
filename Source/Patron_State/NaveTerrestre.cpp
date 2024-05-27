// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveTerrestre.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "EstadoTerrestre.h"
#include "EstadoAereo.h"
#include "EstadoEspacial.h"
#include "ProyectilE.h"
#include "Engine/World.h"
// Sets default values
ANaveTerrestre::ANaveTerrestre()
{
    PrimaryActorTick.bCanEverTick = true;
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshNaveEnemigocaza1(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));

    NaveEnemigoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
    NaveEnemigoMesh->SetupAttachment(RootComponent);
    RootComponent = NaveEnemigoMesh;

    NaveEnemigoMesh->SetStaticMesh(MeshNaveEnemigocaza1.Object);

    Velocidad = 2.0f;
    Tiempo_Disparo = 5.0f;
    Tiempo_M = 0.f;
    Distancia_D_CB = 200.f;
    Tiempo_Disparo_Generar = 5.0f;
    CurrentState = "ninguno";
    Timer = 5.0f;
    TiempoTranscurrido = 10.0f;
}

void ANaveTerrestre::BeginPlay()
{
    Super::BeginPlay();

    EstadoTerrestre = GetWorld()->SpawnActor<AEstadoTerrestre>(AEstadoTerrestre::StaticClass());
    EstadoAereo = GetWorld()->SpawnActor<AEstadoAereo>(AEstadoAereo::StaticClass());
    EstadoEspacial = GetWorld()->SpawnActor<AEstadoEspacial>(AEstadoEspacial::StaticClass());

    if (EstadoTerrestre && EstadoAereo && EstadoEspacial)
    {
        EstadoTerrestre->setNaveTerrestre(this);
        EstadoAereo->setNaveTerrestre(this);
        EstadoEspacial->setNaveTerrestre(this);
    }
}

void ANaveTerrestre::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (EstadoActual)
    {
        EstadoActual->EstadoActual();
    }
}

void ANaveTerrestre::Mover(float DeltaTime) {
    // Obtiene la posición actual del actor
    FVector PosicionActual = GetActorLocation();

    // Parámetros para simular el movimiento de la cometa
    float VelocidadBase = 50.0f; // Velocidad base de la cometa
    float Amplitud = 100.0f; // Amplitud de la oscilación
    float Frecuencia = 0.5f; // Frecuencia de la oscilación
    float RandomFactor = FMath::FRandRange(-20.0f, 20.0f); // Factor aleatorio para variación
    float AlturaBase = 300.0f; // Altura base para el movimiento de la cometa

    // Calcula las nuevas posiciones en X e Y
    float NewX = PosicionActual.X - VelocidadBase * DeltaTime;
    float NewY = PosicionActual.Y + Amplitud * FMath::Sin(TiempoTranscurrido * Frecuencia) + RandomFactor;
    float NewZ = AlturaBase + Amplitud * FMath::Cos(TiempoTranscurrido * Frecuencia / 2) + RandomFactor;

    // Actualiza el tiempo transcurrido
    TiempoTranscurrido += DeltaTime;

    // Actualiza la posición del actor
    SetActorLocation(FVector(NewX, NewY, NewZ));

    // Verifica los límites de la pantalla y ajusta la posición si es necesario
    if (GetActorLocation().X <= -1800.0f) {
        SetActorLocation(FVector(1850.0f, NewY, NewZ));
    }
    if (GetActorLocation().Y >= 1850) {
        SetActorLocation(FVector(NewX, -1850.0f, NewZ));
    }
    if (GetActorLocation().Y <= -1850) {
        SetActorLocation(FVector(NewX, 1850.0f, NewZ));
    }
    if (GetActorLocation().Z <= 0) {
        SetActorLocation(FVector(NewX, NewY, AlturaBase));
    }
}
void ANaveTerrestre::Disparo_Nave(float DeltaTime)
{
    Tiempo_Disparo += DeltaTime;
    if (Tiempo_Disparo >= Tiempo_Disparo_Generar)
    {
        Tiempo_Disparo = 0.0f;

        // Configura la dirección hacia el eje X negativo
        FVector Direction = FVector(-1.0f, 0.0f, 0.0f);  // Dirección negativa en X
        FVector SpawnLocation = GetActorLocation() + (Direction * Distancia_D_CB);  // Calcula la nueva ubicación de generación basada en la distancia configurada

        FRotator FireRotation = Direction.Rotation();  // Asegura que la rotación del proyectil coincida con la dirección

        UWorld* const World = GetWorld();
        if (World)
        {
            AProyectilE* Proyectil = World->SpawnActor<AProyectilE>(AProyectilE::StaticClass(), SpawnLocation, FireRotation);
            if (Proyectil)
            {
               // Proyectil->Set_Danio(Danio_Disparo);
                Proyectil->FireInDiagonal();
            }
        }
    }
}
void ANaveTerrestre::SetEstadoTerrestre()
{
    if (EstadoTerrestre)
    {
        EstadoActual = EstadoTerrestre;
        EstadoActual->EstadoTerrestre();
        CurrentState = "Terrestre";
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Estado cambiado a Terrestre"));
      
    }
}

void ANaveTerrestre::SetEstadoAereo()
{
    if (EstadoAereo)
    {
        EstadoActual = EstadoAereo;
        EstadoActual->EstadoAereo();
        CurrentState = "Aereo";
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Estado cambiado a Aereo"));
    }
}
void ANaveTerrestre::SetEstadoEspacial()
{
    if (EstadoEspacial)
    {
        EstadoActual = EstadoEspacial;
        EstadoActual->EstadoEspacial();
        //implementamos


        CurrentState = "Espacial";
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Estado cambiado a Espacial"));
    }
}
FString ANaveTerrestre::GetCurrentState() const
{
    return CurrentState;
}