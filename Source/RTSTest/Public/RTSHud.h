#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RTSHud.generated.h"

class ARTSUnitBase;

UCLASS()
class RTSTEST_API ARTSHud : public AHUD
{
	GENERATED_BODY()
protected:
	FVector2D initialPos;
	FVector2D currentPos;

	UPROPERTY()
	bool isSelecting;

public:

	UPROPERTY(VisibleAnywhere, Category = "Gameplay", BlueprintReadOnly)
	TArray<ARTSUnitBase*> SelectedCharacters;

	virtual void DrawHUD() override;
	
	FORCEINLINE FVector2D getMousePosition() const
	{
		float xOut;
		float yOut;
		GetOwningPlayerController()->GetMousePosition(xOut, yOut);

		return FVector2D(xOut, yOut);
	}

	FORCEINLINE bool getIsSelecting() const { return this->isSelecting; }
	FORCEINLINE void setIsSelecting(bool select) { this->isSelecting = select; }

	FORCEINLINE const FVector2D& getInitialPos() const { return this->initialPos; }
	FORCEINLINE const FVector2D& getCurrentPos() const { return this->currentPos; }
	FORCEINLINE void setInitialPos(const FVector2D& pos) { this->initialPos = pos; }
	FORCEINLINE void setCurrentPos(const FVector2D& pos) { this->currentPos = pos; }
};
