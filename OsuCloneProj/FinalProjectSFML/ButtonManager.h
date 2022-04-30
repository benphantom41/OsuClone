#pragma once

#include "Trackable.h"
#include "Button.h"
#include "EventSystem.h"
#include "ChangeScreenEvent.h"
#include "SelectSongEvent.h"
#include "SwitchLanguageEvent.h"
#include "VolumeUpEvent.h"
#include "EndGameEvent.h"
#include <vector>

class Button;

class ButtonManager : public Trackable
{
public:

	ButtonManager() {};
	~ButtonManager() { cleanup(); };

	void addButton(int buttonName, int buttonShape, int posX, int posY);

	void cleanup();

	void update();

	void clickButton(int menuName, int x, int y);

	void resolveButtonClick(int buttonName);

	void draw(int menuName);

	bool findButtonBoundaries(int buttonID, int clickAtX, int clickAtY);

	std::vector<Button*> getButtonVec() { return mpButtons; };


	enum ButtonShapes
	{
		INVALID_BUTTON_SHAPE = -1,
		SQUARE_BUTTON,
		RECTANGLE_BUTTON,
		NUM_BUTTON_SHAPES
	};

private:
	std::vector<Button*> mpButtons;

};
