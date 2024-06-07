// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.h"
//#include "Subscriptor.h"
//#include "Escaner.h"
#include "NaveTerrestre.generated.h"


UCLASS()
class PATRON_STATE_API ANaveTerrestre : public AActor
{
    GENERATED_BODY()

public:
    ANaveTerrestre();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	IEstado* EstadoEspacial;
	IEstado* EstadoAereo;
	IEstado* EstadoTerrestre;
	IEstado* Estado;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float TiempoTranscurrido;

	UPROPERTY(VisibleAnywhere, Category = "true")
	UStaticMeshComponent* NaveTrestreP;
	void inicializar();
	void Manejar();
	void Volar();
	void Navegar();
	void Disparar();

	FORCEINLINE void EstablecerEstados(IEstado* _Estado);
	//Funciones para obtener los estados
	FORCEINLINE IEstado* GetEstado();
	FORCEINLINE IEstado* GetEstadoEspacial();
	FORCEINLINE IEstado* GetEstadoAereo();
	FORCEINLINE IEstado* GetEstadoTerrestre();
	FORCEINLINE FString ObtenerEstadoActual();

	//esto funcion inservible para esta clase
	FORCEINLINE FVector GetSafeActorLocation() const;
};

