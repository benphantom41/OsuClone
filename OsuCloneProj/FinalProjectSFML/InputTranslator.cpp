#include "InputTranslator.h"
#include "EventSystem.h"
#include "MouseMoved.h"
#include "LeftMouse.h"
#include "RightMouse.h"
#include "ZKeyPress.h"
#include "XKeyPress.h"


InputTranslator::InputTranslator()
{
}

InputTranslator::~InputTranslator()
{

}

void InputTranslator::init()
{
	EventSystem::getInstance()->addListener(MOUSE_MOVED_EVENT, this);
	EventSystem::getInstance()->addListener(MOUSE_CLICK_1, this);
	EventSystem::getInstance()->addListener(MOUSE_CLICK_2, this);
	EventSystem::getInstance()->addListener(Z_KEY_PRESS, this);
	EventSystem::getInstance()->addListener(X_KEY_PRESS, this);
	EventSystem::getInstance()->addListener(ESC_KEY_PRESS, this);
	EventSystem::getInstance()->addListener(SPACE_KEY_PRESS, this);
}

void InputTranslator::cleanup()
{
}

void InputTranslator::handleEvent(const Event& theEvent)
{
	//cout << "\t" << theEvent.getEventName() << "Recieved";

	if (theEvent.getType() == MOUSE_MOVED_EVENT) //Mouse Position recieved
	{
		const MouseMoved& mouseMoved = static_cast<const MouseMoved&>(theEvent);
		EventSystem::getInstance()->fireEvent(MoveCursorEvent(mouseMoved.getX(), mouseMoved.getY()));
	}

	if (theEvent.getType() == MOUSE_CLICK_1) //Left Click Recieved
	{
		const LeftMouse& leftMouse = static_cast<const LeftMouse&>(theEvent);
		EventSystem::getInstance()->fireEvent(LeftClickCircleEvent(leftMouse.getX(), leftMouse.getY()));
	}

	if (theEvent.getType() == Z_KEY_PRESS) //Z Key Recieved
	{
		const ZKeyPress& zKey = static_cast<const ZKeyPress&>(theEvent);
		EventSystem::getInstance()->fireEvent(ZPressCircleEvent(zKey.getX(), zKey.getY()));
	}

	if (theEvent.getType() == MOUSE_CLICK_2) //Right Click Recieved
	{
		const RightMouse& rightMouse = static_cast<const RightMouse&>(theEvent);
		EventSystem::getInstance()->fireEvent(RightClickCircleEvent(rightMouse.getX(), rightMouse.getY()));
	}

	if (theEvent.getType() == X_KEY_PRESS) //X Key Recieved
	{
		const XKeyPress& xKey = static_cast<const XKeyPress&>(theEvent);
		EventSystem::getInstance()->fireEvent(XPressCircleEvent(xKey.getX(), xKey.getY()));
	}

	if (theEvent.getType() == ESC_KEY_PRESS) //Escape Key Recieved
	{
		EventSystem::getInstance()->fireEvent(EndGameEvent());
	}

	if (theEvent.getType() == SPACE_KEY_PRESS) //Space Key Recieved
	{
		EventSystem::getInstance()->fireEvent(AnimationSwapEvent());
	}
	
}
