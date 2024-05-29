// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveTerrestreModificado.h"
#include "Patron_StateGameMode.h"
#include "Patron_StateProjectile.h"
ANaveTerrestreModificado::ANaveTerrestreModificado()
{
	
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	NaveTrestreP = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	NaveTrestreP->SetStaticMesh(ShipMesh.Object);
	//GetActorRelativeScale3D();
	//SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
}

void ANaveTerrestreModificado::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
}

void ANaveTerrestreModificado::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Mover(DeltaTime);
	Disparar(FVector(-1.0f, 0.0f, 0.0f));
	if (retorno == true)
	{
		SetActorLocation(FMath::VInterpTo(GetActorLocation(), PosicionInicial, DeltaTime, 0.5));
		TiempoTranscurrido += DeltaTime;
		if (TiempoTranscurrido >= 5)
		{
			retorno = false;
			TiempoTranscurrido = 0;
		}
	}

}

void ANaveTerrestreModificado::Mover(float DeltaTime)
{
	FVector Coordenada = GetActorLocation();
	float posicion = velocidad * DeltaTime;
	FVector NewLocation = FVector(Coordenada.X - velocidad, Coordenada.Y, Coordenada.Z);
	SetActorLocation(NewLocation);
}

void ANaveTerrestreModificado::Disparar(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<APatron_StateProjectile>(SpawnLocation, FireRotation);
			}
			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveTerrestreModificado::ShotTimerExpired, FireRate);

			bCanFire = false;

		}
	}
}

void ANaveTerrestreModificado::ShotTimerExpired()
{
	bCanFire = true;
}

void ANaveTerrestreModificado::RecibirDanio()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("NaveCaza::RecibirDanio"));
	Vida -= 5;
	if (Vida <= 0)
	{
		Destroy();
	}
}

void ANaveTerrestreModificado::Curarse()
{
	Vida = 100;
}
