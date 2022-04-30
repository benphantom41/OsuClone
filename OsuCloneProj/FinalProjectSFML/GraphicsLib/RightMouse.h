#pragma once
#include "Event.h"

class RightMouse : public Event
{
public:

	RightMouse(int locX, int locY) : Event(EventType::MOUSE_CLICK_2)
	{
		mPosX = locX;
		mPosY = locY;
	}
	~RightMouse() {};

	int getX() const { return mPosX; };
	int getY() const { return mPosY; };

private:
	int mPosX;
	int mPosY;
};