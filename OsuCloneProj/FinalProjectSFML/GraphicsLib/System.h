//SFML Implementation:

#ifndef System_h
#define System_h

#include "Trackable.h"
#include "GraphicsSystem.h"
#include "InputSystem.h"
#include "MusicSystem.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;

class System : public Trackable
{

public:

	System();

	~System();

	void initSystem();

	void cleanUp();

	GraphicsSystem* getGraphicsSystem() { return mpGraphicsSystem; };
	InputSystem* getInputSystem() { return mpInputSystem; };
	MusicSystem* getMusicSystem() { return mpMusicSystem; };

private:

	GraphicsSystem * mpGraphicsSystem;
	InputSystem* mpInputSystem;
	MusicSystem* mpMusicSystem;
	
};

#endif 

