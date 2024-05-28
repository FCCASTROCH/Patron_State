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
	class ANaveTerrestre* NaveA;

	float velocidad;
public:
	void SetNaveTerrestre(class ANaveTerrestre* _NaveTerrestre) override;
	void Mover(float DeltaTime) override;

private:
	void Disparar() override {};
	FVector TargetLocation;
	bool bIsMoving ;
	float MoveSpeed;
};
