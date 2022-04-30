#include "Font.h"
Font::Font()
{
}

Font::Font(string name, int size)
{
	mFont = name;
	mSize = size;
	cour_font = al_load_ttf_font(mFont.c_str(), mSize, 0);
}

Font::~Font()
{
	al_destroy_font(cour_font);
	cour_font = NULL;
}

int Font::getSize()
{
	return mSize;
}
