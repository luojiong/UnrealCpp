// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"



//前置声明类型
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



	// 相机
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr <UCameraComponent> PlayerCamera;

	//Input 输入
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


	//纯函数数据定义
	UFUNCTION(BlueprintPure)
	bool PureFunction();

	UFUNCTION(BlueprintImplementableEvent)
	//BLurprintImplementEvent
	void MyBlueprintFunction();

	//property 定义
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "U|Test")
	float testLen;

	void Look(const FInputActionValue& Value);

	void Move(const FInputActionValue& Value);


	//相机杆
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr <USpringArmComponent> CameraBoom;


	//演示如何组合  实际上就是在我们当前组件获取 然后设置值来访问
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Sphere", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> SphereComponent;


};
