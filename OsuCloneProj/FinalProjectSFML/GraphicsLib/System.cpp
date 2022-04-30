//SFML Implementation

#include "System.h"

System::System()
{

}

System::~System()
{
	delete mpGraphicsSystem;
	mpGraphicsSystem = NULL;

	delete mpInputSystem;
	mpInputSystem = NULL;

	delete mpMusicSystem;
	mpMusicSystem = NULL;

	cleanUp();
}

void System::initSystem()
{
	mpGraphicsSystem = new GraphicsSystem;
	mpGraphicsSystem->init();

	mpInputSystem = new InputSystem;

	mpMusicSystem = new MusicSystem;
}

void System::cleanUp()
{

}