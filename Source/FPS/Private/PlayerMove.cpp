
#include "PlayerMove.h"
#include "FPSPlayer.h"
#include "FPS.h"

// Sets default values for this component's properties
UPlayerMove::UPlayerMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true;  // Initialize 함수 정상 호출되도록 선언
}


// Called when the game starts
void UPlayerMove::BeginPlay()
{
	Super::BeginPlay();
	
	
}


void UPlayerMove::InitializeComponent()
{
	Super::InitializeComponent();

	me = Cast<AFPSPlayer>(GetOwner());  // Initialize 가 먼저 로드되기 때문에 BeginPlay 에서 이동

	// Delegate 에 처리할 내 함수를 등록하고 싶다.(add)
	me->OnInputDelegate.AddUObject(this, &UPlayerMove::SetupPlayerInputComponent);
	me->bUseControllerRotationPitch = true;   // Pitch 회전도 가능하도록 (생성자, 에디터에서도 가능)
	// 점프 가능 수
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
	// 사용자 입력을 처리할 함수 bind
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &UPlayerMove::Vertical);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &UPlayerMove::Horizontal);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &UPlayerMove::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &UPlayerMove::LookUp);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &UPlayerMove::Jump);
}

void UPlayerMove::Horizontal(float value)
{
	// CharacterMovement
	// 방향(좌우)
	FVector dir = me->GetControlRotation().Quaternion().GetRightVector();
	// 이동
	me->AddMovementInput(dir, value);
}

void UPlayerMove::Vertical(float value)
{
	// 방향 - controller 에 의해서 좌우
//	FVector dir = FRotationMatrix(me->GetControlRotation()).GetScaledAxis(EAxis::X);          // rotater? return
//	FVector dir = FTransform(me->GetControlRotation()).GetRotation().GetForwardVector();
	FVector dir = me->GetControlRotation().Quaternion().GetForwardVector();
	me->AddMovementInput(dir, value);
}

void UPlayerMove::Turn(float value)
{
	me->AddControllerYawInput(value);  // z 축(양옆)
}

void UPlayerMove::LookUp(float value)
{
	me->AddControllerPitchInput(value);  // y 축(위아래), UseControllerRotationPitch 체크 필요
}

void UPlayerMove::Jump()
{
	me->Jump();
}
