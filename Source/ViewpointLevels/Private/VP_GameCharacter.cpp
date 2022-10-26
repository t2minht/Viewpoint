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

}

