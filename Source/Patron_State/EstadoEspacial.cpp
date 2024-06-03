// Fill out your copyright notice in the Description page of Project Settings.

#include "EstadoEspacial.h"
#include "NaveTerrestre.h"
#include "ProyectilE.h"
#include "Kismet/GameplayStatics.h"
#include "Patron_StateProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"

// Sets default values

AEstadoEspacial::AEstadoEspacial()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    MaxProjectile = 18;
    NumberFired = 0;

    bCanFire = true; // 

    TiempoDisparo = 2.0f;
}

// Called when the game starts or when spawned
void AEstadoEspacial::BeginPlay()
{
    Super::BeginPlay();
    Radio = 1000.0f; // Radio del círculo
    Angulo = 0.0f;
    VelocidadAngular = FMath::DegreesToRadians(30.0f); // Velocidad angular en radianes por segundo (ejemplo: 30 grados por segundo)
    Centro = FVector(0.0f, 0.0f, 700.0f); // Centro del círculo

}

// Called every frame
void AEstadoEspacial::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AEstadoEspacial::SetNaveTerrestre(ANaveTerrestre* _Nave)
{
    NaveEs = Cast<ANaveTerrestre>(_Nave);
	
  //  NaveE->EstablecerEstados(NaveE->GetEstadoEspacial());

}

void AEstadoEspacial::Navegar()
{
	if (NaveEs->GetActorLocation().Z <= 700.0f)
	{
		NaveEs->SetActorLocation(FVector(NaveEs->GetActorLocation().X, NaveEs->GetActorLocation().Y, NaveEs->GetActorLocation().Z + 1));
		return;
	}
	// Actualiza el ángulo
	Angulo += VelocidadAngular * GetWorld()->GetDeltaSeconds();
	if (Angulo > 2 * PI)
	{
		Angulo -= 2 * PI; // Mantener el ángulo entre 0 y 2?
	}

	// Calcula la nueva posición usando coordenadas polares
	float X = Centro.X + Radio * FMath::Cos(Angulo);
	float Y = Centro.Y + Radio * FMath::Sin(Angulo);
	float Z = Centro.Z; // Mantener el mismo nivel si no quieres movimiento vertical

	FVector NuevaPosicion = FVector(X, Y, Z);
	NaveEs->SetActorLocation(NuevaPosicion);

	// Calcula la dirección del movimiento tangencial
	FVector Tangente = FVector(-FMath::Sin(Angulo), FMath::Cos(Angulo), 0.0f).GetSafeNormal();
	NaveEs->SetActorRotation(Tangente.Rotation());
	if (NaveEs->TiempoTranscurrido >= 10.0f)
	{
		NaveEs->EstablecerEstados(NaveEs->GetEstadoTerrestre());
		NaveEs->TiempoTranscurrido = 0.0f;
	}
}

void AEstadoEspacial::Disparar()
{
    if (bCanFire && NumberFired < MaxProjectile)
    {
        bCanFire = false;  

        // Obtener el jugador
        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        if (PlayerPawn)
        {
            UPJugador = PlayerPawn->GetActorLocation(); 
        }

        // creador de bombas
        UWorld* const World = GetWorld();
        if (World != NULL)
        {
            FVector Location = NaveEs->GetActorLocation();
            FRotator Rotation = NaveEs->GetActorRotation();
            AProyectilE* Proyectil = World->SpawnActor<AProyectilE>(Location, Rotation);
            if (Proyectil)
            {
                Proyectil->SetUltimaPosicionJugador(UPJugador); // Pasar la posición del jugador al proyectil
                Proyectil->SetActorRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));
            }
            NumberFired++;

            // Establecer el temporizador para el próximo disparo
            FTimerHandle TimerHandle;
            GetWorldTimerManager().SetTimer(TimerHandle, this, &AEstadoEspacial::ResetCanFire, TiempoDisparo, false); //cambiar cada cuantoo habrán bombas
        }
    }
 
}
void AEstadoEspacial::ResetCanFire()
{
    bCanFire = true;
}
FString AEstadoEspacial::Estado()
{
    return "Estado Espacial";
}
