// Fill out your copyright notice in the Description page of Project Settings.


#include "ProyectilE.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
// Sets default values
AProyectilE::AProyectilE()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    // Creando la malla del proyectil
    Projectil_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectil_Mesh"));
    RootComponent = Projectil_Mesh;

    static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
    if (MeshAsset.Succeeded())
    {
        Projectil_Mesh->SetStaticMesh(MeshAsset.Object);

        //// Modificar la escala del componente de malla
        FVector NewScale(0.5f, 0.5f, 0.5f); // Escala modificada
        Projectil_Mesh->SetWorldScale3D(NewScale);
    }
    // Controlando el movimiento del proyectil
    Projectil_Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectil_Movement"));
    Projectil_Movement->InitialSpeed = 750.0f;
    Projectil_Movement->MaxSpeed = 850.0f;
    Projectil_Movement->bRotationFollowsVelocity = true;
    Projectil_Movement->bShouldBounce = false;
    Projectil_Movement->ProjectileGravityScale = 0.0f;

    // Creando el componente de colisión del proyectil
    Projectil_Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Projectil_Collision"));
    Projectil_Collision->SetupAttachment(RootComponent);

    // Estableciendo el tiempo de vida inicial del proyectil
    InitialLifeSpan = 5.f;

    // Daño predeterminado del proyectil
    DanioProvocado = 0.f;
    //Configurando el proyectil para que genere eventos de colision
    Projectil_Collision->SetCapsuleHalfHeight(160.0f);
    Projectil_Collision->SetCapsuleRadius(160.0f);

}

// Called when the game starts or when spawned
void AProyectilE::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProyectilE::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AProyectilE::FireInDiagonal()
{
    if (Projectil_Movement)
    {
        // Establecer la velocidad inicial para moverse diagonalmente hacia arriba
        FVector DiagonalVelocity = FVector(1.0f, 0.0f, 0.5f).GetSafeNormal() * Projectil_Movement->InitialSpeed;
        Projectil_Movement->Velocity = DiagonalVelocity;
    }
}

