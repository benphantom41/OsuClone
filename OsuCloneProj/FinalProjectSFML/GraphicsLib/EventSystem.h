#pragma once

#include "Trackable.h"
#include <map>

class Event;
class EventListener;
enum EventType;

using namespace std;

class EventSystem : public Trackable
{

public:
	EventSystem();
	~EventSystem();

	void fireEvent(const Event& theEvent);

	void addListener(EventType type, EventListener* pListener);

	void removeListener(EventType type, EventListener* pListener);

	void removeListenerFromAllEvents(EventListener* pListener);

	static void initInstance();

	static void cleanUpInstance();

	static EventSystem* getInstance();


private:

	static EventSystem* mpsInstance;

	multimap<EventType, EventListener*> mListenerMap;

	void dispatchAllEvents(const Event& theEvent);

};
