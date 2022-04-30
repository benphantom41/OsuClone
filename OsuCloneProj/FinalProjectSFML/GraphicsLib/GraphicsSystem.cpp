//SFML Implementation:

#include "GraphicsSystem.h"

GraphicsSystem::GraphicsSystem()
{

}

GraphicsSystem::~GraphicsSystem()
{
	cleanUp();
}

int GraphicsSystem::init()
{
	mDisplay = new sf::RenderWindow;

	return 0;
}

//initialize the display
void GraphicsSystem::initializeDisplay(int width, int height)
{
	mSystemWidth = width;
	mSystemHeight = height;
	if (!mIsInnited)
	{
		mDisplay->create(sf::VideoMode(mSystemWidth, mSystemHeight), "Bongo Cat Plays Game");
		mDisplay->setMouseCursorVisible(false);
		mIsInnited = true;
	}
	//you can make a bool = true here
}

//delete the backBuffer and destroy the display
void GraphicsSystem::cleanUp()
{
	/*if mInit;
	{
	cleanUp()
	}*/
	
	if (mIsInnited)
	{
		mDisplay->clear();
		//delete mpDisplay;
		//mpDisplay = NULL;
		//delete mpBackBuffer;
		//mpBackBuffer = NULL;

		mIsInnited = false;
	}
}

int GraphicsSystem::getHeight()
{
	return mSystemHeight;
}

int GraphicsSystem::getWidth()
{
	return mSystemWidth;
}


//flips display
void GraphicsSystem::flip()
{
	mDisplay->display();
}

void GraphicsSystem::simpleDraw(Sprite * image, int x, int y)
{
	sf::Sprite tmpSprite;
	tmpSprite.setTexture(image->pGetBuffer()->getBuffer());
	tmpSprite.setTextureRect(sf::IntRect(image->getSourceX(), image->getSourceY(), image->getWidthSprite(), image->getHeightSprite()));
	tmpSprite.setScale(1, 1);
	tmpSprite.setPosition(static_cast<float>(x), static_cast<float>(y));

	mDisplay->draw(tmpSprite);

}

void GraphicsSystem::simpleDraw(Sprite * image, int x, int y, float scale)
{
	sf::Sprite tmpSprite;
	tmpSprite.setTexture(image->pGetBuffer()->getBuffer());
	tmpSprite.setTextureRect(sf::IntRect(image->getSourceX(), image->getSourceY(), image->getWidthSprite(), image->getHeightSprite()));
	tmpSprite.setScale(scale, scale);
	tmpSprite.setPosition(static_cast<float>(x), static_cast<float>(y));

	mDisplay->draw(tmpSprite);

}

void GraphicsSystem::draw(GraphicsBuffer *gBuff, float locX, float locY, float systemWidth, float systemHeight, float dX, float dY, float scaleFactor, int flags)
{
	sf::Sprite tmpSprite;
	tmpSprite.setTexture(gBuff->getBuffer());
	tmpSprite.setScale(scaleFactor, scaleFactor);
	tmpSprite.setPosition(dX, dY);
	mDisplay->draw(tmpSprite);
}

void GraphicsSystem::draw(GraphicsBuffer * target, Sprite * sprite, int x, int y, float scale)
{
	sf::Sprite tmpSprite;
	tmpSprite.setTexture(sprite->pGetBuffer()->getBuffer());
	tmpSprite.setTextureRect(sf::IntRect(sprite->getSourceX(), sprite->getSourceY(), sprite->getWidthSprite(), sprite->getHeightSprite()));
	tmpSprite.setScale(scale, scale);
	tmpSprite.setPosition(static_cast<float>(x), static_cast<float>(y));

}

void GraphicsSystem::drawButton(int width, int height, float x, float y, Color color)
{
	sf::RectangleShape tmpRectangle;
	tmpRectangle.setSize(sf::Vector2f(static_cast<float>(width), static_cast<float>(height)));
	tmpRectangle.setFillColor(color.getColor());
	tmpRectangle.setPosition(x, y);

	mDisplay->draw(tmpRectangle);
}

//write text
void GraphicsSystem::writeText(Font * font, Color c, string text, float x, float y)
{
	sf::Text tempTXT;
	tempTXT.setFont(*font->getFont());
	tempTXT.setFillColor(c.getColor());
	tempTXT.setString(text);
	tempTXT.setCharacterSize(font->getSize());
	tempTXT.setPosition(x, y);

	mDisplay->draw(tempTXT);

}

void GraphicsSystem::writeText(GraphicsBuffer * target, Font * font, Color c, string text, float x, float y)
{
	sf::Text tempTXT;
	tempTXT.setFont(*font->getFont());
	tempTXT.setFillColor(c.getColor());
	tempTXT.setString(text);
	tempTXT.setPosition(x, y);
}
