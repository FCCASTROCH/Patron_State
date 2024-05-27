// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
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
	class ANaveTerrestre* NaveTerrestre;

	void AlternarEstados();
	FTimerHandle EstadoTimerHandle;
	bool bEstadoInicial;
	FTimerHandle EstadoATimerHandle;
	FTimerHandle EstadoTTimerHandle;
	float TiempoTranscurrido;
};



