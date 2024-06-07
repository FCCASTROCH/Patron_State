// Fill out your copyright notice in the Description page of Project Settings.


#include "Estrategia3.h"
#include "IStrategy.h"
#include "Patron_StatePawn.h"
#include "Patron_StateProjectile.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "ProyectilE.h"
#include "NaveEspecial.h"
// Sets default values
AEstrategia3::AEstrategia3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategia3::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategia3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Ejecutar();
}

void AEstrategia3::Disparar(ANaveEspecial* especial)
{
	FVector FireDirection = especial->GetActorForwardVector();
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = especial->GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<APatron_StateProjectile>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEstrategia3::ShotTimerExpired, FireRate);
}
	}
}

void AEstrategia3::ShotTimerExpired()
{
	bCanFire = true;
}