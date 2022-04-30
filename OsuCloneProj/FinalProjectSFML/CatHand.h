#pragma once
#include "Trackable.h"
#include "Game.h"

class CatHand : public Trackable
{

public:
	CatHand() {};
	~CatHand() {};

	void swapSprite();

	void addSprite(Sprite* newSprite);

	void draw();

	void cleanup();

	int getCurrentSprite() { return mCurrentSprite; }

private:

	vector<Sprite*> mSprites;
	int mCurrentSprite = 0; //Note: '0' is KeyTapHand1, which is the "Z" key pressed.
							//		'1' is KeyTapHand2, which is the "X" key pressed.

};