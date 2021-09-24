// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());

	if (PlayerController != nullptr)
	{
		EndGame(false);
	}

	// For looper over the ShooterAI in World
		
	for (AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
	{
		if (!Controller->IsDead())										// is dead
		{
			return;
		}
	}
	EndGame(true);														// end game with WIN condition
		
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
		
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}
