#pragma once
#include "Event.h"

class MoveCursorEvent : public Event
{

public:

	MoveCursorEvent(int locX, int locY) : Event(EventType::MOVE_CURSOR_EVENT)
	{
		mPosX = locX;
		mPosY = locY;
	}
	~MoveCursorEvent() {};

	int getX() const { return mPosX; };
	int getY() const { return mPosY; };

private:
	int mPosX;
	int mPosY;

};
