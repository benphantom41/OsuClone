#pragma once
#include "Event.h"

class VolumeUpEvent : public Event
{
public:

	VolumeUpEvent(bool up) : Event(EventType::VOLUME_UP_EVENT)
	{
		mVolUp = up;
	}
	~VolumeUpEvent() {};

	bool getUpOrDown() const { return mVolUp; };

private:
	int mVolUp;

};