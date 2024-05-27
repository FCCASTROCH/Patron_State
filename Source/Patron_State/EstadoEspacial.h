// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estado.h"
#include "NaveTerrestre.h"
#include "EstadoEspacial.generated.h"

UCLASS()
class PATRON_STATE_API AEstadoEspacial : public AActor ,public IEstado
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstadoEspacial();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Metodos de la interfaz IEstado
	virtual void EstadoActual() override;
	virtual void EstadoTerrestre() override;
	virtual void EstadoEspacial() override;
	virtual void setNaveTerrestre(ANaveTerrestre* nave) override;
	virtual void EstadoAereo() override;

private:
	ANaveTerrestre* NaveE;
	bool bIsMoving;
	FVector TargetLocation;
	float MoveSpeed;

};
