#pragma once
#include "Event.h"

class ChangeScreenEvent : public Event
{
public:

	ChangeScreenEvent(int screenName) : Event(EventType::CHANGE_SCREEN_EVENT)
	{
		mScreen = screenName;
	}
	~ChangeScreenEvent() {};

	int getScreen() const { return mScreen; };

private:
	int mScreen;

};