#pragma once
#include "Event.h"

class AddUnitEvent : public Event
{
public:
	AddUnitEvent(int x, int y) : Event(ADD_UNIT_EVENT)
	{
		mPosX = x;
		mPosY = y;
	}
	~AddUnitEvent() {};

	int getX() const { return mPosX; };
	int getY() const { return mPosY; };

private:
	int mPosX;
	int mPosY;
};
