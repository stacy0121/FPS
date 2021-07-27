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

	// 카메라 컴포넌트 추가
	fpsCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	fpsCamera->SetupAttachment(GetCapsuleComponent());
	fpsCamera->SetRelativeLocation(FVector(-30, 0, 60));
//	(X = -30.000000, Y = 0.000000, Z = 60.000000)                    // root 기준 좌표

	bodyMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(fpsCamera);

	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));
	playerFire = CreateDefaultSubobject<UPlayerFire>(TEXT("PlayerFire"));

	//bodyMesh 의 SkeletalMesh 데이터 할당하기
	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempMesh(TEXT("SkeletalMesh'/Game/FirstPerson/Character/Mesh/SK_Mannequin_Arms.SK_Mannequin_Arms'"));

	// 로드가 성공하면
	if (tempMesh.Succeeded()) {
		// 데이터 할당
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
void AFPSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)                     // BeginPlay 보다 먼저 호출
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
//	playerMove->SetupPlayerInputComponent(PlayerInputComponent);     함수를 있는대로 다 써주기보다는
	
	// 등록(add)된 Delegate 함수 모조리 실행해주기
	OnInputDelegate.Broadcast(PlayerInputComponent);

}

//delegate : 함수를 저장하기 위한 type 변수