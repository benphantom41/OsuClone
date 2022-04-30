#pragma once
#include "Event.h"

class ZKeyPress : public Event
{
public:

	ZKeyPress(int locX, int locY) : Event(EventType::Z_KEY_PRESS)
	{
		mPosX = locX;
		mPosY = locY;
	}
	~ZKeyPress() {};

	int getX() const { return mPosX; };
	int getY() const { return mPosY; };

private:
	int mPosX;
	int mPosY;

};
