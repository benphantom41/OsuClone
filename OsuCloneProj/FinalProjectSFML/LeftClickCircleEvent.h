#pragma once
#include "Event.h"

class LeftClickCircleEvent : public Event
{
public:

	LeftClickCircleEvent(int locX, int locY) : Event(EventType::LEFT_CLICK_CIRCLE_EVENT)
	{
		mPosX = locX;
		mPosY = locY;
	}
	~LeftClickCircleEvent() {};

	int getX() const { return mPosX; };
	int getY() const { return mPosY; };

private:
	int mPosX;
	int mPosY;
};