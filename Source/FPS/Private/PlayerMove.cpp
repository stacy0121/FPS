
#include "PlayerMove.h"
#include "FPSPlayer.h"
#include "FPS.h"

// Sets default values for this component's properties
UPlayerMove::UPlayerMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true;  // Initialize �Լ� ���� ȣ��ǵ��� ����
}


// Called when the game starts
void UPlayerMove::BeginPlay()
{
	Super::BeginPlay();
	
	
}


void UPlayerMove::InitializeComponent()
{
	Super::InitializeComponent();

	me = Cast<AFPSPlayer>(GetOwner());  // Initialize �� ���� �ε�Ǳ� ������ BeginPlay ���� �̵�

	// Delegate �� ó���� �� �Լ��� ����ϰ� �ʹ�.(add)
	me->OnInputDelegate.AddUObject(this, &UPlayerMove::SetupPlayerInputComponent);
	me->bUseControllerRotationPitch = true;   // Pitch ȸ���� �����ϵ��� (������, �����Ϳ����� ����)
	// ���� ���� ��
	me->JumpMaxCount = 2;
}

// Called every frame
void UPlayerMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerMove::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// ����� �Է��� ó���� �Լ� bind
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &UPlayerMove::Vertical);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &UPlayerMove::Horizontal);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &UPlayerMove::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &UPlayerMove::LookUp);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &UPlayerMove::Jump);
}

void UPlayerMove::Horizontal(float value)
{
	// CharacterMovement
	// ����(�¿�)
	FVector dir = me->GetControlRotation().Quaternion().GetRightVector();
	// �̵�
	me->AddMovementInput(dir, value);
}

void UPlayerMove::Vertical(float value)
{
	// ���� - controller �� ���ؼ� �¿�
//	FVector dir = FRotationMatrix(me->GetControlRotation()).GetScaledAxis(EAxis::X);          // rotater? return
//	FVector dir = FTransform(me->GetControlRotation()).GetRotation().GetForwardVector();
	FVector dir = me->GetControlRotation().Quaternion().GetForwardVector();
	me->AddMovementInput(dir, value);
}

void UPlayerMove::Turn(float value)
{
	me->AddControllerYawInput(value);  // z ��(�翷)
}

void UPlayerMove::LookUp(float value)
{
	me->AddControllerPitchInput(value);  // y ��(���Ʒ�), UseControllerRotationPitch üũ �ʿ�
}

void UPlayerMove::Jump()
{
	me->Jump();
}
