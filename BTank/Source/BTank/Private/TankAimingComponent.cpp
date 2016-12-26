// Fill out your copyright notice in the Description page of Project Settings.

#include "BTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) 
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; } // If no barrel is found then return void
	
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile")); // Using Barrel socket for fire start location
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
							(
								this,
								OutLaunchVelocity,
								StartLocation,
								HitLocation,
								LaunchSpeed,
								false,
								0,
								0,
								ESuggestProjVelocityTraceOption::DoNotTrace
							);
	
	// If a projectile velocity can be suggested
	if (bHaveAimSolution)
	{	// Calculate the OutLaunchVelocity
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
	// If no solution then do nothing
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDireciton)
{
	// Find difference between current direction and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDireciton.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	Barrel->Elevate(5); // TODO remove magic number
}