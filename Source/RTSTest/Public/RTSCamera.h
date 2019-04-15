#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RTSCamera.generated.h"

class USceneComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class RTSTEST_API ARTSCamera : public APawn
{
	GENERATED_BODY()

public:
	ARTSCamera();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay")
	float cameraLowerBound;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay")
	float cameraUpperBoundX;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay")
	float cameraUpperBoundY;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay")
	float cameraSpeed;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay")
	APlayerController* PlayerController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay")
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY()
	int ScreenWidth;

	UPROPERTY()
	int ScreenHeight;
	
	UFUNCTION()
	FVector GetCameraMoveDirection();
};
