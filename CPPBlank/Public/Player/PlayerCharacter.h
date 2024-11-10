// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"



//ǰ����������
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class CPPBLANK_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();


private:
	//�����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta=(AllowPrivateAccess="true"))
	TObjectPtr <USpringArmComponent> CameraBoom;


	// ���
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr <UCameraComponent> PlayerCamera;

	//Input ����
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMapping;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	//InputAction
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	//InputAction
	TObjectPtr<UInputAction> LookAction;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void CallableFunction(); 


	//���������ݶ���
	UFUNCTION(BlueprintPure)
	bool PureFunction();

	UFUNCTION(BlueprintImplementableEvent)
	//BLurprintImplementEvent
	void MyBlueprintFunction();

	//property ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "U|Test")
	float testLen;

	void Look(const FInputActionValue& Value);

	void Move(const FInputActionValue& Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
