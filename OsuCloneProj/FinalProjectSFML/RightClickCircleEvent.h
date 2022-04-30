#pragma once
#include "Event.h"

class RightClickCircleEvent : public Event
{
public:

	RightClickCircleEvent(int locX, int locY) : Event(EventType::RIGHT_CLICK_CIRCLE_EVENT)
	{
		mPosX = locX;
		mPosY = locY;
	}
	~RightClickCircleEvent() {};

	int getX() const { return mPosX; };
	int getY() const { return mPosY; };

private:
	int mPosX;
	int mPosY;
};