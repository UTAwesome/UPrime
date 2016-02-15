// (c) 2015 Evan 'Wail' Whiting

#include "PrimeMutator.h"
#include "UPCharacter.h"

#include "Core.h"
#include "Engine.h"
#include "ModuleManager.h"
#include "ModuleInterface.h"

class FPrimeMutatorPlugin : public IModuleInterface
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FPrimeMutatorPlugin, PrimeMutator )

void FPrimeMutatorPlugin::StartupModule()
{
	
}


void FPrimeMutatorPlugin::ShutdownModule()
{
	
}



