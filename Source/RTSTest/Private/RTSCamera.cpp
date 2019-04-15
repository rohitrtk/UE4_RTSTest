#include "RTSCamera.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ARTSCamera::ARTSCamera()
{
	this->SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	RootComponent = this->SceneComponent;

	this->SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	this->SpringArmComponent->SetupAttachment(RootComponent);
	this->SpringArmComponent->bDoCollisionTest = false;
	//this->SpringArmComponent->SetRelativeRotation(FRotator(-40.f, 40.f, 0.f));
	this->SpringArmComponent->SetRelativeRotation(FRotator(-40.f, 0.f, 0.f));

	this->CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	this->CameraComponent->SetupAttachment(this->SpringArmComponent);
	this->CameraComponent->FieldOfView = 120.f;

	this->cameraLowerBound = 10.f;
	this->cameraUpperBoundX = -1;
	this->cameraUpperBoundY = -1;

	this->cameraSpeed = 5.f;
}

void ARTSCamera::BeginPlay()
{
	Super::BeginPlay();
	
	this->PlayerController = Cast<APlayerController>(GetController());
	this->PlayerController->GetViewportSize(ScreenWidth, ScreenHeight);

	this->cameraUpperBoundX = this->ScreenWidth - this->cameraLowerBound;
	this->cameraUpperBoundY = this->ScreenHeight - this->cameraLowerBound;
}

void ARTSCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorWorldOffset(GetCameraMoveDirection() * cameraSpeed);
}

FVector ARTSCamera::GetCameraMoveDirection()
{
	float xOut;
	float yOut;
	int moveX = 0;
	int moveY = 0;

	this->PlayerController->GetMousePosition(xOut, yOut);

	if (xOut <= cameraLowerBound) moveX = -1;
	else if (xOut >= cameraUpperBoundX) moveX = 1;

	if (yOut <= cameraLowerBound) moveY = 1;
	else if (yOut >= cameraUpperBoundY) moveY = -1;

	// x and y are flipped because of axis
	return FVector(moveY, moveX, 0.f);
}
