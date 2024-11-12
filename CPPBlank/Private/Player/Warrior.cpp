// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Warrior.h"

#include "GameFramework/SpringArmComponent.h"


void AWarrior::Attack()
{

	//super ÊÇ·ÃÎÊ¸¸Àà
	//Super::Attack();

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Hello World %f"), CameraBoom->TargetArmLength));

	
}
