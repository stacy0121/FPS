// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSPlayer.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FPlayerInputDelegate, class UInputComponent*);                // delegate type 설정, parameter type                       // 1번, Ctrl+F12 매크로 정의된 파일

UCLASS()
class FPS_API AFPSPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category="FPSCamera")
	class UCameraComponent* fpsCamera;

	UPROPERTY(VisibleAnywhere, Category="BodyMesh")
	class USkeletalMeshComponent* bodyMesh;

	UPROPERTY(VisibleAnywhere, Category = PlayerMove)
	class UPlayerMove* playerMove;

	// 사용자 입력 처리를 담당할 Delegate - 위에서 설정한 자료형 사용
	FPlayerInputDelegate OnInputDelegate;                  // 2. 변수 선언
	
	UPROPERTY(VisibleAnywhere, Category = PlayerFire)
	class UPlayerFire* playerFire;
};