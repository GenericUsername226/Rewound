// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Rewound : ModuleRules
{
	public Rewound(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
