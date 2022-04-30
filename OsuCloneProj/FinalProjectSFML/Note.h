#pragma once
#include "Trackable.h"
#include "Game.h"

const int NOTE_WIDTH = 50;
const int NOTE_HEIGHT = 50;

class Note : public Trackable
{
public:
	Note(int x, int y, float time, Sprite* sprite);
	~Note() {};

	void draw();

	void update(float time);

	void cleanup();

	int getX() { return mXLoc; };

	int getY() { return mYLoc; };

	float getSpawnTime() { return mTimeTillSpawn; };

private:
	int mXLoc;
	int mYLoc;
	float mTimeTillSpawn;
	Sprite* mSprite;

};
