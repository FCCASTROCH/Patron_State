// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.h"
#include "NaveTerrestre.h"
#include "EstadoEspacial.generated.h"

UCLASS()
class PATRON_STATE_API AEstadoEspacial : public AActor ,public IEstado
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstadoEspacial();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
protected:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	class ANaveTerrestre* NaveEs;
private:
	float Radio;
	float Angulo;
	float VelocidadAngular; // En radianes por segundo
	FVector Centro;
	int MaxProjectile;

	int NumberFired;
	bool bCanFire;

	FVector UPJugador;
	float TiempoDisparo;
public:

	virtual void SetNaveTerrestre(class ANaveTerrestre* Terrestre) override;

	virtual void Conducir() override {};

	virtual void Volar() override {};

	virtual void Navegar() override ;
	//Disparar acorde a disparar de formas diferentes
	virtual void Disparar()override;
	//para establecer estados
	virtual FString Estado()override;
	void ResetCanFire();
};
