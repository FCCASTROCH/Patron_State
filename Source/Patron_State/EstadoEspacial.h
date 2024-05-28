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
protected:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	class ANaveTerrestre* NaveE;



public:
	void SetNaveTerrestre(class ANaveTerrestre* _Nave) override;
	void Disparar() override;
	
private:
	void Mover(float DeltaTime) override {};
	FVector TargetLocation;
	bool bIsMoving ;
	float MoveSpeed;
};
