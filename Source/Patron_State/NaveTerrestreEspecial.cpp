// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveTerrestreEspecial.h"
#include "Patron_StateProjectile.h"
#include "Engine/World.h"
ANaveTerrestreEspecial::ANaveTerrestreEspecial()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	NaveTrestreP = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	NaveTrestreP->SetStaticMesh(ShipMesh.Object);
	//GetActorRelativeScale3D();
	//SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
}

void ANaveTerrestreEspecial::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
}

void ANaveTerrestreEspecial::Tick(float DeltaTime)
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

void ANaveTerrestreEspecial::Mover(float DeltaTime)
{
	float Amplitud = 2.0f;
	float Frecuencia = 1.0f;
	float Tiempo = GetWorld()->GetTimeSeconds();  // Obtener el tiempo actual del juego

	// Obtener la ubicación actual del actor
	FVector Coordenada = GetActorLocation();

	// Calcular el desplazamiento en zigzag en el eje Y
	float ZigZagY = FMath::Sin(Tiempo * Frecuencia) * Amplitud;

	// Calcular la nueva ubicación
	FVector NewLocation = FVector(Coordenada.X - velocidad + ZigZagY * DeltaTime, Coordenada.Y + ZigZagY, Coordenada.Z);

	// Establecer la nueva ubicación del actor
	SetActorLocation(NewLocation);
}

void ANaveTerrestreEspecial::Disparar(FVector FireDirection)
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
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveTerrestreEspecial::ShotTimerExpired, FireRate);

			bCanFire = false;

		}
	}
}

void ANaveTerrestreEspecial::ShotTimerExpired()
{
	bCanFire = true;
}

void ANaveTerrestreEspecial::RecibirDanio()
{
	Vida -= 5;
	if (Vida <= 0)
	{
		Destroy();
	}
}

void ANaveTerrestreEspecial::Curarse()
{
	Vida = 100;
}

