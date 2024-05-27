// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProyectilE.generated.h"

UCLASS()
class PATRON_STATE_API AProyectilE : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProyectilE();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	class USceneComponent* DefaulSceneRoot;

	//Componente de Malla para el proyectil
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Projectile")
	class UStaticMeshComponent* Projectil_Mesh;

	//Componente de Movimiento para el proyectil
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	class UProjectileMovementComponent* Projectil_Movement; // movimiento

	//Componente de colision para el proyectil
	UPROPERTY(EditAnywhere, Category = "Projectile")
	class UCapsuleComponent* Projectil_Collision; // para colisiones 

public:
	float Danio_D_B;
	//Danio del proyectil 
	float DanioProvocado;
	void FireInDiagonal();

};
