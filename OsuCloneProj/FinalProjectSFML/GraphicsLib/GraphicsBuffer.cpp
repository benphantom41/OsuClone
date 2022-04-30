//SFML Implementation:

#include "GraphicsBuffer.h"
GraphicsBuffer::GraphicsBuffer()
{

}

GraphicsBuffer::GraphicsBuffer(string filename)
{
	mBitmap.loadFromFile(filename);
	mWidth = mBitmap.getSize().x;
	mHeight = mBitmap.getSize().y;
}

GraphicsBuffer::GraphicsBuffer(int width, int height, Color c)
{
	mWidth = width;
	mHeight = height;
	mBitmap.create(width, height);
}

GraphicsBuffer::~GraphicsBuffer()
{
	cleanUp();
}

GraphicsBuffer::GraphicsBuffer(sf::Texture texture)
{
	mBitmap = texture;
	mWidth = mBitmap.getSize().x;
	mHeight = mBitmap.getSize().y;
}

void GraphicsBuffer::cleanUp()
{
	
}

sf::Texture & GraphicsBuffer::getBuffer()
{
	return mBitmap;
}