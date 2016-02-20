// (c) 2016 Evan 'Wail' Whiting

#include "PrimeMutator.h"
#include "UnrealTournament.h"
#include "UTCharacter.h"
#include "UTCharacterMovement.h"
#include "UTWeaponAttachment.h"
#include "UnrealNetwork.h"
#include "UTDmgType_Suicide.h"
#include "UTDmgType_Fell.h"
#include "UTDmgType_Drown.h"
#include "Particles/ParticleSystemComponent.h"
#include "UTTeamGameMode.h"
#include "UTDmgType_Telefragged.h"
#include "UTDmgType_BlockedTelefrag.h"
#include "UTDmgType_FeignFail.h"
#include "UTReplicatedEmitter.h"
#include "UTWorldSettings.h"
#include "UTArmor.h"
#include "UTImpactEffect.h"
#include "UTGib.h"
#include "UTRemoteRedeemer.h"
#include "UTDroppedPickup.h"
#include "UTWeaponStateFiring.h"
#include "UTMovementBaseInterface.h"
#include "UTCharacterContent.h"
#include "UTPlayerCameraManager.h"
#include "ComponentReregisterContext.h"
#include "UTMutator.h"
#include "UTRewardMessage.h"
#include "StatNames.h"
#include "UTGhostComponent.h"
#include "UTTimedPowerup.h"
#include "UTWaterVolume.h"
#include "UTLift.h"
#include "UTWeaponSkin.h"

AUPCharacter::AUPCharacter(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UUTCharacterMovement>(ACharacter::CharacterMovementComponentName))
{
}

void AUPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// This will soon be irrelevant, but adding it in here for now.
	DefaultBaseEyeHeight = UP_DefaultBaseEyeHeight;
	CharacterCameraComponent->SetRelativeLocation(FVector(0.f, 0.f, DefaultBaseEyeHeight), false);
	
	//if (GetCapsuleComponent() && DefaultPawnCollisionRadius != 0 && DefaultPawnCollisionHalfHeight != 0)
	//{
	//	GetCapsuleComponent()->SetCapsuleSize(DefaultPawnCollisionRadius, DefaultPawnCollisionHalfHeight);
		
		// For default UTCharacter mesh ... 
		//Mesh.Location.Z = -1 * DefaultPawnCollisionHalfHeight;
	//}
}


void AUPCharacter::UP_DeactivateSpawnProtection()
{
	DeactivateSpawnProtection();
}

bool AUPCharacter::CanBlockTelefrags()
{
	if (UP_CanBlockTelefrags())
	{
		return true;
	}

	return false;
}

bool AUPCharacter::UP_CanBlockTelefrags_Implementation()
{
	return false;
}

void AUPCharacter::UP_SetHatClass(TSubclassOf<AUTHat> HatClass)
{
	SetHatClass(HatClass);
}

bool AUPCharacter::UP_IsWearingAnyCosmetic()
{
	return Super::IsWearingAnyCosmetic();
}

void AUPCharacter::SetSkinForWeapon(UUTWeaponSkin* WeaponSkin)
{
	// might want to be able to intercept calls here
	if (true)
	{
		Super::SetSkinForWeapon(WeaponSkin);
	}
}

void AUPCharacter::UP_SetSkinForWeapon(UUTWeaponSkin* WeaponSkin)
{
	SetSkinForWeapon(WeaponSkin);
}

void AUPCharacter::SetTacComEnabled(bool bEnabled)
{
	bTacComEnabled = bEnabled;
}

