// Copyright Epic Games, Inc. All Rights Reserved.

#include "Patron_StatePawn.h"
#include "Patron_StateProjectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "IStrategy.h"
#include "Estrategia1.h"
#include "Estrategia2.h"
#include "Estrategia3.h"

const FName APatron_StatePawn::MoveForwardBinding("MoveForward");
const FName APatron_StatePawn::MoveRightBinding("MoveRight");
const FName APatron_StatePawn::FireForwardBinding("FireForward");
const FName APatron_StatePawn::FireRightBinding("FireRight");

APatron_StatePawn::APatron_StatePawn()
{	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;
	Jump = FInputActionKeyMapping("salta", EKeys::T, 0, 0, 0, 0);
	crecer = FInputActionKeyMapping("crece", EKeys::Y, 0, 0, 0, 0);
	Disparar = FInputActionKeyMapping("dispara", EKeys::U, 0, 0, 0, 0);
}

void APatron_StatePawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	UPlayerInput::AddEngineDefinedActionMapping(Jump);
	UPlayerInput::AddEngineDefinedActionMapping(crecer);
	UPlayerInput::AddEngineDefinedActionMapping(Disparar);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);


	PlayerInputComponent->BindAction("salta", IE_Pressed, this, &APatron_StatePawn::EstartegiaSaltar);
	PlayerInputComponent->BindAction("crece", IE_Pressed, this, &APatron_StatePawn::EstrategiaCrecer);
	PlayerInputComponent->BindAction("dispara", IE_Pressed, this, &APatron_StatePawn::EstrategiaDisparo);
}

void APatron_StatePawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
	
	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);
}

void APatron_StatePawn::FireShot(FVector FireDirection)
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
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &APatron_StatePawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void APatron_StatePawn::ShotTimerExpired()
{
	bCanFire = true;
}

void APatron_StatePawn::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void APatron_StatePawn::CambiarEstrategia(AActor* estrategias)
{
	estratega = Cast<IIStrategy>(estrategias);
}

void APatron_StatePawn::EjecutarEstrategia()
{
	//estratega->Ejecutar();
}

void APatron_StatePawn::EstrategiaDisparo()
{

	Estartega3 = GetWorld()->SpawnActor<AEstrategia3>(AEstrategia3::StaticClass());
	CambiarEstrategia(Estartega3);
	EjecutarEstrategia();
	
}

void APatron_StatePawn::EstrategiaCrecer()
{
	Estartega2 = GetWorld()->SpawnActor<AEstrategia2>(AEstrategia2::StaticClass());
	CambiarEstrategia(Estartega2);
	EjecutarEstrategia();
}

void APatron_StatePawn::EstartegiaSaltar()
{	
	startega1 = GetWorld()->SpawnActor<AEstrategia1>(AEstrategia1::StaticClass());
	CambiarEstrategia(startega1);
	EjecutarEstrategia();
	startega1->Destroy();

}

