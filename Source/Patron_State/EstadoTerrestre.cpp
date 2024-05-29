// Fill out your copyright notice in the Description page of Project Settings.

#include "EstadoTerrestre.h"
#include "NaveTerrestre.h"
#include "Engine/Engine.h"
// Sets default values
AEstadoTerrestre::AEstadoTerrestre()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TiempoDisparo = 0.5f;

	MoveSpeed = 60.0f;
	bIsMoving = true;

	TargetLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 194.0f);
}

// Called when the game starts or when spawned
void AEstadoTerrestre::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEstadoTerrestre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsMoving && NaveT)
	{
		FVector CurrentLocation = NaveT->GetActorLocation();
		FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
		NaveT->SetActorLocation(NewLocation);

		if (CurrentLocation.Equals(TargetLocation, 1.0f))
		{
			bIsMoving = false;
		}
	}
}

void AEstadoTerrestre::SetNaveTerrestre(ANaveTerrestre* _Nave)
{
	NaveT = Cast<ANaveTerrestre>(_Nave);
	//NaveT->EstablecerEstados(NaveT->GetEstadoTerrestre());
}

void AEstadoTerrestre::Mover(float DeltaTime)
{
	//// Definimos las variables necesarias
	//static float TiempoTotal = 0.0f; // Variable estática para acumular el tiempo
	//const float Radio = 300.0f; // Radio del círculo
	//const float VelocidadAngular = 1.0f; // Velocidad angular (radianes por segundo)

	//// Actualizamos el tiempo total acumulado
	//TiempoTotal += DeltaTime * VelocidadAngular;

	//// Calculamos la nueva posición en la circunferencia
	//float NuevaPosX = Radio * FMath::Cos(TiempoTotal);
	//float NuevaPosY = Radio * FMath::Sin(TiempoTotal);

	//// Obtenemos la posición actual del objeto
	//FVector PosicionActual = NaveT->GetActorLocation();

	//// Actualizamos solo las coordenadas X e Y, manteniendo la Z actual
	//FVector NuevaPosicion = FVector(NuevaPosX, NuevaPosY, PosicionActual.Z);

	//// Establecemos la nueva posición del objeto
	//NaveT->SetActorLocation(NuevaPosicion);
}

void AEstadoTerrestre::Disparar()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Disparando"));
}


//}