//SFML Implementation:

#ifndef GraphicsSystems_h
#define GraphicsSystems_h

#include <Trackable.h>
#include "GraphicsBuffer.h"
#include "Sprite.h"
#include "Font.h"

#include<SFML/Window.hpp>
#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/Graphics/RenderTexture.hpp>
#include<SFML/Graphics/RenderTarget.hpp>
#include<SFML/System/Time.hpp>
#include<SFML/Graphics/Sprite.hpp>
#include<SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;

//class GraphicsBuffer;

class GraphicsSystem : public Trackable
{
public:

	friend class System;
	friend class InputSystem;

	//constructor and destructor
	GraphicsSystem();
	~GraphicsSystem();

	//initialize SFML
	int init();

	GraphicsBuffer * getBackBuffer() const { return mpBackBuffer; };
	void initializeDisplay(int width, int height); //builds display
	void cleanUp(); //cleans up memory leaks
	int getHeight(); //gets height of display
	int getWidth(); //gets width of display
	void flip(); //calls the flip fucntion

				 //draw functions
	void simpleDraw(Sprite * image, int x, int y);
	void simpleDraw(Sprite * image, int x, int y, float scale);
	void draw(GraphicsBuffer *target, float locX, float locY, float systemWidth, float systemHeight, float dX, float dY, float scaleFactor, int flags);
	void draw(GraphicsBuffer *target, Sprite * sprite, int x, int y, float scale);
	void drawButton(int width, int height, float x, float y, Color color);

	//write to text functions
	void writeText(Font * font, Color c, string text, float x, float y);
	void writeText(GraphicsBuffer *target, Font * font, Color c, string text, float x, float y);

	sf::RenderWindow *mDisplay;

	sf::RenderWindow* getWindow() { return mDisplay; };
private:
	GraphicsBuffer * mpBackBuffer;

	int mSystemHeight;
	int mSystemWidth;
	int mFlags = 0;
	float mScale;
	bool mIsInnited = false;
};
#endif