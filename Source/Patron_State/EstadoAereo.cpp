// Fill out your copyright notice in the Description page of Project Settings.
#include "EstadoAereo.h"
#include "NaveTerrestre.h"
#include "Patron_StatePawn.h"
#include "Patron_StateProjectile.h"
#include "Engine/Engine.h"

AEstadoAereo::AEstadoAereo()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GunOffset = FVector(90.f, 0.f, 0.f);
	TiempoDisparo = 0.5f;
	bCanFire = true;
}

// Called when the game starts or when spawned
void AEstadoAereo::BeginPlay()
{
	Super::BeginPlay();

	VerticesTriangulo.Add(FVector(0.0f, 0.0f, 0.0f)); // Vértice 1
	VerticesTriangulo.Add(FVector(1850.0f, 0.0f, 0.0f)); // Vértice 2
	VerticesTriangulo.Add(FVector(800.0f, 1000.0f, 0.0f)); // Vértice 3 (aproximadamente altura de un triángulo equilátero)
	VerticeActual = 0;
	DireccionMovimiento = (VerticesTriangulo[1] - VerticesTriangulo[0]).GetSafeNormal();
	DistanciaRecorrida = 0.0f;
	VelocidadMovimiento = 200.0f; // Velocidad del movimiento del vehículo
}

// Called every frame
void AEstadoAereo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AEstadoAereo::SetNaveTerrestre(ANaveTerrestre* _NaveNodriza)
{
	NaveAe = Cast<ANaveTerrestre>(_NaveNodriza);
	//NaveAe = _NaveNodriza;
	//NaveA->EstablecerEstados(NaveA->GetEstadoAereo());
}

void AEstadoAereo::Volar()
{
	if (NaveAe->GetActorLocation().Z <= 500.0f)
	{
		NaveAe->SetActorLocation(FVector(NaveAe->GetActorLocation().X, NaveAe->GetActorLocation().Y, NaveAe->GetActorLocation().Z + 1));
		return;
	}
	FVector NuevaPosicion = NaveAe->GetActorLocation() + (DireccionMovimiento * VelocidadMovimiento * GetWorld()->GetDeltaSeconds());
	NaveAe->SetActorLocation(NuevaPosicion);

	DistanciaRecorrida += (DireccionMovimiento * VelocidadMovimiento * GetWorld()->GetDeltaSeconds()).Size();

	// Cambia de dirección cuando se alcanza la distancia al siguiente vértice
	if (DistanciaRecorrida >= (VerticesTriangulo[(VerticeActual + 1) % 3] - VerticesTriangulo[VerticeActual]).Size())
	{
		DistanciaRecorrida = 0.0f;
		VerticeActual = (VerticeActual + 1) % 3;
		DireccionMovimiento = (VerticesTriangulo[(VerticeActual + 1) % 3] - VerticesTriangulo[VerticeActual]).GetSafeNormal();
	}
	NaveAe->SetActorRotation(DireccionMovimiento.Rotation());

	if (NaveAe->TiempoTranscurrido >= 10.0f)
	{
		NaveAe->EstablecerEstados(NaveAe->GetEstadoEspacial());
		NaveAe->TiempoTranscurrido = 0.0f;
	}
}

void AEstadoAereo::Disparar()
{
	FVector FireDirection = NaveAe->GetActorForwardVector();
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				for (int i = 0; i < 3; i++)
				{
					float grado = 90.0f / 4;
					FireDirection = FireDirection.RotateAngleAxis(grado * i, FVector(0.0f, 0.0f, 1.0f));
					const FRotator FireRotation = FireDirection.Rotation();
					const FVector SpawnLocation = NaveAe->GetActorLocation() + FireRotation.RotateVector(GunOffset);
					World->SpawnActor<APatron_StateProjectile>(SpawnLocation, FireRotation);
					bCanFire = false;
					World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEstadoAereo::ShotTimerExpired, TiempoDisparo);
				}
			}
			bCanFire = false;
		}
	}
}
void AEstadoAereo::ShotTimerExpired()
{
	bCanFire = true;
}
FString AEstadoAereo::Estado()
{
	return "Estado Aereo";
}


