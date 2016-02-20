// (c) 2016 Evan 'Wail' Whiting

#pragma once

#include "PrimeMutator.h"
#include "UTPlayerController.h"

#include "UPPlayerController.generated.h"

UCLASS(config=Game)
class AUPPlayerController : public AUTPlayerController
{
	GENERATED_UCLASS_BODY()
	
	/** override to disable spectators being unable to chat */
	virtual void ServerSay_Implementation(const FString& Message, bool bTeamMessage) override;
	
	/** override suicide prevention behavior */
	void ServerSuicide_Implementation() override;
	
};