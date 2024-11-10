// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include  "GameFramework/SpringArmComponent.h"
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values 这里是构造函数 做一些默认的操作
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//创建变量
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");

	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->SetRelativeRotation(FRotator(-40.f, 0.f, 0.f));// pitch yaw roll

	//将变量附着到根组件
	CameraBoom->SetupAttachment(RootComponent);


	
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>("Player Camera");

	//相机附着到CameraBoom  相当于设置一个parent  类似于bjs SetParent  Socketname 是从ue里面创建的
	PlayerCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);


	//不要让角色随着控制器旋转
	
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;



	// 
	// 相机杆旋转 而相机不旋转

	CameraBoom->bUsePawnControlRotation = true;

	PlayerCamera->bUsePawnControlRotation = false;


	// 
	// 角色面向我们前进的方向
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0);
	
	// Get
	//PlayerCamera->SetupAttachment(GetMesh(), FName("RootSocket"));

	


	  
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	
	//开辟指针类型为ULocalPlayer的Player 变量 并做一个三元表达式 进行判断 并且保证变量作用域存在在 if 块内
	if(const ULocalPlayer* Player = (GEngine && GetWorld()) ? GEngine->GetFirstGamePlayer(GetWorld()) : nullptr)
		{

			
			  UEnhancedInputLocalPlayerSubsystem*  Subsystem =  ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(Player);


			  if (DefaultMapping) {

				  Subsystem->AddMappingContext(DefaultMapping, 0);
			  }

		}

	//打印调试
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Hello World"));

	//UE_LOG(LogTemp, Warning, TEXT("CameraBoom : targetArmLength: %f"), CameraBoom->TargetArmLength);

	//MyBlurprintFunction();
	
}

void APlayerCharacter::CallableFunction()
{
	UE_LOG(LogTemp, Warning, TEXT("Callable"));
}


// 纯函数
bool APlayerCharacter::PureFunction()
{
	return false;
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::Move(const FInputActionValue& Value) {

	FVector2D MoveVector = Value.Get<FVector2D>();

	if (Controller) {

		const FRotator Rotation = Controller->GetControlRotation();

		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		const FVector RightDirection  = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);


		AddMovementInput(ForwardDirection, MoveVector.X);
		AddMovementInput(RightDirection, MoveVector.Y);

		


		
		//AddControllerYawInput(MoveVector.X);
		//AddControllerPitchInput(MoveVector.Y);
	}

}

void APlayerCharacter::Look(const FInputActionValue& Value) {

	FVector2D LookVector = Value.Get<FVector2D>();
	

	if (Controller) {
		AddControllerYawInput(LookVector.X);
		AddControllerPitchInput(LookVector.Y);
	}

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)

{


	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		//绑定输入的事件
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this,  &APlayerCharacter::Look);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this,  &APlayerCharacter::Move);


	}

}

