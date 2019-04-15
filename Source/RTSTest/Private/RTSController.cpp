#include "RTSController.h"
#include "RTSHud.h"
#include "RTSUnitBase.h"
#include "NavigationSystem.h"
#include "DrawDebugHelpers.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

ARTSController::ARTSController()
{
	this->bShowMouseCursor = true;
	this->DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ARTSController::BeginPlay() 
{
	this->hud = Cast<ARTSHud>(GetHUD());
}

void ARTSController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LMBClick", IE_Pressed, this, &ARTSController::LMBPressed);
	InputComponent->BindAction("LMBClick", IE_Released, this, &ARTSController::LMBReleased);
	InputComponent->BindAction("RMBClick", IE_Pressed, this, &ARTSController::RMBPressed);
	InputComponent->BindAction("RMBClick", IE_Released, this, &ARTSController::RMBReleased);
}

void ARTSController::LMBPressed()
{
	if (!this->hud) return;

	this->hud->setInitialPos(this->hud->getMousePosition());
	this->hud->setIsSelecting(true);
}

void ARTSController::LMBReleased() 
{
	if (!this->hud) return;

	this->hud->setIsSelecting(false);
	this->SelectedCharacters = this->hud->SelectedCharacters;
}

void ARTSController::RMBPressed() {}
void ARTSController::RMBReleased()
{
	int i = 0;
	for (const auto& character : SelectedCharacters)
	{
		FHitResult hit;
		GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, hit);
		FVector location = hit.Location + FVector(i / 2 * 100, i % 2 * 100, 0);

		UAIBlueprintHelperLibrary::SimpleMoveToLocation(character->GetController(), location);

		DrawDebugSphere(GetWorld(), location, 25, 10, FColor::Green, false, 3);

		++i;
	}
}
