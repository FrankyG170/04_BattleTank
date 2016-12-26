// Fill out your copyright notice in the Description page of Project Settings.

#include "BTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// Move Barrel in X/Y/Z to properly aim at, and hit, the HitLocation
	// Given max elevation speed & frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel->Elevate() called at speed %f"), DegreesPerSecond);
}


