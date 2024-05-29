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
	uint32 bCanFire : 1;

	FVector GunOffset;

	float FireRate;

	FTimerHandle TimerHandle_ShotTimerExpired;

	void ShotTimerExpired();

public:
	void Mover(float DeltaTime) ;
	void Disparar(FVector FireDirection) ;
	void RecibirDanio() ;
	void Curarse() ;




};
