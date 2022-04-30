#include "CatHand.h"

void CatHand::swapSprite() // This function only really needs to switch between two different sprites, the "Z" and "X" press one.
{
	if (mCurrentSprite == 0) //If the hand's sprite is currently at KeyTapHand1, then...
	{
		mCurrentSprite = 1; //Switch it to KeyTapHand2, the "X" key press.
	}
	else //Otherwise...
	{
		mCurrentSprite = 0; //Default to the "Z" key being pressed.
	}
}

void CatHand::addSprite(Sprite * newSprite)
{

	mSprites.push_back(newSprite);
}

void CatHand::draw()
{
	Game::getInstance()->getSystem()->getGraphicsSystem()->simpleDraw(mSprites[mCurrentSprite], 600, 400);
}

void CatHand::cleanup()
{
	unsigned size = mSprites.size();

	for (unsigned i = 0; i < size; i++)
	{
		delete mSprites[i]; // Deletes all sprites associated with the hands.
	}
}
