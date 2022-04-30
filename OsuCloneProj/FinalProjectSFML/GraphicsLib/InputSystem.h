//SFML Implementation:

#pragma once

#include "Trackable.h"
#include "GraphicsSystem.h"
#include "EventSystem.h"
#include "MouseMoved.h"
#include "ZKeyPress.h"
#include "XKeyPress.h"
#include "LeftMouse.h"
#include "RightMouse.h"
#include "EscapeEvent.h"
#include "SpaceEvent.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

class InputSystem : public Trackable
{
public:
	InputSystem();
	~InputSystem();

	void update(sf::RenderWindow* window);

	void init(sf::RenderWindow* window);

	void cleanup();

	bool KeyPressed(sf::Keyboard::Key key);

private:
	sf::Vector2i mMousePosition;
	sf::Vector2i mPrevMousePosition;

	bool mCurrentKeyboardState[sf::Keyboard::KeyCount];
	bool mPreviousKeyboardState[sf::Keyboard::KeyCount];
};