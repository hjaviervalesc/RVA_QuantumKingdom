using UnrealBuildTool;

public class QuantumKingdom : ModuleRules
{
    public QuantumKingdom(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "AIModule",
            "GameplayTasks"
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
        });
    }
}
