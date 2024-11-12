// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPPPlayerController.generated.h"

/**
 * 生命流程 Player()-> OnPossess()->beginPlay()
 *
 *
 * HUD 一般跟Controller 绑定 例如英雄联盟里面的生命条
 */
UCLASS()
class CPPBLANK_API ACPPPlayerController : public APlayerController
{
	GENERATED_BODY()



public:
		virtual void OnPossess(APawn* InPawn) override;
};
