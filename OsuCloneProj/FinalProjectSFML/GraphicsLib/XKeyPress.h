#pragma once
#include "Event.h"

class XKeyPress : public Event
{

public:

	XKeyPress(int locX, int locY) : Event(EventType::X_KEY_PRESS)
	{
		mPosX = locX;
		mPosY = locY;
	}
	~XKeyPress() {};

	int getX() const { return mPosX; };
	int getY() const { return mPosY; };

private:
	int mPosX;
	int mPosY;

};
