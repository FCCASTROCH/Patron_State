// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveTerrestre.h"
#include "NaveTerrestreEspecial.generated.h"

/**
 * 
 */
UCLASS()
class PATRON_STATE_API ANaveTerrestreEspecial : public ANaveTerrestre
{
	GENERATED_BODY()
	
public:
	ANaveTerrestreEspecial();
	protected:

	virtual void BeginPlay() override;
		
public:
	virtual void Tick(float DeltaTime) override;
	
public:
	
	//void RepararNave() override;
	

public:
	//void Mover(float DeltaTime) override;
	//void Disparar(FVector FireDirection) override;
	//void RecibirDanio() override;
	
};
