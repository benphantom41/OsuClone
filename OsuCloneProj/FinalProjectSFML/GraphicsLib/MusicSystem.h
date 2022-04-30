#pragma once

#include "Trackable.h"
#include <SFML\Audio.hpp>

const float VOLUME_INCREMENT = 10.0f;

class MusicSystem : public Trackable
{
public:

	enum Status
	{
		INVALID_STATUS = -1,
		STOPPED = sf::SoundSource::Status::Stopped,
		PAUSED = sf::SoundSource::Status::Paused,
		PLAYING = sf::SoundSource::Status::Playing,
		NUM_OF_STATUS
	};

	MusicSystem() {};
	~MusicSystem() { cleanup(); };

	void init(std::string filepath); //Pass in a filepath with a song to play.

	void cleanup();

	void playMusic(float offset);
	
	void pauseMusic();

	void stopMusic();

	void increaseVolume();

	void decreaseVolume();
	
	float getVolume() { return mVolume; };

	void setVolume(float newVolume) { mVolume = newVolume; };

	sf::SoundSource::Status getStatus() { return music.getStatus(); };

private:
	sf::Music music;
	float mVolume = 50;
};
