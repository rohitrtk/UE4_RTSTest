#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RTSUnitBase.generated.h"

class UDecalComponent;

UCLASS()
class RTSTEST_API ARTSUnitBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARTSUnitBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay")
	UDecalComponent* cursor;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE UDecalComponent* getCursor() const { return this->cursor; }

	void setCursorSelected(bool selected);
};
