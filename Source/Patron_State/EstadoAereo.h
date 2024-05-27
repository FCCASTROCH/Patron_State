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

    virtual void EstadoActual() override;
    virtual void EstadoTerrestre() override;
    virtual void EstadoEspacial() override;
    virtual void setNaveTerrestre(ANaveTerrestre* nave) override;
    virtual void EstadoAereo() override;

private:
    ANaveTerrestre* NaveA;
    bool bIsMoving;
    FVector TargetLocation;
    float MoveSpeed;
};
