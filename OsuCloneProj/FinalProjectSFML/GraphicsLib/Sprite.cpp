#include "Sprite.h"
Sprite::Sprite()
{
}

Sprite::Sprite(GraphicsBuffer * bitmap, int x, int y, int height, int width)
{
	pGraphicsBuffer = bitmap;
	mSourceX = x;
	mSourceY = y;
	mHeight = height;
	mWidth = width;
}

Sprite::~Sprite()
{
}


int Sprite::getWidthSprite()
{
	return mWidth;
}

int Sprite::getHeightSprite()
{
	return mHeight;
}

int Sprite::getSourceX()
{
	return mSourceX;
}

int Sprite::getSourceY()
{
	return mSourceY;
}

