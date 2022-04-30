#include "MusicSystem.h"

void MusicSystem::init(std::string filepath)
{
	if (!music.openFromFile(filepath))
	{
		std::cout << "ERROR: Music file not found";
	}
}

void MusicSystem::cleanup()
{
}

void MusicSystem::playMusic(float offset)
{

	stopMusic();
	
	music.setVolume(mVolume);

	music.setPlayingOffset(sf::seconds(offset/1000.0f));
	music.play();
}

void MusicSystem::pauseMusic()
{
	music.pause();
}

void MusicSystem::stopMusic()
{
	music.stop();
}

void MusicSystem::increaseVolume()
{
	mVolume += VOLUME_INCREMENT;

	if (mVolume > 100.0f)
	{
		mVolume = 100.0f;
	}
}

void MusicSystem::decreaseVolume()
{
	mVolume -= VOLUME_INCREMENT;

	if (mVolume < 0.0f)
	{
		mVolume = 0.0f;
	}
}
