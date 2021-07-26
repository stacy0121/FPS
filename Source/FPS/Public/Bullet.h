// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class FPS_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	virtual void PreInitializeComponents();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// 액터가 가지고 있는 특성 속성을 수정한 후에 호출되는 이벤트 함수 (root <-> Movement)
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	UPROPERTY(VisibleAnywhere, Category=Movement)
	class UProjectileMovementComponent* movement;

	// 충돌 컴포넌트
	UPROPERTY(VisibleAnywhere, Category=Collision)
	class USphereComponent* collision;
	// 외관 컴포넌트
	UPROPERTY(VisibleAnywhere, Category=Collision)
	class UStaticMeshComponent* bodyMesh;

	UPROPERTY(EditDefaultsOnly, Category=Speed)
	float speed = 500;
};
