#include "Unit.h"


Unit::Unit(vector<Animation*> animation, int locX, int locY)
{
	mpCurrentAnimation = animation;
	mCurrentAnimation = 0;
	mLocX = locX;
	mLocY = locY;
}

Unit::~Unit()
{
	mpCurrentAnimation.clear();
	mpCurrentAnimation.shrink_to_fit();
}

void Unit::cleanup()
{
	for (unsigned i = 0; i < mpCurrentAnimation.size(); i++)
	{
		delete mpCurrentAnimation[i];
	}
	mpCurrentAnimation.shrink_to_fit();
}

void Unit::update(float time)
{
	mRemainingTime -= time;

	if (mRemainingTime <= 0)
	{
		mpCurrentAnimation[mCurrentAnimation]->update();
		mRemainingTime = mpCurrentAnimation[mCurrentAnimation]->getTiming();
	}
}

void Unit::draw()
{
	Game::getInstance()->getSystem()->getGraphicsSystem()->simpleDraw(getAnimation()->getCurrentSprite(), mLocX, mLocY);
}

void Unit::switchAnimation()
{
	mCurrentAnimation++;

	if (static_cast<unsigned>(mCurrentAnimation) >= mpCurrentAnimation.size())
	{
		mCurrentAnimation = 0;
	}
}
