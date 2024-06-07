// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IStrategy.h"
#include "Estrategia1.generated.h"

UCLASS()
class PATRON_STATE_API AEstrategia1 : public AActor,public IIStrategy
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategia1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Disparar(class ANaveEspecial*especial) override;
	
};
