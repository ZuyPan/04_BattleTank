// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAiController.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AiController not possesing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AiController possesing: %s"), *ControlledTank->GetName());
	}

	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AiController can't find player tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AiController found player: %s"), *PlayerTank->GetName());
	}
}

ATank* ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank() const
{
	APawn* PlayerTankPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTankPawn) { return nullptr; }
	return Cast<ATank>(PlayerTankPawn);
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}