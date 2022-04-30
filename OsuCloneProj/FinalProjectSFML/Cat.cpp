#include "Cat.h"

void Cat::swapSprite(int x, int y)
{
	//X 266
	//Y 200

	if (y < 200)
	{
		if (x < 266)
		{
			mCurrentSprite = 0;
		}
		else if (x < 532)
		{
			mCurrentSprite = 1;
		}
		else
		{
			mCurrentSprite = 2;
		}
	}
	else if (y < 400)
	{
		if (x < 266)
		{
			mCurrentSprite = 3;
		}
		else if (x < 532)
		{
			mCurrentSprite = 4;
		}
		else
		{
			mCurrentSprite = 5;
		}
	}
	else
	{
		if (x < 266)
		{
			mCurrentSprite = 6;
		}
		else if (x < 532)
		{
			mCurrentSprite = 7;
		}
		else
		{
			mCurrentSprite = 8;
		}
	}
}

void Cat::addSprite(Sprite* newSprite)
{
	mSprites.push_back(newSprite);
}

void Cat::draw()
{
	Game::getInstance()->getSystem()->getGraphicsSystem()->simpleDraw(mSprites[mCurrentSprite], 600, 400);
}

void Cat::cleanup()
{
	unsigned size = mSprites.size();

	for (unsigned i = 0; i < size; i++)
	{
		delete mSprites[i];
	}
}