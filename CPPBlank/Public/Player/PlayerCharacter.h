// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"



//ǰ����������
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class USphereComponent;

UCLASS()
class CPPBLANK_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Sets default values for this character's properties
	APlayerCharacter();

	UFUNCTION(BlueprintCallable,Category="Action")
	virtual void Attack();


private:



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


	UPROPERTY(EditDefaultsOnly, Category = "Input")
	//InputAction
	TObjectPtr<UInputAction> AttackAction;



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


	//�����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr <USpringArmComponent> CameraBoom;


	//��ʾ������  ʵ���Ͼ��������ǵ�ǰ�����ȡ Ȼ������ֵ������
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Sphere", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> SphereComponent;


};
