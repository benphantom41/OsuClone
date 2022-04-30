#ifndef Sprite_h
#define Sprite_h
#include "GraphicsBuffer.h"
#include <Trackable.h>


using namespace std;

class GraphicsBuffer;

class Sprite : public Trackable
{
public:
	Sprite();
	Sprite(GraphicsBuffer * bitmap, int x, int y, int height, int width);
	~Sprite();
	GraphicsBuffer *pGetBuffer() { return pGraphicsBuffer; };
	int getWidthSprite();
	int getHeightSprite();
	int getSourceX();
	int getSourceY();
private:

	GraphicsBuffer * pGraphicsBuffer;
	int mSourceX; //sourceLocX
	int mSourceY; //sourceLocY
	int mWidth; //width of sprite
	int mHeight; //hieght of sprite
};
#endif