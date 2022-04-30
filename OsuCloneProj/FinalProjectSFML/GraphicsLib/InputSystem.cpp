//SFML Implementation:

#include "InputSystem.h"

InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
}

void InputSystem::update(sf::RenderWindow* window)
{
	mMousePosition = sf::Mouse::getPosition(*window);

	if (mMousePosition.x != mPrevMousePosition.x && mMousePosition.y != mPrevMousePosition.y)
	{
		mPrevMousePosition = sf::Mouse::getPosition(*window);
		EventSystem::getInstance()->fireEvent(MouseMoved(mMousePosition.x, mMousePosition.y));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //Left Mouse Key pressed, functionally same as Z Key pressed.
	{
		EventSystem::getInstance()->fireEvent(LeftMouse(mMousePosition.x, mMousePosition.y));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) //Right Mouse Key pressed, functionally same as X Key pressed.
	{
		EventSystem::getInstance()->fireEvent(RightMouse(mMousePosition.x, mMousePosition.y));
	}

	for (unsigned i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		mPreviousKeyboardState[i] = mCurrentKeyboardState[i];

		mCurrentKeyboardState[i] = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i);
	}

	if (KeyPressed(sf::Keyboard::Z)) //Z Key pressed, functionally same as Left Click
	{
		EventSystem::getInstance()->fireEvent(ZKeyPress(mMousePosition.x, mMousePosition.y));
	}

	if (KeyPressed(sf::Keyboard::X)) //X Key pressed, functionally same as Right Click
	{
		EventSystem::getInstance()->fireEvent(XKeyPress(mMousePosition.x, mMousePosition.y));
	}

	if (KeyPressed(sf::Keyboard::Escape))
	{
		EventSystem::getInstance()->fireEvent(EscapeEvent());
	}

	if (KeyPressed(sf::Keyboard::Space))
	{
		EventSystem::getInstance()->fireEvent(SpaceEvent());
	}
}		

void InputSystem::init(sf::RenderWindow* window)
{
	mPrevMousePosition = sf::Mouse::getPosition(*window);

	memset(mCurrentKeyboardState, false, sizeof(mCurrentKeyboardState));
	memset(mPreviousKeyboardState, false, sizeof(mPreviousKeyboardState));
}

void InputSystem::cleanup()
{
}

bool InputSystem::KeyPressed(sf::Keyboard::Key key)
{
	return (mCurrentKeyboardState[key] && !mPreviousKeyboardState[key]);
}