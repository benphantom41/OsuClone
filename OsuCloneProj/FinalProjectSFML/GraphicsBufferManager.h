#ifndef GraphicsBufferManager_h
#define GraphicsBufferManager_h

#include "Trackable.h"
#include "GraphicsBuffer.h"
#include <string>
#include <map>

class GraphicsBuffer;

typedef string BufferKey;

using namespace std;

class GraphicsBufferManager : public Trackable
{

public:
	GraphicsBufferManager();

	~GraphicsBufferManager();

	void cleanup();

	GraphicsBuffer* createAndManageGraphicsBuffer(const BufferKey& key, string filename);
	
	void deleteBuffer(const BufferKey& key);

	void deleteBuffer(GraphicsBuffer* pGraphicsBuffer);

	GraphicsBuffer* getGraphicsBuffer(const BufferKey& key) const;


private:

	map<BufferKey, GraphicsBuffer*> mMap;

};


#endif
