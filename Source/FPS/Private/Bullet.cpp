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

	// �浹ü ���
	collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	// ��Ʈ�� ����
	RootComponent = collision;
	collision->SetCollisionProfileName(TEXT("BlockAll"));

	// �ܰ�
	bodyMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(collision);
	// �浹 ����
	bodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// �߻�ü ������Ʈ
	movement=CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	// movement �� ����� ������Ʈ ����
	movement->SetUpdatedComponent(collision);
	// movement ������Ʈ�� �ʱⰪ ����
	// ƨ���� ����
	movement->bShouldBounce=true;
	movement->Bounciness=0.3f;                     // 1�� ���� ź��
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

