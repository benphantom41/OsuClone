#include "Event.h"

Event::Event(EventType type) : mType(type)
{

}

Event::~Event()
{

}

const string& Event::getEventName() const
{
	if (mType > INVALID_EVENT && mType < NUM_OF_EVENTS)
	{
		 
	}
	else
	{
		
	}

	static const string nullString;
	return nullString;
}
