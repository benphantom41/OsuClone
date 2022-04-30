#ifndef Animation_h
#define Animation_h

#include "Trackable.h"
#include "Sprite.h"
#include <vector>


using namespace std;

class Animation : public Trackable
{

public:

	Animation(vector<Sprite*> spriteList, float timing, bool shouldLoop);

	~Animation();

	void cleanup();

	Sprite* getCurrentSprite() { return mAnimations[mCurrentSprite]; }

	void addSprite(Sprite* sprite);

	void setTiming(float timing) { mTiming = timing; }

	float getTiming() { return mTiming; }

	void update();

private:
	
	vector<Sprite*> mAnimations;
	float mTiming;
	int mCurrentSprite;
	bool mShouldAnimationLoop;

};
#endif
