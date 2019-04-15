#include "RTSUnitBase.h"
#include "Components/DecalComponent.h"

// Sets default values
ARTSUnitBase::ARTSUnitBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->cursor = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	this->cursor->SetupAttachment(RootComponent);
	this->cursor->DecalSize = FVector(16.f, 32.f, 32.f);
	this->cursor->SetRelativeRotation(FRotator(90.f, 0.f, 0.f).Quaternion());

	this->cursor->SetVisibility(false);
}

// Called when the game starts or when spawned
void ARTSUnitBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARTSUnitBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ARTSUnitBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ARTSUnitBase::setCursorSelected(bool selected)
{
	this->cursor->SetVisibility(selected);
}
