// (c) 2016 Evan 'Wail' Whiting

#pragma once

#include "PrimeMutator.h"
#include "UTWeapon.h"

#include "UPWeapon.generated.h"

UCLASS(Blueprintable, Abstract, NotPlaceable, Config = Game)
class AUPWeapon : public AUTWeapon
{
	GENERATED_UCLASS_BODY()

	/** Call access to BP-inaccessible function */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	virtual void UP_StartFire(uint8 FireMode);
	
	/** Call access to BP-inaccessible function */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	virtual void UP_StopFire(uint8 FireMode);
	
	/** Call access to BP-inaccessible function */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	virtual void UP_GoToFireMode(uint8 NewFireMode);
	
	/** Call access to BP-inaccessible function */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	virtual void UP_UpdateTiming();
	
	/** Get the Zoom Material for dynamic material updating */
	UFUNCTION(BlueprintCallable, Category = Zoom)
	virtual void SetZoomMaterial(UMaterialInstanceDynamic* NewMaterial, uint8 FireModeNum);
	
	/** Get the Zoom Material for dynamic material updating */
	UFUNCTION(BlueprintPure, BlueprintCallable, Category = Zoom)
	UMaterialInstanceDynamic* GetZoomMaterial(uint8 FireModeNum);
};