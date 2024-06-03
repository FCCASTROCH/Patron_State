// Fill out your copyright notice in the Description page of Project Settings.

#include "EstadoTerrestre.h"
#include "NaveTerrestre.h"
#include "Engine/Engine.h"
AEstadoTerrestre::AEstadoTerrestre()
{
    // Establecer el tick para este actor
    PrimaryActorTick.bCanEverTick = true;
}

void AEstadoTerrestre::BeginPlay()
{
    Super::BeginPlay();
    DireccionMovimiento = FVector(1.0f, 0.0f, 0.0f);
    DistanciaRecorrida = 0.0f;
    LongitudLadoCuadrado = 300.0f;
    VelocidadMovimiento = 100.0f;

}

void AEstadoTerrestre::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

   
}

void AEstadoTerrestre::SetNaveTerrestre(ANaveTerrestre* _Nave)
{
    NaveT = Cast<ANaveTerrestre>(_Nave);
	//NaveT->EstablecerEstados(NaveT->GetEstadoTerrestre());
	//NaveT->Set
}

void AEstadoTerrestre::Conducir()
{
	if (NaveT->GetActorLocation().Z > 214.0f)
	{
		NaveT->SetActorLocation(FVector(NaveT->GetActorLocation().X, NaveT->GetActorLocation().Y, NaveT->GetActorLocation().Z - 1));
		return;
	}
	// Actualiza la posición del vehículo
	FVector NuevaPosicion = NaveT->GetActorLocation() + (DireccionMovimiento * VelocidadMovimiento * GetWorld()->GetDeltaSeconds());
	NaveT->SetActorLocation(NuevaPosicion);

	DistanciaRecorrida += (DireccionMovimiento * VelocidadMovimiento * GetWorld()->GetDeltaSeconds()).Size();

	// Cambia de dirección cuando se alcanza la longitud del lado del cuadrado
	if (DistanciaRecorrida >= LongitudLadoCuadrado)
	{
		DistanciaRecorrida = 0.0f;
		// Cambia la dirección del movimiento en sentido horario
		if (DireccionMovimiento == FVector(1.0f, 0.0f, 0.0f))
		{
			DireccionMovimiento = FVector(0.0f, 1.0f, 0.0f); // Mueve hacia adelante en el eje Y
		}
		else if (DireccionMovimiento == FVector(0.0f, 1.0f, 0.0f))
		{
			DireccionMovimiento = FVector(-1.0f, 0.0f, 0.0f); // Mueve hacia atrás en el eje X
		}
		else if (DireccionMovimiento == FVector(-1.0f, 0.0f, 0.0f))
		{
			DireccionMovimiento = FVector(0.0f, -1.0f, 0.0f); // Mueve hacia atrás en el eje Y
		}
		else if (DireccionMovimiento == FVector(0.0f, -1.0f, 0.0f))
		{
			DireccionMovimiento = FVector(1.0f, 0.0f, 0.0f); // Mueve hacia adelante en el eje X
		}
	}
	NaveT->SetActorRotation(DireccionMovimiento.Rotation());
	if (NaveT->TiempoTranscurrido >= 10.0f)
	{
		NaveT->EstablecerEstados(NaveT->GetEstadoAereo());
		NaveT->TiempoTranscurrido = 0.0f;
	}

	
}

void AEstadoTerrestre::Disparar()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Disparando terresrtre"));
}

FString AEstadoTerrestre::Estado()
{
    return "Estado Terrestre";
}


