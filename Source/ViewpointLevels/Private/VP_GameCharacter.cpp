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
	// FVector Direction = FRotationMatrix(UGameplayStatics::GetPlayerController(GetWorld(),0)->GetViewTarget()->GetActorRotation()).GetScaledAxis(EAxis::Y);
	FVector Direction = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraRotation().Vector();
	float temp = Direction.Component(0);
	
	UE_LOG(LogTemp, Warning, TEXT("Dir1: %s"), *Direction.ToString());
	// UE_LOG(LogTemp, Warning, TEXT("%f"), (abs(temp) - 1));
	if(abs((abs(temp) - 1)) > 0.00000000000000000000000001){
		UE_LOG(LogTemp, Warning, TEXT("here"));
		Direction.Component(1) = -Direction.Component(1);
	}
	Direction.Component(0) = Direction.Component(1);
	Direction.Component(1) = temp;
	// FVector dir;
	// if((abs(x) - 1) > 0.00000000000000000000000001){
	// 	UE_LOG(LogTemp, Warning, TEXT("here"));
	// 	dir = FRotationMatrix(UGameplayStatics::GetPlayerController(GetWorld(),0)->GetViewTarget()->GetActorRotation()).GetScaledAxis(EAxis::X);
	// }else{
	// 	UE_LOG(LogTemp, Warning, TEXT("there"));
	// 	dir = FRotationMatrix(UGameplayStatics::GetPlayerController(GetWorld(),0)->GetViewTarget()->GetActorRotation()).GetScaledAxis(EAxis::Y);
	// 	// UE_LOG(LogTemp, Warning, TEXT("dir: %s"), *dir.ToString());
	// }
	UE_LOG(LogTemp, Warning, TEXT("Dir2: %s"), *Direction.ToString());
	// UE_LOG(LogTemp, Warning, TEXT("x: %f"), x);
    // FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	// if(abs(abs(Direction.Component(2)) - 1) > 0.00000000000000000000000001){
	AddMovementInput(Direction, Value);
	// FVector current = GetActorLocation();
	// current.Component();
	// SetActorLocation()
}



