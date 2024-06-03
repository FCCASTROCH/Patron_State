// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.h"
#include "NaveTerrestre.h"
#include "EstadoTerrestre.generated.h"

UCLASS()
class PATRON_STATE_API AEstadoTerrestre : public AActor, public IEstado
{
    GENERATED_BODY()

public:
    AEstadoTerrestre();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
private:
	FVector DireccionMovimiento;
	float DistanciaRecorrida;
	float LongitudLadoCuadrado;
	float VelocidadMovimiento;

protected:
	class ANaveTerrestre* NaveT;

public:

	virtual void SetNaveTerrestre(class ANaveTerrestre* Terrestre) override;

	virtual void Conducir() override;

	virtual void Volar() override {};
	
	virtual void Navegar() override {};
	//Disparar acorde a disparar de formas diferentes
	virtual void Disparar()override;
	//para establecer estados
	virtual FString Estado()override;
};
