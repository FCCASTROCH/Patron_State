// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.h"
#include "NaveTerrestre.generated.h"

UCLASS()
class PATRON_STATE_API ANaveTerrestre : public AActor
{
    GENERATED_BODY()

public:
    ANaveTerrestre();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    void Mover(float DeltaTime);
    void Disparo_Nave(float DeltaTime);

    void SetEstadoTerrestre();
    void SetEstadoAereo();
    void SetEstadoEspacial();

    FString GetCurrentState() const;

private:
    IEstado* EstadoActual;
    IEstado* EstadoTerrestre;
    IEstado* EstadoAereo;

    class AEstadoTerrestre* EstadoTerrestre;
    class AEstadoAereo* EstadoAereo;
    class AEstadoEspacial* EstadoEspacial;

    FString CurrentState;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* NaveEnemigoMesh;

    float Velocidad;
    float Tiempo_Disparo;
    float Tiempo_M;
    float Distancia_D_CB;
    float Tiempo_Disparo_Generar;
    float Timer;
    float TiempoTranscurrido;
};

