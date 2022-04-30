#pragma once
#include "Event.h"

class LeftMouse : public Event
{
public:

	LeftMouse(int locX, int locY) : Event(EventType::MOUSE_CLICK_1)
	{
		mPosX = locX;
		mPosY = locY;
	}
	~LeftMouse() {};

	int getX() const { return mPosX; };
	int getY() const { return mPosY; };

private:
	int mPosX;
	int mPosY;
};
