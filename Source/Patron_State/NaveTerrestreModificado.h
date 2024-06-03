// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveTerrestre.h"
#include "NaveTerrestreModificado.generated.h"

/**
 * 
 */
UCLASS()
class PATRON_STATE_API ANaveTerrestreModificado : public ANaveTerrestre
{
	GENERATED_BODY()
public:
		ANaveTerrestreModificado();
		virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;


public:
	
};
