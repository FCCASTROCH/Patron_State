// Fill out your copyright notice in the Description page of Project Settings.


#include "Estrategia1.h"
#include "ProyectilE.h"
#include "NaveEspecial.h"
// Sets default values
AEstrategia1::AEstrategia1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategia1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategia1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategia1::Disparar(ANaveEspecial* especial)
{
	FVector posicion = especial->GetActorLocation();
	FRotator rotacion = especial->GetActorRotation();
	FVector offset = FVector(0, 100, 0);
	FVector posicionFinal = posicion + offset;
	FRotator rotacionFinal = rotacion;
	GetWorld()->SpawnActor<AProyectilE>(posicionFinal, rotacionFinal);
}
