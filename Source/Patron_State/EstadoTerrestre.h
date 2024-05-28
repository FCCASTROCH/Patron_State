// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
    public:
	/** Offset from the ships location to spawn projectiles */


	float TiempoDisparo;

protected:
	class ANaveTerrestre* NaveT;


public:
	void SetNaveTerrestre(class ANaveTerrestre* _Nave) override;
	void Mover(float DeltaTime) override;
	void Disparar() override;

private:
	float MoveSpeed;
	FVector TargetLocation;
	bool bIsMoving;
};
