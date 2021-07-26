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
	// movement 가 적용될 컴포넌트 지정
	movement->SetUpdatedComponent(collision);
	// movement 컴포넌트의 초기값 설정
	// 튕길지 여부
	movement->bShouldBounce=true;
	movement->Bounciness=0.3f;                     // 1이 완전 탄성
}

void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

