// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveTerrestre.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "EstadoTerrestre.h"
#include "EstadoAereo.h"
#include "EstadoEspacial.h"
#include "Estado.h"
#include "ProyectilE.h"
#include "Engine/World.h"

ANaveTerrestre::ANaveTerrestre()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	NaveNodrizaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	NaveNodrizaMesh->SetStaticMesh(ShipMesh.Object);
	GetActorRelativeScale3D();
	SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
	vida = 200;
	time = 0.0f;
	vida = 200;
	time = 0.0f;
	StateChangeInterval = 10.0f;
	CurrentStateIndex = 0;
}

// Called when the game starts or when spawned
void ANaveTerrestre::BeginPlay()
{
	Super::BeginPlay();

	EstadoAereo = GetWorld()->SpawnActor<AEstadoAereo>(AEstadoAereo::StaticClass());
	EstadoTerrestre = GetWorld()->SpawnActor<AEstadoTerrestre>(	AEstadoTerrestre::StaticClass());
	EstadoEspacial = GetWorld()->SpawnActor<AEstadoEspacial>(AEstadoEspacial::StaticClass());

	Inicializar(0.0f);
}

// Called every frame
void ANaveTerrestre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Disparar();
	Mover(DeltaTime);
	time += DeltaTime;
	if (time >= StateChangeInterval)
	{
		time = 0.0f;
		CurrentStateIndex = (CurrentStateIndex + 1) % 3;
		Inicializar(0.0f);
	}
}

void ANaveTerrestre::RecibirDanio()
{
	vida -= 25;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vida: " + FString::SanitizeFloat(vida)));
	if (vida <= 0)
	{
		Destroy();
	}

}

void ANaveTerrestre::Inicializar(float DeltaTime)
{
	switch (CurrentStateIndex)
	{
	case 0:
		EstadoTerrestre->SetNaveTerrestre(this);
		EstablecerEstados(EstadoTerrestre);
		break;
	case 1:
		EstadoAereo->SetNaveTerrestre(this);
		EstablecerEstados(EstadoAereo);
		break;
	case 2:
		EstadoEspacial->SetNaveTerrestre(this);
		EstablecerEstados(EstadoEspacial);
		break;
	}
}


void ANaveTerrestre::EstablecerEstados(IEstado* _Estado)
{
    Estado = _Estado;
}

void ANaveTerrestre::Mover(float DeltaTime)
{
    Estado->Mover(DeltaTime);
}

void ANaveTerrestre::Disparar()
{
    Estado->Disparar();
}

IEstado* ANaveTerrestre::GetEstado()
{
    return Estado;
}

IEstado* ANaveTerrestre::GetEstadoEspacial()
{
    return EstadoEspacial;
}

IEstado* ANaveTerrestre::GetEstadoAereo()
{
    return EstadoAereo;
}

IEstado* ANaveTerrestre::GetEstadoTerrestre()
{
    return EstadoTerrestre;
}
