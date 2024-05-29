// Fill out your copyright notice in the Description page of Project Settings.


#include "Publicador.h"
#include "Subscriptor.h"
// Sets default values
APublicador::APublicador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Subscriptores = TArray<AActor*>();
}

// Called when the game starts or when spawned
void APublicador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APublicador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APublicador::Suscribirse(AActor* _Suscriptor)
{
	Subscriptores.Add(_Suscriptor);
}

void APublicador::Desuscribirse(AActor* _Suscriptor)
{
	Subscriptores.Remove(_Suscriptor);
}

void APublicador::Notificar()
{
	for (AActor* Sub : Subscriptores)
	{
		ISubscriptor* Suscriptor = Cast<ISubscriptor>(Sub);
		if (Suscriptor)
		{
			Suscriptor->Actualizar();
		}
	}
}

