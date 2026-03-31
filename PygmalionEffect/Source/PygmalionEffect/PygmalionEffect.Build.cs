// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PygmalionEffect : ModuleRules
{
	public PygmalionEffect(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput",
            "Niagara",          // Effect
		    "UMG",              // UI
		    "AIModule",         // AI (FSM/BT)
		    "GameplayTasks",    // AI/Ability º¸Á¶
		    "NavigationSystem" // NavMesh
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
