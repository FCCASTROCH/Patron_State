// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.h"
#include "NaveTerrestre.h"
#include "EstadoAereo.generated.h"

UCLASS()
class PATRON_STATE_API AEstadoAereo : public AActor, public IEstado
{
    GENERATED_BODY()

public:
    AEstadoAereo();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
protected:
	class ANaveTerrestre* NaveAe;
private:
	TArray<FVector> VerticesTriangulo;
	//IInventarioAFactory* inventarioFactory;
	int VerticeActual;
	FVector DireccionMovimiento;
	float DistanciaRecorrida;
	float VelocidadMovimiento;

public:
	

	virtual void SetNaveTerrestre(class ANaveTerrestre* Terrestre) override;

	virtual void Conducir() override {};

	virtual void Volar() override;

	virtual void Navegar() override {};
	//Disparar acorde a disparar de formas diferentes
	virtual void Disparar()override;
	//para establecer estados
	virtual FString Estado()override;
	void ShotTimerExpired();
	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FVector GunOffset;

	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	float TiempoDisparo;
};
