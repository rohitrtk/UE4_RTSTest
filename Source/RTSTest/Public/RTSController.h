#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RTSController.generated.h"

class ARTSHud;
class ARTSUnitBase;

UCLASS()
class RTSTEST_API ARTSController : public APlayerController
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere, Category = "Hud", BlueprintReadOnly)
	ARTSHud* hud;

public:
	ARTSController();

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UFUNCTION()
	void LMBPressed();

	UFUNCTION()
	void LMBReleased();

	UFUNCTION()
	void RMBPressed();

	UFUNCTION()
	void RMBReleased();

	UPROPERTY(VisibleAnywhere, Category = "Gameplay", BlueprintReadOnly)
	TArray<ARTSUnitBase*> SelectedCharacters;

	FORCEINLINE ARTSHud* getHud() const { return this->hud; }
};
