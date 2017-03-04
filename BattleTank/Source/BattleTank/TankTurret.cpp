// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto CalculatedRotation = RelativeSpeed * RotationSpeed * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = FMath::Clamp<float>(RelativeRotation.Yaw + CalculatedRotation, -180, 180);
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}