#include "Color.h"

Color::Color(int red, int green, int blue, int alpha)
{
	mRed = red;
	mGreen = green;
	mBlue = blue;
	mAplha = alpha;

	mColor = sf::Color(mRed, mGreen, mBlue, mAplha);
}

Color::~Color()
{

}

sf::Color Color::getColor()
{
	return mColor;
}