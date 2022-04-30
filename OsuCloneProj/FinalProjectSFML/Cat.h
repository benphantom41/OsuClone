#pragma once
#include "Trackable.h"
#include "Game.h"

class Cat : public Trackable
{

public:
	Cat() {};
	~Cat() {};

	void swapSprite(int x, int y);
	
	void addSprite(Sprite* newSprite);

	void draw();

	void cleanup();

private:

	vector<Sprite*> mSprites;
	int mCurrentSprite = 0;

};