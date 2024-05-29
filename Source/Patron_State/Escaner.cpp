// Fill out your copyright notice in the Description page of Project Settings.


#include "Escaner.h"


AEscaner::AEscaner()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEscaner::BeginPlay()
{
	Super::BeginPlay();
}

void AEscaner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEscaner::VidaNave()
{
	Notificar();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Notificando"));
}

void AEscaner::SetVidaPromedio(float _VidaPromedio)
{
	VidaPromedio = _VidaPromedio;
	VidaNave();
}

float AEscaner::GetVidaPromedio()
{
	return VidaPromedio;
}
