#pragma once

#include <SFML/Graphics.hpp>
#include <Trackable.h>

class Color : public Trackable
{
	friend class GraphicsSystem;
	friend class GraphicsBuffer;

public:
	Color(int red, int green, int blue, int alpha);

	~Color();

private:

	int mRed;
	int mGreen;
	int mBlue;
	int mAplha;

	sf::Color mColor;
	sf::Color getColor();
};