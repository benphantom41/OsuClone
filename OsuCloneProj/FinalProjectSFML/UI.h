#pragma once

#include "Trackable.h"
#include "GraphicsSystem.h"
#include "Game.h"

const Color WHITE = Color(255, 255, 255, 255);

class UI : public Trackable
{
public:
	UI(string filename, int size, float x, float y);
	~UI() {};

	void draw();
	void cleanup();

	void setMessage(string message) { mMessage = message; };
	void setColor(Color color) { mColor = color; };

	Color getColor() { return mColor; };
	Font* getFont() { return mpFont; };
	float getX() { return LocX; };
	float getY() { return LocY; };
	string getMessage() { return mMessage; };

	void addToLanguageVec(string text);

	enum Languages
	{
		INVALID_LANGUAGE = -1,
		ENGLISH,
		SPANISH,
		FRENCH,
		NUM_OF_LANGUAGES
	};
		
	void setLanguage(int newLanguage) { mCurrentLanguage = Languages(newLanguage); };

private:
	Font* mpFont;
	string mMessage = "";
	Color mColor = WHITE;
	float LocX;
	float LocY;

	std::vector<string> mLanguages;
	enum Languages mCurrentLanguage = ENGLISH;
};