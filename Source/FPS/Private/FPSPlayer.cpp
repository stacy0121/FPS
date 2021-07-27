// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSPlayer.h"
#include "FPS.h"
#include <Camera/CameraComponent.h>
#include <Components/CapsuleComponent.h>
#include <Components/SkeletalMeshComponent.h>
#include "PlayerMove.h"
#include "PlayerFire.h"


// Sets default values
AFPSPlayer::AFPSPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ī�޶� ������Ʈ �߰�
	fpsCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	fpsCamera->SetupAttachment(GetCapsuleComponent());
	fpsCamera->SetRelativeLocation(FVector(-30, 0, 60));
//	(X = -30.000000, Y = 0.000000, Z = 60.000000)                    // root ���� ��ǥ

	bodyMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(fpsCamera);

	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));
	playerFire = CreateDefaultSubobject<UPlayerFire>(TEXT("PlayerFire"));

	//bodyMesh �� SkeletalMesh ������ �Ҵ��ϱ�
	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempMesh(TEXT("SkeletalMesh'/Game/FirstPerson/Character/Mesh/SK_Mannequin_Arms.SK_Mannequin_Arms'"));

	// �ε尡 �����ϸ�
	if (tempMesh.Succeeded()) {
		// ������ �Ҵ�
		bodyMesh->SetSkeletalMesh(tempMesh.Object);
	}
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;

//	CALLINFO();              CDO

//	PRINTLOG(TEXT("%s"), TEXT("Hello World"));
}

// Called when the game starts or when spawned
void AFPSPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)                     // BeginPlay ���� ���� ȣ��
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
//	playerMove->SetupPlayerInputComponent(PlayerInputComponent);     �Լ��� �ִ´�� �� ���ֱ⺸�ٴ�
	
	// ���(add)�� Delegate �Լ� ������ �������ֱ�
	OnInputDelegate.Broadcast(PlayerInputComponent);

}

//delegate : �Լ��� �����ϱ� ���� type ����