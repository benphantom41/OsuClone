#pragma once

#include "Trackable.h"
#include <string>

using namespace std;

enum EventType
{
	INVALID_EVENT = -1,
	MOUSE_MOVED_EVENT, //Mouse Moved Event
	MOVE_CURSOR_EVENT, //Cursor Moved Event
	MOUSE_CLICK_1, //Mouse clicks and Z/X presses
	Z_KEY_PRESS,
	LEFT_CLICK_CIRCLE_EVENT,
	Z_PRESS_CIRCLE_EVENT,
	MOUSE_CLICK_2,
	X_KEY_PRESS,
	RIGHT_CLICK_CIRCLE_EVENT,
	X_PRESS_CIRCLE_EVENT,
	SPACE_KEY_PRESS, //Other button press events
	ESC_KEY_PRESS,
	ADD_UNIT_EVENT, //Add unit / Remove unit events
	REMOVE_UNIT_EVENT,
	PAUSE_UNIT_EVENT,
	QUIT_EVENT, //Quit the game event
	CHANGE_SCREEN_EVENT, //Menu events
	VOLUME_UP_EVENT,
	SWITCH_LANGUAGE_EVENT,
	SELECT_SONG_EVENT,
	NUM_OF_EVENTS
};

class Event : public Trackable
{
public:

	Event(EventType type);
	virtual ~Event();

	EventType getType() const { return mType; };
	const string& getEventName() const;

private:
	EventType mType;

};


