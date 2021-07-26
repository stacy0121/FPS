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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category=Movement)
	class UProjectileMovementComponent* movement;

	// �浹 ������Ʈ
	UPROPERTY(VisibleAnywhere, Category=Collision)
	class USphereComponent* collision;
	// �ܰ� ������Ʈ
	UPROPERTY(VisibleAnywhere, Category=Collision)
	class UStaticMeshComponent* bodyMesh;
};
