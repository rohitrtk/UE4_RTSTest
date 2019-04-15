#include "RTSHud.h"
#include "RTSTest.h"
#include "RTSUnitBase.h"
#include "Engine/GameEngine.h"

void ARTSHud::DrawHUD()
{
	if (!isSelecting) return;

	for (const auto& character : SelectedCharacters) character->setCursorSelected(false);
	SelectedCharacters.Empty();

	this->currentPos = getMousePosition();

	float width = currentPos.X - initialPos.X;
	float height = currentPos.Y - initialPos.Y;

	DrawRect(FLinearColor(0, 1, 0, .15), initialPos.X, initialPos.Y, width, height);

	GetActorsInSelectionRectangle<ARTSUnitBase>(initialPos, currentPos, SelectedCharacters, false, false);

	for (const auto& character : SelectedCharacters) character->setCursorSelected(true);
}