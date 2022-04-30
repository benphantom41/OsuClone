#include "Animation.h"

Animation::Animation(vector<Sprite*> spriteList, float timing, bool shouldLoop)
{
	mAnimations = spriteList;
	mTiming = timing;
	mShouldAnimationLoop = shouldLoop;
	mCurrentSprite = 0;
}

Animation::~Animation()
{

	unsigned size = mAnimations.size();

	for(unsigned i = 0; i < size; i++)
	{
		mAnimations.pop_back();
	}
	
	mAnimations.clear();
	mAnimations.shrink_to_fit();
}

void Animation::cleanup()
{
	/*for (unsigned i = 0; i < mAnimations.size(); i++)
	{
		delete mAnimations[i];
	}*/
}

void Animation::addSprite(Sprite* sprite)
{
	mAnimations.push_back(sprite);
}

void Animation::update()
{
	mCurrentSprite++;

	if (mCurrentSprite >= mAnimations.size())
	{
		if (mShouldAnimationLoop)
		{
			mCurrentSprite = 0;
		}
		else
		{
			mCurrentSprite = mAnimations.size();
		}
	}
}


