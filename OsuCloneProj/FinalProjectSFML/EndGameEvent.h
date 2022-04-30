#pragma once
#include "Event.h"

class EndGameEvent : public Event
{
public:
	EndGameEvent() : Event(QUIT_EVENT) {};
	~EndGameEvent() {};
};

