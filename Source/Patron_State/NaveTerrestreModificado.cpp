// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveTerrestreModificado.h"
#include "Patron_StateGameMode.h"
#include "Patron_StateProjectile.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

ANaveTerrestreModificado::ANaveTerrestreModificado()
{
	PrimaryActorTick.bCanEverTick = true;
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	//NaveTrestreP = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NaveTrestreP"));
	//// NaveTrestreP->SetStaticMesh(ShipMesh.Object);
	// // Set the StaticMeshComponent as the RootComponent
	//RootComponent = NaveTrestreP;
	//// Verifica si se encontró el StaticMesh
	//if (ShipMesh.Succeeded())
	//{
	//	// Asigna el StaticMesh al componente de malla estática
	//	NaveTrestreP->SetStaticMesh(ShipMesh.Object);

	//	// Modifica la escala del componente de malla estática
	//	NaveTrestreP->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f)); // Aquí se ajusta la escala
	//}


}

void ANaveTerrestreModificado::BeginPlay()
{
	Super::BeginPlay();
	//InicializarEstados();
	//PosicionInicial = GetActorLocation();
}

void ANaveTerrestreModificado::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
