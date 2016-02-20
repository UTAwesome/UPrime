// (c) 2016 Evan 'Wail' Whiting

#include "PrimeMutator.h"
#include "UnrealTournament.h"
#include "UTRemoteRedeemer.h"
#include "Net/UnrealNetwork.h"
#include "UTProjectileMovementComponent.h"
#include "UPProjectileMovementComponent.h"

UUPProjectileMovementComponent::UUPProjectileMovementComponent(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	MinimumForwardVelocity = 0.f;
}
