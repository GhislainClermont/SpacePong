// Fill out your copyright notice in the Description page of Project Settings.


#include "Ship.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AShip::AShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	SetRootComponent(Root);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement Component"));
	MovementComponent->SetUpdatedComponent(Root);
	MovementComponent->MaxSpeed = MoveSpeed;	
	MovementComponent->InitialSpeed = 0.f;
	MovementComponent->ProjectileGravityScale = 0.f;

	//SpawnDefaultController();

}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShip::Move(float Direction)
{
	FVector DeltaLocation(0.f);
	DeltaLocation.Y = Direction * MoveSpeed * GetWorld()->GetDeltaSeconds();
	UE_LOG(LogTemp, Warning, TEXT("Direction: %f, VelocitySize: %f"), Direction, MovementComponent->Velocity.Size());
	//AddActorWorldOffset(DeltaLocation, true);
	//MovementComponent->AddInputVector(DeltaLocation * 100.f, true);
	//AddMovementInput(DeltaLocation.GetSafeNormal(), MoveSpeed);
	if (MovementComponent) {
		if (FMath::Abs(Direction * MoveSpeed) >= MovementComponent->Velocity.Size()) {
			MovementComponent->AddForce(DeltaLocation * MoveSpeed);
			UE_LOG(LogTemp, Warning, TEXT("Increasing speed."));
		}
		else {
			float NewVelocity = FMath::Max(FMath::Abs(Direction * MoveSpeed), MovementComponent->Velocity.Size() - DeltaLocation.Size() * MoveSpeed);
			UE_LOG(LogTemp, Warning, TEXT("Decreasing speed. New Velocity = %f"), NewVelocity);
			MovementComponent->SetVelocityInLocalSpace(MovementComponent->Velocity.GetSafeNormal() * NewVelocity);
			//MovementComponent->LimitVelocity(FMath::Max(Direction * MoveSpeed, MovementComponent->Velocity.Size() - DeltaLocation.Size()));
		}
		
	}
	else UE_LOG(LogTemp, Error, TEXT("ERROR! MovementComponent not found???????"));
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

