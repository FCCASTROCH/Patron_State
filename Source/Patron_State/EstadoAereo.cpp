// Fill out your copyright notice in the Description page of Project Settings.
#include "EstadoAereo.h"
#include "NaveTerrestre.h"
#include "Engine/Engine.h"

AEstadoAereo::AEstadoAereo()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	velocidad = 0.5f;
	TargetLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 314.0f);
	bIsMoving = true;
	MoveSpeed = 20.0f;
}

// Called when the game starts or when spawned
void AEstadoAereo::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEstadoAereo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsMoving && NaveA)
	{
		FVector CurrentLocation = NaveA->GetActorLocation();
		FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
		NaveA->SetActorLocation(NewLocation);

		if (CurrentLocation.Equals(TargetLocation, 1.0f))
		{
			bIsMoving = false;
		}
	}
}

void AEstadoAereo::SetNaveTerrestre(ANaveTerrestre* _NaveNodriza)
{
	NaveA = Cast<ANaveTerrestre>(_NaveNodriza);
	NaveA->EstablecerEstados(NaveA->GetEstadoAereo());
}

void AEstadoAereo::Mover(float DeltaTime)
{
	//float Amplitud = 2.0f;
	//float Frecuencia = 1.0f;
	//float Tiempo = GetWorld()->GetTimeSeconds();  // Obtener el tiempo actual del juego

	//// Obtener la ubicación actual del actor
	//FVector Coordenada = NaveA->GetActorLocation();

	//// Calcular el desplazamiento en zigzag en el eje Y
	//float ZigZagY = FMath::Sin(Tiempo * Frecuencia) * Amplitud;

	//// Calcular la nueva ubicación
	//FVector NewLocation = FVector(Coordenada.X - velocidad + ZigZagY * DeltaTime, Coordenada.Y + ZigZagY, GetActorLocation().Z);

	//// Establecer la nueva ubicación del actor
	//NaveA->SetActorLocation(NewLocation);
}
