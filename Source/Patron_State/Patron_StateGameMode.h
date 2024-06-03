// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NaveTerrestre.h"
#include "NaveTerrestreEspecial.h"
#include "NaveTerrestreModificado.h"
#include "Patron_StateGameMode.generated.h"

UCLASS(MinimalAPI)
class APatron_StateGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APatron_StateGameMode();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
public:
	float VidaPromedio;
public:
	class ANaveTerrestre* Nave;
	void crearNave();
	float tiempo;
};