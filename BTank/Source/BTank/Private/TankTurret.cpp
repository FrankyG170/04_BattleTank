// Fill out your copyright notice in the Description page of Project Settings.

#include "BTank.h"
#include "TankAimingComponent.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move Turret in X axis to turn towards hit location
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	

	SetRelativeRotation(FRotator(0, NewRotation, 0));
}

