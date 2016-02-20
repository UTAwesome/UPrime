// (c) 2016 Evan 'Wail' Whiting

#pragma once

#include "PrimeMutator.h"

#include "UPProjectileMovementComponent.generated.h"

UCLASS(ClassGroup = Movement, meta = (BlueprintSpawnableComponent))
class UUPProjectileMovementComponent : public UUTProjectileMovementComponent
{
	GENERATED_UCLASS_BODY()
	
	/** For use with negative acceleration rates.
		Negative acceleration rates that are too high may still cause the projectile to flip directions.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
	float MinimumForwardVelocity;
	
	virtual FVector ComputeVelocity(FVector InitialVelocity, float DeltaTime) const override
	{
		InitialVelocity += InitialVelocity.GetSafeNormal() * AccelRate * DeltaTime + Acceleration * DeltaTime;
		
		// @! TODO: Clamp MinimumForwardVelocity

		return Super::ComputeVelocity(InitialVelocity, DeltaTime);
	}
};