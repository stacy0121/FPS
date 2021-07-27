// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include <Components/SphereComponent.h>
#include <Components/StaticMeshComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 충돌체 등록
	collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	// 루트로 설정
	RootComponent = collision;
	collision->SetCollisionProfileName(TEXT("BlockAll"));

	// 외관
	bodyMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(collision);
	// 충돌 설정
	bodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// 발사체 컴포넌트
	movement=CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	// movement 가 적용될 컴포넌트 지정 - 부모자식 모두 적용됨
	movement->SetUpdatedComponent(collision);
	// movement 컴포넌트의 초기값 설정
	movement->bShouldBounce=true;  // 튕길지 여부
	movement->Bounciness=0.3f;  // 1이 완전 탄성

}

void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(3);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// 수정된 속성의 정보가 파라미터로 들어온다
void ABullet::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	// speed 값이 수정되었는지 확인
	if (PropertyChangedEvent.GetPropertyName() == TEXT("speed")) {
		// 속도
		movement->MaxSpeed = speed;
		movement->InitialSpeed = speed;
	}
}

