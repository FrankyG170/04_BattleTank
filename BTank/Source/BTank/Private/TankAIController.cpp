// Fill out your copyright notice in the Description page of Project Settings.

#include "BTank.h"
#include "Tank.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) 
{
	Super::Tick( DeltaTime );

	// Get Player Tank
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	// Get AI Tank
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank) 
	{
		//TODO Move towards player

		// Aim Torwards player & fire
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire(); // TODO Don't fire every frame
	}
	
}