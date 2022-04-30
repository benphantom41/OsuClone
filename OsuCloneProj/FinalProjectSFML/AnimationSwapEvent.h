#pragma once
#include "Event.h"

class AnimationSwapEvent : public Event
{
public:
	AnimationSwapEvent() : Event(PAUSE_UNIT_EVENT) {};
	~AnimationSwapEvent() {};
};
