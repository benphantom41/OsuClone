#pragma once
#include "Event.h"

class SpaceEvent : public Event
{
public:
	SpaceEvent() : Event(SPACE_KEY_PRESS) {};
	~SpaceEvent() {};
};
