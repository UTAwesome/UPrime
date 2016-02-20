// (c) 2016 Evan 'Wail' Whiting

#pragma once

#include "PrimeMutator.h"
#include "UTCharacter.h"

#include "UPCharacter.generated.h"

UCLASS(config=Game, collapsecategories)
class AUPCharacter : public AUTCharacter
{
	GENERATED_UCLASS_BODY()

	/** Call access to BP-inaccessible function */
	UFUNCTION(BlueprintCallable, Category = Cosmetic)
	virtual void UP_SetHatClass(TSubclassOf<AUTHat> HatClass);
	
	/** Call access to BP-inaccessible function */
	UFUNCTION(BlueprintCallable, Category = Cosmetic)
	virtual bool UP_IsWearingAnyCosmetic();
	
	/** Allow intercept of weapon skins to prevent */
	virtual void SetSkinForWeapon(UUTWeaponSkin* WeaponSkin) override;
	
	/** Call access to BP-inaccessible function */
	UFUNCTION(BlueprintCallable, Category = Cosmetic)
	virtual void UP_SetSkinForWeapon(UUTWeaponSkin* WeaponSkin);
	
	// @! TEMP
	/** Workaround for BP-inaccessible value. Sets UTCharacter.DefaultBaseEyeHeight. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Camera)
	float UP_DefaultBaseEyeHeight;
	
	/** BP-setter function for bTacComEnabled */
	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void SetTacComEnabled(bool bEnabled);

	/** Call access to BP-inaccessible function. Call DeactivateSpawnProtection() */
	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void UP_DeactivateSpawnProtection();

	/** Override so we can give BP access. */
	virtual bool CanBlockTelefrags();

	/** BP function */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Pawn)
	bool UP_CanBlockTelefrags();
	
	/** Override for eye height */
	void BeginPlay() override;

};