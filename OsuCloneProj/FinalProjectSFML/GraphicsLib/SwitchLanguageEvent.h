#pragma once
#include "Event.h"

class SwitchLanguageEvent : public Event
{
public:

	SwitchLanguageEvent(int language) : Event(EventType::SWITCH_LANGUAGE_EVENT)
	{
		mLanguageID = language;
	}
	~SwitchLanguageEvent() {};

	int getLanguage() const { return mLanguageID; };

private:
	int mLanguageID;

};