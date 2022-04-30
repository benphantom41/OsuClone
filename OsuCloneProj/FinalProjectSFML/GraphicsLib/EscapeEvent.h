#pragma once
#include "Event.h"

class EscapeEvent : public Event
{
public:
	EscapeEvent() : Event(ESC_KEY_PRESS) {};
	~EscapeEvent() {};
};
