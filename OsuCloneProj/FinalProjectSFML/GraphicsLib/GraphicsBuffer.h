//SFML Implementation:

#ifndef GraphicsBuffer_h
#define GraphicsBuffer_h

#include <Trackable.h>
#include <SFML/Graphics.hpp>

#include "Color.h"
using namespace std;

//This class stores a bitmap for the Graphics System to draw

class GraphicsBuffer :public Trackable
{


public:
	friend class GraphicsSystem;
	friend class Sprite;

	//constructors and deconstructors
	GraphicsBuffer();
	GraphicsBuffer(string filename);
	GraphicsBuffer(int width, int height, Color c);
	~GraphicsBuffer();
	GraphicsBuffer(sf::Texture texture);

	//accessors
	int getWidth() { return mWidth; };
	int getHeight() { return mHeight;  };

	//clean up function
	void cleanUp();
private:
	sf::Texture mBitmap;

	sf::Texture& getBuffer();

	int mWidth;
	int mHeight;

	//invalidate copy constructor and assignment operator
	GraphicsBuffer(GraphicsBuffer&);

};
#endif