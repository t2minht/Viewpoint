// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Viewpoint : ModuleRules
{
	public Viewpoint(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
