// Fill out your copyright notice in the Description page of Project Settings.


#include "VP_GameCharacter.h"

// Sets default values
AVP_GameCharacter::AVP_GameCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVP_GameCharacter::BeginPlay()
{
	Super::BeginPlay();
	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using C++ GameCharacter."));
	
}

// Called every frame
void AVP_GameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVP_GameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// PlayerInputComponent->BindAxis("MoveForward", this, &AVP_GameCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AVP_GameCharacter::MoveRight);
}

// void AVP_GameCharacter::MoveForward(float Value)
// {
//     // Find out which way is "forward" and record that the player wants to move that way.
// 	FVector Direction = FRotationMatrix(UGameplayStatics::GetPlayerController(GetWorld(),0)->GetViewTarget()->GetActorRotation()).GetScaledAxis(EAxis::X);
//     // FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
//     AddMovementInput(Direction, Value);
// }

void AVP_GameCharacter::MoveRight(float Value)
{
    // Find out which way is "right" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(UGameplayStatics::GetPlayerController(GetWorld(),0)->GetViewTarget()->GetActorRotation()).GetScaledAxis(EAxis::Y);
    // FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
    AddMovementInput(Direction, Value);
}



