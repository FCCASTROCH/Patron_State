// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEspecial.h"
#include "IStrategy.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

// Sets default values
ANaveEspecial::ANaveEspecial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Nave"));
	MeshComp->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f)); // Aquí se ajusta la escala
	//MeshComp->SetStaticMesh(ShipMesh.Object);
	  if (ShipMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(ShipMesh.Object);
	}
	 // Set the StaticMeshComponent as the RootComponent
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void ANaveEspecial::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveEspecial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANaveEspecial::CambiarEstrategia(AActor* estrategias)
{
	estratega = Cast<IIStrategy>(estrategias);
}

void ANaveEspecial::EjecutarEstrategia()
{
	estratega->Disparar(this);
}

