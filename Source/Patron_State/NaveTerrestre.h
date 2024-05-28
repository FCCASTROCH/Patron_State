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
	//Declaramos las caracteristicas de la nave nodriza
public:
	UStaticMeshComponent* NaveNodrizaMesh;

	float vida;

	void RecibirDanio();

	//Declaramos todo lo necesario para hacer trabajar los estados de la nave nodriza
public:
	//Inicializar los estados de la nave nodriza
	void Inicializar(float DeltaTime);

	//Declaramos los estados de la nave nodriza
	IEstado* EstadoAereo;
	IEstado* EstadoTerrestre;
	IEstado* EstadoEspacial;
	IEstado* Estado;

	//Funciones para cambiar de estado
	FORCEINLINE void EstablecerEstados(IEstado* _Estado);

	void Mover(float DeltaTime);
	void Disparar();
	float time;

	//Funciones para obtener los estados
	FORCEINLINE IEstado* GetEstado();
	FORCEINLINE IEstado* GetEstadoAereo();
	FORCEINLINE IEstado* GetEstadoEspacial();
	FORCEINLINE IEstado* GetEstadoTerrestre();
    UPROPERTY(VisibleAnywhere)
    //UStaticMeshComponent* NaveEnemigoMesh;

    float Velocidad;
    float Tiempo_Disparo;
    float Tiempo_M;
    float Distancia_D_CB;
    float Tiempo_Disparo_Generar;
    float Timer;
    float TiempoTranscurrido;
	float StateChangeInterval;
	int32 CurrentStateIndex;
};

