// ����� �Է��� �޾� �̵�
// �ʿ� �Ӽ�:�̵� �ӵ�, ���� ����

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

	virtual void InitializeComponent() override;                  // setup �Լ����� ���� ȣ��Ǵ� life cycle �Լ�

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	// �ʿ� �Ӽ�:���� ����
	UPROPERTY()
	class AFPSPlayer* me;

	//�̵�
	void Horizontal(float value);
	void Vertical(float value);
	// ȸ��
	void Turn(float value);
	void LookUp(float value);
	//����
	void Jump();
};
