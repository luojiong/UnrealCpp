// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPPPlayerController.generated.h"

/**
 * �������� Player()-> OnPossess()->beginPlay()
 *
 *
 * HUD һ���Controller �� ����Ӣ�����������������
 */
UCLASS()
class CPPBLANK_API ACPPPlayerController : public APlayerController
{
	GENERATED_BODY()



public:
		virtual void OnPossess(APawn* InPawn) override;
};
