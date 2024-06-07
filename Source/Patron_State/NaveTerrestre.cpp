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
#include "Escaner.h"
#include "Patron_StateGameMode.h"

ANaveTerrestre::ANaveTerrestre()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	NaveTrestreP = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	NaveTrestreP->SetStaticMesh(ShipMesh.Object);
	RootComponent = NaveTrestreP;
	TiempoTranscurrido = 0.0f;

}

// Called when the game starts or when spawned
void ANaveTerrestre::BeginPlay()
{
	Super::BeginPlay();
	EstadoTerrestre = GetWorld()->SpawnActor<AEstadoTerrestre>(AEstadoTerrestre::StaticClass());
	EstadoAereo = GetWorld()->SpawnActor<AEstadoAereo>(AEstadoAereo::StaticClass());
	EstadoEspacial = GetWorld()->SpawnActor<AEstadoEspacial>(AEstadoEspacial::StaticClass());

	Estado = EstadoTerrestre;
	//opcional
	inicializar();
}

// Called every frame
void ANaveTerrestre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TiempoTranscurrido += DeltaTime;
}

void ANaveTerrestre::inicializar()
{
		//EstadoTerrestre = GetWorld()->SpawnActor<AEstadoTerrestre>(AEstadoTerrestre::StaticClass());
    
		EstadoTerrestre->SetNaveTerrestre(this);
		EstablecerEstados(EstadoAereo);
	
	//EstadoAereo = GetWorld()->SpawnActor<AEstadoAereo>(AEstadoAereo::StaticClass());
	EstadoAereo->SetNaveTerrestre(this);
	EstablecerEstados(EstadoEspacial);
    
	//	EstadoEspacial = GetWorld()->SpawnActor<AEstadoEspacial>(AEstadoEspacial::StaticClass());
		EstadoEspacial->SetNaveTerrestre(this);
		EstablecerEstados(EstadoTerrestre);
		
	//Estado = EstadoTerrestre;
}

void ANaveTerrestre::Manejar()
{
	Estado->Conducir();
}

void ANaveTerrestre::Volar()
{
	Estado->Volar();
}

void ANaveTerrestre::Navegar()
{
	Estado->Navegar();
}

void ANaveTerrestre::Disparar()
{
	Estado->Disparar();
}

void ANaveTerrestre::EstablecerEstados(IEstado* _Estado)
{
	Estado = _Estado;
	//en aqui no se pudo cambiar de malla asi que para simular se cambio de tamaño
	if (Estado == EstadoTerrestre)
	{

	NaveTrestreP->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	}
	else if (Estado == EstadoAereo)
	{
		NaveTrestreP->SetWorldScale3D(FVector(1.5f, 1.5f, 1.5f));
	}
	else if (Estado == EstadoEspacial)
	{
		NaveTrestreP->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
	}
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

FString ANaveTerrestre::ObtenerEstadoActual()
{
	return Estado ? Estado->Estado() : "Estado no inicializado";

}


//void ANaveTerrestre::DisminuirVida(float Cantidad)
//{
//	Vida -= Cantidad;
//
//	if (Vida <= 0.f)
//	{
//		Destroy();
//	}



FVector ANaveTerrestre::GetSafeActorLocation() const
{
	if (RootComponent)
	{
		return RootComponent->GetComponentLocation();
	}
	else
	{
		// Devuelve una ubicación predeterminada si RootComponent es nulo
		return FVector::ZeroVector;
	}
}