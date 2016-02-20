// (c) 2016 Evan 'Wail' Whiting

#include "PrimeMutator.h"
#include "UnrealTournament.h"
#include "UTCharacterMovement.h"
#include "ActiveSound.h"
#include "AudioDevice.h"
#include "UTPickupWeapon.h"
#include "UTAnnouncer.h"
#include "UTPlayerInput.h"
#include "UTPlayerCameraManager.h"
#include "UTCheatManager.h"
#include "UTCTFGameState.h"
#include "Engine/Console.h"
#include "UTAnalytics.h"
#include "Runtime/Analytics/Analytics/Public/Analytics.h"
#include "Runtime/Analytics/Analytics/Public/Interfaces/IAnalyticsProvider.h"
#include "Online.h"
#include "UTOnlineGameSearchBase.h"
#include "OnlineSubsystemTypes.h"
#include "UTDroppedPickup.h"
#include "UTGameEngine.h"
#include "UnrealNetwork.h"
#include "UTProfileSettings.h"
#include "UTProgressionStorage.h"
#include "UTViewPlaceholder.h"
#include "DataChannel.h"
#include "Engine/GameInstance.h"
#include "UTSpectatorCamera.h"
#include "UTHUDWidget_NetInfo.h"
#include "UTWorldSettings.h"
#include "Engine/DemoNetDriver.h"
#include "UTGhostComponent.h"
#include "UTGameEngine.h"
#include "UTFlagInfo.h"
#include "UTProfileItem.h"
#include "UTMutator.h"
#include "UPPlayerController.h"

AUPPlayerController::AUPPlayerController(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void AUPPlayerController::ServerSay_Implementation(const FString& Message, bool bTeamMessage)
{
	if (AllowTextMessage(Message) && PlayerState != nullptr)
	{
		bool bSpectatorMsg = PlayerState->bOnlySpectator;

		for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
		{
			AUTBasePlayerController* UTPC = Cast<AUTBasePlayerController>(*Iterator);
			if (UTPC != nullptr)
			{
				if (!bTeamMessage || UTPC->GetTeamNum() == GetTeamNum())
				{
					// @! TODO restrict spectator chat only if game is set up to restrict spectator chat.
					AUTBaseGameMode* GameMode = GetWorld()->GetAuthGameMode<AUTBaseGameMode>();
					
					/*
					if (GameMode && GameMode->bRestrictSpectatorChat)
					{
						if (UTPC->PlayerState != nullptr && (!bSpectatorMsg || UTPC->PlayerState->bOnlySpectator))
						{
							UTPC->ClientSay(UTPlayerState, Message, (bTeamMessage ? ChatDestinations::Team : ChatDestinations::Local));
						}
					}
					else
					*/
					
					UTPC->ClientSay(UTPlayerState, Message, (bTeamMessage ? ChatDestinations::Team : ChatDestinations::Local));
					
				}
			}
		}
	}
}

void AUPPlayerController::ServerSuicide_Implementation()
{
	// throttle suicides to avoid spamming to grief own team in TDM
	if (GetPawn() != NULL)
	{
		AUTCharacter* Char = Cast<AUTCharacter>(GetPawn());
		if (Char != NULL)
		{
			Char->PlayerSuicide();
		}
	}
}
