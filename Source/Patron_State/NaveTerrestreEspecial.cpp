// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveTerrestreEspecial.h"
#include "Patron_StateProjectile.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
ANaveTerrestreEspecial::ANaveTerrestreEspecial()
{
   PrimaryActorTick.bCanEverTick = true;
 //   static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
 //   NaveTrestreP = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NaveTrestreP"));
 //   NaveTrestreP->SetStaticMesh(ShipMesh.Object);
 //    Set the StaticMeshComponent as the RootComponent
 //   RootComponent = NaveTrestreP;*/
	//// Verifica si se encontr� el StaticMesh
	//if (ShipMesh.Succeeded())
	//{
	//	// Asigna el StaticMesh al componente de malla est�tica
	//	NaveTrestreP->SetStaticMesh(ShipMesh.Object);

	//	// Modifica la escala del componente de malla est�tica
	//	NaveTrestreP->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f)); // Aqu� se ajusta la escala
	//}
    
}

void ANaveTerrestreEspecial::BeginPlay()
{
	Super::BeginPlay();
}

void ANaveTerrestreEspecial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
