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
    virtual void EstadoActual() override;
    virtual void EstadoTerrestre() override;
    virtual void EstadoEspacial() override;
    virtual void setNaveTerrestre(ANaveTerrestre* nave) override;
    virtual void EstadoAereo() override;

private:
    ANaveTerrestre* NaveT;
    bool bIsMoving;
    FVector TargetLocation;
    float MoveSpeed;
};

