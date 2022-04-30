
#include <MemoryTracker.h>
#include "Game.h"
#include "EventSystem.h"

using namespace std;

int main()
{
	EventSystem::initInstance();

	Game::initInstance();
	Game* pGame = Game::getInstance();

	pGame->init();

	pGame->doLoop();

	delete pGame;

	EventSystem::cleanUpInstance();

	MemoryTracker::getInstance()->reportAllocations(cout);
	system("pause");

	return 0;
}

/*
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}*/