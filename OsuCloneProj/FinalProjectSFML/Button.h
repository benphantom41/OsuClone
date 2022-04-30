#pragma once

#include "Trackable.h"
#include "GraphicsSystem.h"
#include "Game.h"

const Color GREY = Color(119, 136, 153, 255);

class Button : public Trackable
{
public:
	Button();
	Button(int buttonName, int width, int height, float x, float y);
	~Button() {};

	void draw();
	void cleanup();

	int getButtonName() { return mButtonName; }
	Color getColor() { return mColor;  }
	int getWidth() { return mWidth; }
	int getHeight() { return mHeight; }
	float getX() { return mLocX; };
	float getY() { return mLocY; };

	enum ButtonNames
	{
		INVALID_BUTTON_NAME = -1,
		BUTTON_MENU_QUIT,
		BUTTON_MENU_RETURN,
		BUTTON_MAIN_MENU_START, //Sends you to the Level Select
		BUTTON_MAIN_MENU_LOAD, //Loads a Saved Game
		BUTTON_MAIN_MENU_OPTIONS, //Sends you to the Options Menu
		BUTTON_OPTIONS_VOLUME_UP,
		BUTTON_OPTIONS_VOLUME_DOWN,
		BUTTON_OPTIONS_LANGUAGE, //Sends you to the Language Select Menu
		BUTTON_LEVEL_SELECT_OPTION1,
		BUTTON_LEVEL_SELECT_OPTION2,
		BUTTON_LEVEL_SELECT_OPTION3,
		BUTTON_LANGUAGE_ENG,
		BUTTON_LANGUAGE_FRN,
		BUTTON_LANGUAGE_SPN,
		NUM_BUTTON_NAMES
	};

private:
	int mButtonName;
	Color mColor = GREY;
	int mWidth;
	int mHeight;
	float mLocX;
	float mLocY;
};