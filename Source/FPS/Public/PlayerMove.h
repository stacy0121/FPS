// 사용자 입력을 받아 이동
// 필요 속성:이동 속도, 소유 액터

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerMove.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_API UPlayerMove : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerMove();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void InitializeComponent() override;                  // setup 함수보다 먼저 호출되는 life cycle 함수

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	// 필요 속성:소유 액터
	UPROPERTY()
	class AFPSPlayer* me;

	//이동
	void Horizontal(float value);
	void Vertical(float value);
	// 회전
	void Turn(float value);
	void LookUp(float value);
	//점프
	void Jump();
};
