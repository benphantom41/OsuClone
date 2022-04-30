#pragma once
#include "Event.h"

class XPressCircleEvent : public Event
{
public:

	XPressCircleEvent(int locX, int locY) : Event(EventType::X_PRESS_CIRCLE_EVENT)
	{
		mPosX = locX;
		mPosY = locY;
	}
	~XPressCircleEvent() {};

	int getX() const { return mPosX; };
	int getY() const { return mPosY; };

private:
	int mPosX;
	int mPosY;
};