// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/CPPPlayerController.h"

void ACPPPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	UE_LOG(LogTemp,Warning,TEXT("ACPPPlayerController OnPossess"))

	if(InPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("InPawn OnPossess"))

			InPawn->SetActorLocation(FVector(0.f, 0.f, 0.f));
	}
}
