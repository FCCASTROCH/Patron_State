// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IStrategy.h"
#include "Estrategia2.generated.h"

UCLASS()
class PATRON_STATE_API AEstrategia2 : public AActor,public IIStrategy
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategia2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//class ANaveTerrestreModificado* pawn;
	virtual void Disparar(class ANaveEspecial*especial) override;
};
