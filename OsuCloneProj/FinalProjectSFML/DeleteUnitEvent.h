#pragma once
#include "Event.h"

class DeleteUnitEvent : public Event
{
public:
	DeleteUnitEvent(int x, int y) : Event(REMOVE_UNIT_EVENT)
	{
		mPosX = x;
		mPosY = y;
	}
	~DeleteUnitEvent() {};

	int getX() const { return mPosX; };
	int getY() const { return mPosY; };

private:
	int mPosX;
	int mPosY;
};
