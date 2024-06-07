// Fill out your copyright notice in the Description page of Project Settings.


#include "Estrategia2.h"
#include "Patron_StatePawn.h"
#include "NaveEspecial.h"
#include "ProyectilE.h"
#include "Patron_StateProjectile.h"
// Sets default values
AEstrategia2::AEstrategia2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategia2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategia2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEstrategia2::Disparar(ANaveEspecial* especial)
{
	FVector posicion = especial->GetActorLocation();
	FRotator rotacion = especial->GetActorRotation();
	FVector offset = FVector(0, 100, 0);
	FVector posicionFinal = posicion + offset;
	FRotator rotacionFinal = rotacion;

	GetWorld()->SpawnActor<APatron_StateProjectile>(posicionFinal, rotacionFinal);
}

