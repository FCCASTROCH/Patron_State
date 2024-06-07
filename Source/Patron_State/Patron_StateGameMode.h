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
	class ANaveEspecial* naveEspecial;
	class AEstrategia1* startega1;
	class AEstrategia2* Estartega2;
	class AEstrategia3* Estartega3;
	class ANaveTerrestre* Nave;
	class ANaveTerrestreModificado* naveM;
	void cambiarEstrategia1();
	void cambiarEstrategia2();
	void cambiarEstrategia3();

	FTimerHandle estrategia1;
	FTimerHandle estrategia2;
	FTimerHandle estrategia3;
	float tiempo;
	int32 CurrentStrategyIndex;
	void CambiarYEjecutarEstrategia();
	float ElapsedTime;
};