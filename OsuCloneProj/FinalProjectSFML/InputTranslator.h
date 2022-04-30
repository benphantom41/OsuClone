#pragma once

#include "Trackable.h"
#include "EventListener.h"
#include "MoveCursorEvent.h"
#include "AddUnitEvent.h"
#include "DeleteUnitEvent.h"
#include "EndGameEvent.h"
#include "AnimationSwapEvent.h"
#include "LeftClickCircleEvent.h"
#include "RightClickCircleEvent.h"
#include "ZPressCircleEvent.h"
#include "XPressCircleEvent.h"

class EventSystem;

class InputTranslator : public EventListener
{

public:
	InputTranslator();
	~InputTranslator();


	void init();

	void cleanup();

	void handleEvent(const Event& theEvent);

private:

};
