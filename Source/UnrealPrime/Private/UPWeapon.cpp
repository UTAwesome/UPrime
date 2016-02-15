// (c) 2016 Evan 'Wail' Whiting

// Infinite To-Do List
// O Way to Set the Weapon's Default Crosshair from within the weapon itself (allow User Customization)
// O Refactor Firing States
// O Allow decoupled firing rates (e.g. Shock Rifle secondary + primary vs. secondary + primary)
// O UPProjectileMovement : Gradual Deceleration
// O UPProjectileMovement : Set Homing Location via vector location
// O Spectators should be able to chat in game WTF.



#include "PrimeMutator.h"
#include "UnrealTournament.h"
#include "UPWeapon.h"
#include "UTWeapon.h"
#include "UTWeaponState.h"
#include "UTWeaponStateFiring.h"
#include "UTWeaponStateActive.h"
#include "UTWeaponStateEquipping.h"
#include "UTWeaponStateUnequipping.h"
#include "UTWeaponStateInactive.h"
#include "UTWeaponStateFiringCharged.h"
#include "UTWeaponStateZooming.h"
#include "UTWeaponAttachment.h"
#include "UnrealNetwork.h"
#include "UTHUDWidget.h"
#include "EditorSupportDelegates.h"
#include "Particles/ParticleSystemComponent.h"
#include "UTImpactEffect.h"
#include "UTCharacterMovement.h"
#include "UTWorldSettings.h"
#include "UTPlayerCameraManager.h"
#include "UTHUD.h"
#include "UTGameViewportClient.h"
#include "UTCrosshair.h"
#include "UTDroppedPickup.h"

AUPWeapon::AUPWeapon(const class FObjectInitializer& ObjectInitializer)
{
	FiringState.Empty();
	FireInterval.Empty();
	for (int32 i = 0; i < 4; i++)
	{
		UUTWeaponStateFiring* NewState = ObjectInitializer.CreateDefaultSubobject<UUTWeaponStateFiring, UUTWeaponStateFiring>(this, FName(*FString::Printf(TEXT("UPFiringState%i"), i)), false);
		if (NewState != NULL)
		{
			FiringState.Add(NewState);
			FireInterval.Add(1.0f);
		}
	}
}

void AUPWeapon::UP_StartFire(uint8 FireMode)
{
	StartFire(FireMode);
}

void AUPWeapon::UP_StopFire(uint8 FireMode)
{
	StopFire(FireMode);
}

void AUPWeapon::UP_GoToFireMode(uint8 NewFireMode)
{
	GotoFireMode(NewFireMode);
}

void AUPWeapon::UP_UpdateTiming()
{
	UpdateTiming();
}

void AUPWeapon::SetZoomMaterial(UMaterialInstanceDynamic* NewMaterial, uint8 FireModeNum)
{
	if (FiringState.IsValidIndex(FireModeNum) && FiringState[FireModeNum])
    {
		UUTWeaponStateZooming* ZoomFireMode = Cast<UUTWeaponStateZooming>(FiringState[FireModeNum]);
		
		if (ZoomFireMode)
		{
			ZoomFireMode->OverlayMI = NewMaterial;
		}
	}
}

UMaterialInstanceDynamic* AUPWeapon::GetZoomMaterial(uint8 FireModeNum)
{
    if (FiringState.IsValidIndex(FireModeNum) && FiringState[FireModeNum])
    {
		UUTWeaponStateZooming* ZoomFireMode = Cast<UUTWeaponStateZooming>(FiringState[FireModeNum]);
		
		if (ZoomFireMode)
		{
			return ZoomFireMode->OverlayMI;
		}
		
		return NULL;
    }

    return NULL;
}
