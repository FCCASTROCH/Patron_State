// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Publicador.h"
#include "Escaner.generated.h"

/**
 * 
 */
UCLASS()
class PATRON_STATE_API AEscaner : public APublicador
{
	GENERATED_BODY()
public:
	AEscaner();
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	float VidaPromedio;
	void VidaNave();
	void SetVidaPromedio(float _VidaPromedio);

	FORCEINLINE float GetVidaPromedio();


};
