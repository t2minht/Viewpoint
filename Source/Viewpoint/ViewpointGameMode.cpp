// Copyright Epic Games, Inc. All Rights Reserved.

#include "ViewpointGameMode.h"
#include "ViewpointCharacter.h"
#include "UObject/ConstructorHelpers.h"

AViewpointGameMode::AViewpointGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
