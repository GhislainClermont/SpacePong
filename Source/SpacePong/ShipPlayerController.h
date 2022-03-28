// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShipPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SPACEPONG_API AShipPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	virtual void SetupInputComponent() override;

	void RegisterShip(class AShip* Ship, int32 index, bool bIsPlayerControlled);

protected:
	virtual void BeginPlay() override;

private:
	void MoveVertical_P1(float Scale);
	void MoveHorizontal_P1(float Scale);
	void UseSkill1_P1();
	void UseSkill2_P1();
	void UseSkill3_P1();
	void MoveVertical_P2(float Scale);
	void MoveHorizontal_P2(float Scale);
	void UseSkill1_P2();
	void UseSkill2_P2();
	void UseSkill3_P2();

	class AShip* Ships[2];
	bool IsPlayerControlled[2] = { true, true };

};
