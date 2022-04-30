#include "Note.h"

Note::Note(int x, int y, float time, Sprite* sprite)
{
	mXLoc = x;
	mYLoc = y;
	mTimeTillSpawn = time;
	mSprite = sprite;
}

void Note::draw()
{
	Game::getInstance()->getSystem()->getGraphicsSystem()->simpleDraw(mSprite, mXLoc - 25, mYLoc - 25);
}

void Note::update(float time)
{

}

void Note::cleanup()
{
	mSprite = NULL;
}
