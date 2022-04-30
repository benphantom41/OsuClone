#pragma once
#include "Event.h"

class ZPressCircleEvent : public Event
{
public:

	ZPressCircleEvent(int locX, int locY) : Event(EventType::Z_PRESS_CIRCLE_EVENT)
	{
		mPosX = locX;
		mPosY = locY;
	}
	~ZPressCircleEvent() {};

	int getX() const { return mPosX; };
	int getY() const { return mPosY; };

private:
	int mPosX;
	int mPosY;
};