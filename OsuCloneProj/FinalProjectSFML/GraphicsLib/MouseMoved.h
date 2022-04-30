#pragma once
#include "Event.h"

class MouseMoved : public Event
{

public:

	MouseMoved(int locX, int locY) : Event(EventType::MOUSE_MOVED_EVENT)
	{
		mPosX = locX;
		mPosY = locY;
	}
	~MouseMoved() {};

	int getX() const { return mPosX; };
	int getY() const { return mPosY; };

private:
	int mPosX;
	int mPosY;

};
