// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Publicador.generated.h"

UCLASS()
class PATRON_STATE_API APublicador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APublicador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere, Category = "Publicador")
	TArray<AActor*> Subscriptores;

	class ISubscriptor* Subscriptor;

public:
	void Suscribirse(AActor* _Suscriptor);
	void Desuscribirse(AActor* _Suscriptor);
	void Notificar();
};
