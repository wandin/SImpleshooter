// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

protected:

	virtual void BeginPlay() override;

private:
		//HUD HEALTH AND CROSSHAIR			
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> HUDClass;
				// Lose screen
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> LoseScreenClass;
				// Win Screen
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> WinScreenClass;

				// restart game function
	UPROPERTY(EditAnywhere)
		float RestartDelay = 5;

	FTimerHandle RestartTimer;

	UPROPERTY()
	UUserWidget* HUD;

};
