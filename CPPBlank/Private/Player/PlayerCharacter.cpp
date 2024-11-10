// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include  "GameFramework/SpringArmComponent.h"
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values �����ǹ��캯�� ��һЩĬ�ϵĲ���
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//��������
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");

	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->SetRelativeRotation(FRotator(-40.f, 0.f, 0.f));// pitch yaw roll

	//���������ŵ������
	CameraBoom->SetupAttachment(RootComponent);


	
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>("Player Camera");

	//������ŵ�CameraBoom  �൱������һ��parent  ������bjs SetParent  Socketname �Ǵ�ue���洴����
	PlayerCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);


	//��Ҫ�ý�ɫ���ſ�������ת
	
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;



	// 
	// �������ת ���������ת

	CameraBoom->bUsePawnControlRotation = true;

	PlayerCamera->bUsePawnControlRotation = false;


	// 
	// ��ɫ��������ǰ���ķ���
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0);
	
	// Get
	//PlayerCamera->SetupAttachment(GetMesh(), FName("RootSocket"));

	


	  
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	
	//����ָ������ΪULocalPlayer��Player ���� ����һ����Ԫ���ʽ �����ж� ���ұ�֤��������������� if ����
	if(const ULocalPlayer* Player = (GEngine && GetWorld()) ? GEngine->GetFirstGamePlayer(GetWorld()) : nullptr)
		{

			
			  UEnhancedInputLocalPlayerSubsystem*  Subsystem =  ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(Player);


			  if (DefaultMapping) {

				  Subsystem->AddMappingContext(DefaultMapping, 0);
			  }

		}

	//��ӡ����
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Hello World"));

	//UE_LOG(LogTemp, Warning, TEXT("CameraBoom : targetArmLength: %f"), CameraBoom->TargetArmLength);

	//MyBlurprintFunction();
	
}

void APlayerCharacter::CallableFunction()
{
	UE_LOG(LogTemp, Warning, TEXT("Callable"));
}


// ������
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

		//��������¼�
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this,  &APlayerCharacter::Look);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this,  &APlayerCharacter::Move);


	}

}

