// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpacePongGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SPACEPONG_API ASpacePongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void SpawnPlayerControllers();
	void SpawnActors();

	UPROPERTY(EditDefaultsOnly, Category = "Game Settings")
	int PlayerCount;

	UPROPERTY(EditDefaultsOnly, Category = "Game Settings")
	TSubclassOf<class AShip> DefaultShipClass;
};
