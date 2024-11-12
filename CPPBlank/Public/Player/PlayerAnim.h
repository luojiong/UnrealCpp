// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerCharacter.h" // �������
#include "GameFramework/CharacterMovementComponent.h" 
#include "PlayerAnim.generated.h"




/**
 * 
 */
UCLASS()
class CPPBLANK_API UPlayerAnim : public UAnimInstance
{
	GENERATED_BODY()




public:
	virtual void NativeInitializeAnimation() override;

	virtual	void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<APlayerCharacter> PlayerCharacter;


	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UCharacterMovementComponent> PlayerCharacterMovement;


	UPROPERTY(BlueprintReadOnly)
	float Speed;



	
};
