// Copyright Epic Games, Inc. All Rights Reserved.


#include "SpacePongGameModeBase.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerStart.h"
#include "Misc/CString.h"
#include "Ship.h"
#include "ShipPlayerController.h"

void ASpacePongGameModeBase::BeginPlay() {
	Super::BeginPlay();

	//SpawnPlayerControllers();
	SpawnActors();
}

void ASpacePongGameModeBase::SpawnPlayerControllers()
{
	APlayerController* baseController = UGameplayStatics::GetPlayerController(this, 0);
	for (int i = 0; i < PlayerCount; i++) {
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, i);
		if (!PlayerController) {
			APlayerController* newController = UGameplayStatics::CreatePlayer(this, i, true);
			newController->PushInputComponent(Cast<UInputComponent>(baseController->InputComponent));
		}
	}
}

void ASpacePongGameModeBase::SpawnActors() {
	AShipPlayerController* PlayerController = Cast<AShipPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	for (APlayerStart* playerStart : TActorRange<APlayerStart>(GetWorld())) {
		int32 i = FCString::Atoi(*(playerStart->PlayerStartTag.ToString()));
		AShip* Ship = GetWorld()->SpawnActor<AShip>(DefaultShipClass, playerStart->GetActorLocation(), playerStart->GetActorRotation());
		PlayerController->RegisterShip(Ship, i, true);
	}
}
