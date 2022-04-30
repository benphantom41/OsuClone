#include "UI.h"

UI::UI(string filename, int size, float x, float y)
{
	mpFont = new Font(filename, size);
	LocX = x;
	LocY = y;
}

void UI::draw()
{
	Game::getInstance()->getSystem()->getGraphicsSystem()->writeText(mpFont, mColor, mLanguages[mCurrentLanguage] + mMessage, LocX, LocY);
}

void UI::cleanup()
{
	delete mpFont;
}

void UI::addToLanguageVec(string text)
{
	mLanguages.push_back(text);
}

