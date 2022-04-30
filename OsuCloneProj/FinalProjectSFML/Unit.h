#ifndef Unit_h
#define Unit_h

#include "Trackable.h"
#include "Animation.h"
#include "Game.h"


using namespace std;

class Unit : public Trackable
{

public:

	Unit(vector<Animation*> animation, int locX, int locY);

	~Unit();

	void cleanup();

	void update(float time); //Updates the state of the Unit

	void draw(); //Draws the Unit

	Animation* getAnimation() { return mpCurrentAnimation[mCurrentAnimation]; }

	void switchAnimation(); //Switches to a different animation

	void setPos(int posX, int posY) { mLocX = posX; mLocY = posY; }

	int getLocX() { return mLocX; }

	int getLocY() { return mLocY; }


private:

	int mLocX;
	int mLocY;
	vector<Animation*> mpCurrentAnimation;
	int mCurrentAnimation;
	float mRemainingTime;

};
#endif