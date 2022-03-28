// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipPlayerController.h"
#include "Ship.h"


void AShipPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AShipPlayerController::SetupInputComponent() 
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(TEXT("Player 1 - Move Vertical"), this, &AShipPlayerController::MoveVertical_P1);
	InputComponent->BindAxis(TEXT("Player 1 - Move Horizontal"), this, &AShipPlayerController::MoveHorizontal_P1);
	InputComponent->BindAction(TEXT("Player 1 - Ability 1"), EInputEvent::IE_Pressed, this, &AShipPlayerController::UseSkill1_P1);
	InputComponent->BindAction(TEXT("Player 1 - Ability 2"), EInputEvent::IE_Pressed, this, &AShipPlayerController::UseSkill2_P1);
	InputComponent->BindAction(TEXT("Player 1 - Ability 3"), EInputEvent::IE_Pressed, this, &AShipPlayerController::UseSkill3_P1);
	
	InputComponent->BindAxis(TEXT("Player 2 - Move Vertical"), this, &AShipPlayerController::MoveVertical_P2);
	InputComponent->BindAxis(TEXT("Player 2 - Move Horizontal"), this, &AShipPlayerController::MoveHorizontal_P2);
	InputComponent->BindAction(TEXT("Player 2 - Ability 1"), EInputEvent::IE_Pressed, this, &AShipPlayerController::UseSkill1_P2);
	InputComponent->BindAction(TEXT("Player 2 - Ability 2"), EInputEvent::IE_Pressed, this, &AShipPlayerController::UseSkill2_P2);
	InputComponent->BindAction(TEXT("Player 2 - Ability 3"), EInputEvent::IE_Pressed, this, &AShipPlayerController::UseSkill3_P2);
	

}

void AShipPlayerController::RegisterShip(AShip* Ship, int32 index, bool bIsPlayerControlled)
{
	if (index > 2 || index < 0) return;
	Ships[index] = Ship;
	IsPlayerControlled[index] = bIsPlayerControlled;
}

void AShipPlayerController::MoveVertical_P1(float Scale)
{
	if (IsPlayerControlled[0]) Ships[0]->Move(Scale);
}

void AShipPlayerController::MoveHorizontal_P1(float Scale)
{

}


void AShipPlayerController::UseSkill1_P1()
{
	UE_LOG(LogTemp, Warning, TEXT("Controller #%i using skill 1 (possessing %s)"), GetInputIndex(), *GetPawn()->GetName());
}

void AShipPlayerController::UseSkill2_P1()
{
}

void AShipPlayerController::UseSkill3_P1()
{
}

void AShipPlayerController::MoveVertical_P2(float Scale)
{
	if (IsPlayerControlled[1]) Ships[1]->Move(Scale);
}

void AShipPlayerController::MoveHorizontal_P2(float Scale)
{

}


void AShipPlayerController::UseSkill1_P2()
{
}

void AShipPlayerController::UseSkill2_P2()
{
}

void AShipPlayerController::UseSkill3_P2()
{
}