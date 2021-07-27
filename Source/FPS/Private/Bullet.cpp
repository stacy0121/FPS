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
	// movement �� ����� ������Ʈ ���� - �θ��ڽ� ��� �����
	movement->SetUpdatedComponent(collision);
	// movement ������Ʈ�� �ʱⰪ ����
	movement->bShouldBounce=true;  // ƨ���� ����
	movement->Bounciness=0.3f;  // 1�� ���� ź��

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

// ������ �Ӽ��� ������ �Ķ���ͷ� ���´�
void ABullet::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	// speed ���� �����Ǿ����� Ȯ��
	if (PropertyChangedEvent.GetPropertyName() == TEXT("speed")) {
		// �ӵ�
		movement->MaxSpeed = speed;
		movement->InitialSpeed = speed;
	}
}

