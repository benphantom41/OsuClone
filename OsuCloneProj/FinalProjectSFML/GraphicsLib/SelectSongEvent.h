#pragma once
#include "Event.h"

class SelectSongEvent : public Event
{
public:

	SelectSongEvent(int song) : Event(EventType::SELECT_SONG_EVENT)
	{
		mSongID = song;
	}
	~SelectSongEvent() {};

	int getSong() const { return mSongID; };

private:
	int mSongID;

};