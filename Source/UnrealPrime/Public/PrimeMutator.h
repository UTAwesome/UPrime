// (c) 2016 Evan 'Wail' Whiting

#pragma once

#include "Core.h"
#include "Engine.h"
#include "UTMutator.h"
#include "UTWeapon.h"

#include "PrimeMutator.generated.h"

UCLASS(Blueprintable, Meta = (ChildCanTick))
class APrimeMutator : public AUTMutator
{
	GENERATED_UCLASS_BODY()

	bool CheckRelevance_Implementation(AActor* Other) override;

	// Pure placeholder for now, is a mutator even needed?
};