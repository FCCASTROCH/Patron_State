// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Estado.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEstado : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PATRON_STATE_API IEstado
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:




	//Establecer Nave
	virtual void SetNaveTerrestre(class ANaveTerrestre* Terrestre) = 0;

	virtual void Conducir() = 0;

	virtual void Volar() = 0;

	virtual void Navegar() = 0;
	//Disparar acorde a disparar de formas diferentes
	virtual void Disparar() = 0;
	//para establecer estados
	virtual FString Estado() = 0;
	
};
