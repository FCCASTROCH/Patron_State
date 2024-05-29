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
//#include  "APatron_State.h"

ANaveTerrestre::ANaveTerrestre()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//vida = 200;
	//time = 0.0f;
	//vida = 200;
	//time = 0.0f;
	StateChangeInterval = 10.0f;
	CurrentStateIndex = 0;
	Escape = false;
	retorno = false;

}

// Called when the game starts or when spawned
void ANaveTerrestre::BeginPlay()
{
	Super::BeginPlay();

	/*EstadoAereo = GetWorld()->SpawnActor<AEstadoAereo>(AEstadoAereo::StaticClass());
	EstadoTerrestre = GetWorld()->SpawnActor<AEstadoTerrestre>(	AEstadoTerrestre::StaticClass());
	EstadoEspacial = GetWorld()->SpawnActor<AEstadoEspacial>(AEstadoEspacial::StaticClass());
	Inicializar();
	*/}

// Called every frame
void ANaveTerrestre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Disparar();
	///MoverN(DeltaTime);
	Huir(DeltaTime);

	
}
//
//void ANaveTerrestre::RecibirDanioN()
//{
//	vida -= 25;
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Vida: " + FString::SanitizeFloat(vida)));
//	if (vida <= 0)
//	{
//		Destroy();
//	}
//
//}
//
//void ANaveTerrestre::Inicializar()
//{
//	switch (CurrentStateIndex)
//	{
//	case 0:
//		EstadoTerrestre->SetNaveTerrestre(this);
//		EstablecerEstados(EstadoTerrestre);
//		break;
//	case 1:
//		EstadoAereo->SetNaveTerrestre(this);
//		EstablecerEstados(EstadoAereo);
//		break;
//	case 2:
//		EstadoEspacial->SetNaveTerrestre(this);
//		EstablecerEstados(EstadoEspacial);
//		break;
//	}
//}
//
//
//void ANaveTerrestre::EstablecerEstados(IEstado* _Estado)
//{
//    Estado = _Estado;
//}
//
////void ANaveTerrestre::MoverN(float DeltaTime)
////{
////   // Estado->Mover(DeltaTime);
////}
//
//void ANaveTerrestre::Disparar()
//{
//    //Estado->Disparar();
//}
//IEstado* ANaveTerrestre::GetEstado()
//{
//    return Estado;
//}
//
//IEstado* ANaveTerrestre::GetEstadoEspacial()
//{
//    return EstadoEspacial;
//}
//
//IEstado* ANaveTerrestre::GetEstadoAereo()
//{
//    return EstadoAereo;
//}
//
//IEstado* ANaveTerrestre::GetEstadoTerrestre()
//{
//    return EstadoTerrestre;
//}
void ANaveTerrestre::EstablecerRadar(AEscaner* _Radar)
{
	if (!_Radar)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No se ha encontrado el radar"));
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("radar en naveenemigo"));
	Escaner = _Radar;
	Escaner->Suscribirse(this);
}

void ANaveTerrestre::Actualizar()
{
	Escapar();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Actualizar Escapar"));
}

void ANaveTerrestre::Escapar()
{
	float VidaRecivida = Escaner->GetVidaPromedio();
	if (VidaRecivida <= 10)
	{
		Escape = true;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Escape true"));
	}
}

void ANaveTerrestre::QuitarSuscripcion()
{
	if (Escaner)
	{
		Escaner->Desuscribirse(this);
	}

}

void ANaveTerrestre::Huir(float DeltaTime)
{
	if (Escape == true)
	{
		SetActorLocation(FMath::VInterpTo(GetActorLocation(), FVector(1700.0f, -147.0f, 215.0f), DeltaTime, 0.5));
		Curarse();
	}
	if (GetActorLocation().Equals(FVector(1700.0f, -147.0f, 215.0f), 200))
	{
		Escape = false;
		retorno = true;
	}

}