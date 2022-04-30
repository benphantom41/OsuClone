#include "NoteManager.h"
#include <fstream>

NoteManager::NoteManager()
{
}

NoteManager::~NoteManager()
{
	unsigned size = mSprites.size();
	for (unsigned i = 0; i < size; i++)
	{
		delete mSprites[i];
	}
	unsigned sizeCircles = mApproachCircles.size();
	for (unsigned i = 0; i < sizeCircles; i++)
	{
		delete mApproachCircles[i];
	}
}

void NoteManager::init()
{
	string name = "";

	for (int j = 1; j <= 2; j++)
	{
		for (int i = 1; i <= 4; i++)
		{
			name = to_string(j) + "Note" + to_string(i) + ".png";
			Game::getInstance()->getGraphicsBufferManager()->createAndManageGraphicsBuffer(name, ASSET_PATH + name);
			mSprites.push_back(new Sprite(Game::getInstance()->getGraphicsBufferManager()->getGraphicsBuffer(name), 0, 0, 50, 50));
		}
	}

	Game::getInstance()->getGraphicsBufferManager()->createAndManageGraphicsBuffer("ApproachCircle", ASSET_PATH + APPROACHCIRCLE_FILENAME);

}

void NoteManager::draw()
{
	if (mActiveNotes.size() > 0)
	{
		unsigned size = mActiveNotes.size(); 
		size--;

		for (int i = size; i >= 0; i--)
		{
			mActiveNotes[i].draw();
		}
	}

	if (mApproachCircles.size() > 0)
	{
		drawApproachCircles(mElapsedTime);
	}
}

void NoteManager::update(float time)
{
	mElapsedTime += time;

	if (mNotes.size() != 0 && float(mNotes[0].getSpawnTime() - mNoteBuffer) <= mElapsedTime)
	{
		mActiveNotes.push_back(mNotes[0]);
		addApproachCircle();

		mNotes.erase(mNotes.begin());
		mNotes.shrink_to_fit();
	}

	if (mActiveNotes.size() != 0 && float(mActiveNotes[0].getSpawnTime() + (mNoteBuffer / 2)) <= mElapsedTime)
	{
		removeNote();
		Game::getInstance()->missNote();
	}

}

void NoteManager::addNote(Note newNote)
{
	mNotes.push_back(newNote);
	mSize++;
}

void NoteManager::removeNote()
{
	mActiveNotes.erase(mActiveNotes.begin());

	delete mApproachCircles[0];
	mApproachCircles.erase(mApproachCircles.begin());

	mActiveNotes.shrink_to_fit();
	mApproachCircles.shrink_to_fit();

	mSize--;
}

void NoteManager::cleanup()
{
	unsigned size = mNotes.size();

	for (unsigned i = 0; i < size; i++)
	{
		mNotes[i].cleanup();
	}
}

void NoteManager::createMap(string filename)
{
	int x;
	int y;
	float time;

	ifstream input;
	input.open(filename);

	input >> mNoteBuffer;

	while (!input.eof())
	{
		input >> x;
		input >> y;
		input >> time;

		addNote(Note(x, y, time, mSprites[mNextNote]));

		mNextNote++;

		if (static_cast<unsigned>(mNextNote) >= mSprites.size())
		{
			mNextNote = 0;
		}
	}
}

void NoteManager::newCombo()
{
	if (mNextNote < 4)
	{
		mNextNote = 4;
	}
	else
	{
		mNextNote = 0;
	}

	if (static_cast<unsigned>(mNextNote) >= mSprites.size())
	{
		mNextNote -= 8;
	}
}

void NoteManager::checkCollision(int x, int y)
{
	if (mActiveNotes.size() != 0)
	{

		int noteX = mActiveNotes[0].getX();
		int noteY = mActiveNotes[0].getY();

		if (x > noteX - (NOTE_WIDTH / 2) && x < noteX + (NOTE_WIDTH / 2))
		{
			if (y > noteY - (NOTE_HEIGHT / 2) && y < noteY + (NOTE_HEIGHT / 2))
			{
				removeNote();
				Game::getInstance()->hitNote();
			}
		}
	}
}

void NoteManager::resizeNoteVector(unsigned size)
{
	while (size < mNotes.size())
	{
		mNotes.erase(mNotes.begin());
		mNotes.shrink_to_fit();
	}
}

void NoteManager::addApproachCircle()
{
	mApproachCircles.push_back(new Sprite(Game::getInstance()->getGraphicsBufferManager()->getGraphicsBuffer("ApproachCircle"), 0, 0, 100, 100));
}

void NoteManager::drawApproachCircles(float currentTime)
{
	float timeTillSpawn = 0.0f;
	float scale = 0.5;

	for (unsigned i = 0; i < mApproachCircles.size(); i++)
	{
		if (currentTime < mActiveNotes[i].getSpawnTime())
		{
			timeTillSpawn = mActiveNotes[i].getSpawnTime() - currentTime;

			scale = (timeTillSpawn / mNoteBuffer) * 2.0f;

			if (scale < 0.5f)
			{
				scale = 0.5f;
			}
		}

		Game::getInstance()->getSystem()->getGraphicsSystem()->simpleDraw(mApproachCircles[i], mActiveNotes[i].getX() - (50 * scale), mActiveNotes[i].getY() - (50 * scale), scale);
	}
}