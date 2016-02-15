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
	
	/** Used to set capsule radius initially */
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Pawn)
	//float DefaultPawnCollisionRadius;
	
	/** Used to set capsule height initially */
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Pawn)
	//float DefaultPawnCollisionHalfHeight;
	
	/** BP-setter function for bTacComEnabled */
	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void SetTacComEnabled(bool bEnabled);
	
	
	/** Override for eye height */
	void BeginPlay() override;
	
	//-------------
	
	
	
	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	//virtual void UPO_SetHatClass(TSubclassOf<AUTHat> HatClass);
	
	/** Remove excess armor from the lowest absorption armor type.  Returns amount of armor removed. */
	//virtual int32 ReduceArmorStack(int32 Amount);
	
	// Allow overriding BP-inaccessible function. ReduceArmorStack redirects to this function.
	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	//virtual int32 UPO_ReduceArmorStack(int32 Amount);
	
	
	// Allow UP Character classes to override bSpawnProtectionEligible for character subclasses.
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Pawn)
	//bool UPO_bSpawnProtectionEligible;
	
	
	
	//------------------
	
	
	/** Return true if this character can block translocator telefrags. */
	//virtual bool CanBlockTelefrags();
	
	/** Pawns must be overlapping at least this much for a telefrag to occur. */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Pawn)
	//float MinOverlapToTelefrag;
	
	
	
	
	//UFUNCTION()
	//void FireRateChanged();
	
};