#pragma once
#include "Trackable.h"
#include "Note.h"

class Note;

const string APPROACHCIRCLE_FILENAME = "ApproachCircle.png";

class NoteManager : public Trackable
{
public:
	NoteManager();
	~NoteManager();

	void init();

	void draw();

	void update(float time);

	void createMap(string filename);

	void addNote(Note newNote);

	void removeNote();

	void cleanup();

	void newCombo();

	void checkCollision(int x, int y);

	unsigned getSize() { return mSize; };

	float getElapsedTime() { return mElapsedTime; };

	void setElapsedTime(float time) { mElapsedTime = time; };

	void resizeNoteVector(unsigned size);

	void addApproachCircle();

	void drawApproachCircles(float currentTime);

private:

	std::vector<Note> mNotes;
	std::vector<Note> mActiveNotes;
	std::vector<Sprite*> mApproachCircles;
	std::vector<Sprite*> mSprites;
	unsigned mSize = 0;
	int mNextNote = 0;
	float mElapsedTime = 0.0f;
	int mNoteBuffer;

};