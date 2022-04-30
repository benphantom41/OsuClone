#include "Font.h"

Font::Font()
{

}

Font::Font(string name, int size)
{
	mpFont = new sf::Font;

	mSize = size;
	mFont = name;

	mpFont->loadFromFile(name);
}

Font::~Font()
{
	delete mpFont;
}

int Font::getSize()
{
	return mSize;
}

sf::Font * Font::getFont()
{
	return mpFont;
}
