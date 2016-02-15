#include "PrimeMutator.h"

#include "UTPickupWeapon.h"

APrimeMutator::APrimeMutator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool APrimeMutator::CheckRelevance_Implementation(AActor* Other)
{
	return Super::CheckRelevance_Implementation(Other);
}