#include "GraphicsBufferManager.h"

GraphicsBufferManager::GraphicsBufferManager()
{

}

GraphicsBufferManager::~GraphicsBufferManager()
{
	cleanup();
}

void GraphicsBufferManager::cleanup()
{
	map<BufferKey, GraphicsBuffer*>::iterator iter;

	for (iter = mMap.begin(); iter != mMap.end(); ++iter)
	{
		GraphicsBuffer* pGraphicsBuffer = iter->second;
		delete pGraphicsBuffer;
	}

	mMap.clear();
}

GraphicsBuffer * GraphicsBufferManager::createAndManageGraphicsBuffer(const BufferKey & key, string filename)
{
	GraphicsBuffer* pGraphicsBuffer = NULL;

	map<BufferKey, GraphicsBuffer*>::iterator iter = mMap.find(key);

	if (iter == mMap.end())
	{
		pGraphicsBuffer = new GraphicsBuffer(filename);
		mMap[key] = pGraphicsBuffer;
	}
	return pGraphicsBuffer;
}

void GraphicsBufferManager::deleteBuffer(const BufferKey & key)
{
	map<BufferKey, GraphicsBuffer*>::iterator iter = mMap.find(key);

	if (iter != mMap.end())
	{
		delete iter->second;
		mMap.erase(iter);
	}
}

void GraphicsBufferManager::deleteBuffer(GraphicsBuffer * pGraphicsBuffer)
{
	map<BufferKey, GraphicsBuffer*>::iterator iter;

	for (iter = mMap.begin(); iter != mMap.end(); ++iter)
	{
		if (pGraphicsBuffer == iter->second)
		{
			delete pGraphicsBuffer;
			mMap.erase(iter);
			return;
		}
	}
}

GraphicsBuffer * GraphicsBufferManager::getGraphicsBuffer(const BufferKey & key) const
{
	map<BufferKey, GraphicsBuffer*>::const_iterator iter = mMap.find(key);

	if (iter != mMap.end())
	{
		return iter->second;
	}
	else
	{
		return NULL;
	}
}
