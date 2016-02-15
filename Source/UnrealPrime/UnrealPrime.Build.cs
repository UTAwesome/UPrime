// Copyright 1998-2013 Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class UnrealPrime : ModuleRules
	{
		public UnrealPrime(TargetInfo Target)
        {
            PrivateIncludePaths.Add("UnrealPrime/Private");

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
                    "Engine",
                    "UnrealTournament",
				}
				);
		}
	}
}