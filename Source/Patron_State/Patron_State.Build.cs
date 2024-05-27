// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Patron_State : ModuleRules
{
	public Patron_State(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
