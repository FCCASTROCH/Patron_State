// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.h"
#include "Subscriptor.h"
//#include "Escaner.h"
#include "NaveTerrestre.generated.h"
class AEscaner;

UCLASS()
class PATRON_STATE_API ANaveTerrestre : public AActor,public ISubscriptor
{
    GENERATED_BODY()

public:
    ANaveTerrestre();

    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;
	//Declaramos las caracteristicas de la nave nodriza
public:
	UStaticMeshComponent* NaveTrestreP;

	/*float vida;

	void RecibirDanioN();*/

	//Declaramos todo lo necesario para hacer trabajar los estados de la nave nodriza
public:
	//Inicializar los estados de la nave nodriza
	/*void Inicializar();*/

	//Declaramos los estados de la nave nodriza
	//IEstado* EstadoAereo;
	//IEstado* EstadoTerrestre;
	//IEstado* EstadoEspacial;
	//IEstado* Estado;

	//Funciones para cambiar de estado
	//FORCEINLINE void EstablecerEstados(IEstado* _Estado);

	////void MoverN(float DeltaTime);
	//void Disparar();
	//float time;

	////Funciones para obtener los estados
	//FORCEINLINE IEstado* GetEstado();
	//FORCEINLINE IEstado* GetEstadoAereo();
	//FORCEINLINE IEstado* GetEstadoEspacial();
	//FORCEINLINE IEstado* GetEstadoTerrestre();
 //   UPROPERTY(VisibleAnywhere)
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


	int velocidad;
	float Vida;
	bool Escape;
	FVector PosicionInicial;
	bool retorno;
	//float TiempoTranscurrido;

	class APatron_StateGameMode* GameMode;

	UPROPERTY(VisibleAnywhere, Category = "Subscriptor")
	class AEscaner* Escaner;

public:
	void EstablecerRadar(class AEscaner* _Radar);
	void Actualizar() override;//
	void Escapar();
	void QuitarSuscripcion();
	void Huir(float DeltaTime);

	virtual void Mover(float DeltaTime) PURE_VIRTUAL(ANaveTerrestre::Mover, );
	virtual void Disparar(FVector FireDiretion) PURE_VIRTUAL(ANaveTerrestre::Disparar, );
	virtual void RecibirDanio() PURE_VIRTUAL(ANaveTerrestre::RecibirDanio, );
	virtual void Curarse() PURE_VIRTUAL(ANaveTerrestre::Curarse, );

};

