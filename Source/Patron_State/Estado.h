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
	
	virtual void EstadoTerrestre() = 0;
	virtual void EstadoAereo() = 0;
	virtual void EstadoEspacial() = 0;
	//pregunta por el estado actual

	virtual void EstadoActual() = 0;
	//metodo para acceder a la nave
	virtual void setNaveTerrestre(class ANaveTerrestre* nave) = 0;
};
