#include "Button.h"

Button::Button()
{
	mButtonName = -1;
	mWidth = 0;
	mHeight = 0;
	mLocX = 0;
	mLocY = 0;
}

Button::Button(int buttonName, int width, int height, float x, float y)
{
	mButtonName = buttonName;
	mWidth = width;
	mHeight = height;
	mLocX = x;
	mLocY = y;
}

void Button::draw()
{
	Game::getInstance()->getSystem()->getGraphicsSystem()->drawButton(mWidth, mHeight, mLocX, mLocY, mColor);
}

void Button::cleanup()
{
}
