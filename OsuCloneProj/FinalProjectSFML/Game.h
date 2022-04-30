#pragma once

#include "Trackable.h"
#include "System.h"
#include "UnitManager.h"
#include "GraphicsBufferManager.h"
#include <Timer.h>
#include "PerformanceTracker.h"
#include "EventListener.h"
#include "NoteManager.h"
#include "UIManager.h"
#include "Cat.h"
#include "CatHand.h"

class Unit;
class UnitManager;
class InputTranslator;
class NoteManager;
class UIManager;
class Cat;
class CatHand;
class ButtonManager;

using namespace std;

const string ASSET_PATH = "Assets\\";
const string FONT_PATH = "cour.ttf";
const string BACKGROUND_FILENAME = "background.png";

const string MEGALOVANIA_SONG_FILENAME = "MEGALOVANIA.ogg";
const string MEGALOVANIA_MAP_FILENAME = "Megalovania.txt";
const string MEGALOVANIA_BACKGROUND_FILENAME = "Megalovania_Background_Scaled.png";

const string SANDSTORM_SONG_FILENAME  = "Sandstorm.ogg";
const string SANDSTORM_MAP_FILENAME = "Sandstorm.txt";
const string SANDSTORM_BACKGROUND_FILENAME = "Sandstorm_Background_Scaled.png";

const string RUNNING_SONG_FILENAME = "RunningInThe90s.ogg";
const string RUNNING_MAP_FILENAME = "RunningInThe90s.txt";
const string RUNNING_BACKGROUND_FILENAME = "RunningInThe90s_Background_Scaled.png";

const string CURSOR_FILENAME = "cursor.png";

const int DISPLAY_WIDTH = 800;
const int DISPLAY_HEIGHT = 600;

const float MS_PER_FRAME = 16.7f;

const float LOAD_GAME_BUFFER = 3000.0f;

enum mCurrentScreenNum
{
	INVALID_SCREEN = -1,
	MAIN_MENU_SCREEN,
	OPTIONS_MENU_SCREEN,
	LANGUAGE_MENU_SCREEN,
	SONG_SELECT_SCREEN,
	LOAD_GAME_SCREEN,
	GAME_SCREEN,
	RESULTS_SCREEN,
	NUM_OF_SCREENS
};

class Game : public EventListener
{

public:

	static Game* getInstance() { return mpGameInstance; };

	static void initInstance() { mpGameInstance = new Game; };

	static void cleanupInstance() { delete mpGameInstance; mpGameInstance = NULL; };

	~Game();

	void init();

	void cleanup();

	void menuLoop();

	void gameLoop();

	void doLoop();

	bool goToResults();

	void drawCurrentScreen();

	System* getSystem() { return mpSystem; };

	GraphicsBufferManager* getGraphicsBufferManager() { return mpGraphicsBufferManager; };

	void saveGame();

	void loadGame();

	void handleEvent(const Event& theEvent);

	void hitNote();
	
	void missNote();

	void setMouse(int x, int y) { mMouseX = x; mMouseY = y;};

	int getMouseX() { return mMouseX; };

	int getMouseY() { return mMouseY; };

	enum ButtonNames
	{
		INVALID_BUTTON_NAME = -1,
		BUTTON_MENU_QUIT,
		BUTTON_MENU_RETURN,
		BUTTON_MAIN_MENU_START, //Sends you to the Level Select
		BUTTON_MAIN_MENU_LOAD, //Loads a Saved Game
		BUTTON_MAIN_MENU_OPTIONS, //Sends you to the Options Menu
		BUTTON_OPTIONS_VOLUME_UP,
		BUTTON_OPTIONS_VOLUME_DOWN,
		BUTTON_OPTIONS_LANGUAGE, //Sends you to the Language Select Menu
		BUTTON_LEVEL_SELECT_OPTION1,
		BUTTON_LEVEL_SELECT_OPTION2,
		BUTTON_LEVEL_SELECT_OPTION3,
		BUTTON_LANGUAGE_ENG,
		BUTTON_LANGUAGE_FRN,
		BUTTON_LANGUAGE_SPN,
		NUM_BUTTON_NAMES
	};

private:
	Game();

	static Game* mpGameInstance;
	System* mpSystem;
	UnitManager* mpUnitManager;
	GraphicsBufferManager* mpGraphicsBufferManager;
	
	bool mLoop = true;
	Timer mTimer;
	float mTimeScalar;
	
	bool mLoopAnimation = true;
	vector<Animation*> mBaseAnimations;
	bool mCanAnimate = true;
	InputTranslator* mpInputTranslator;
	NoteManager* mpNoteManager;
	
	int mSongSize = 0;
	int mMissednotesCounter = 0;

	UIManager* mpUIManager;
	UIManager* mpMenuUIManager;
	
	Cat* mpCat;
	CatHand* mpCatHand;
	bool mCatHandDown = false;
	Timer mCatTimer;

	int mCurrentScreen = MAIN_MENU_SCREEN;

	Sprite* mpBaseSprite;

	ButtonManager* mpButtonManager;
	Timer mButtonPressTimer;

	int mScore = 0;
	int mCombo = 1;
	int mGreatestCombo = 1;

	int mMouseX = 0;
	int mMouseY = 0;

	int mCurrentLanguage = 0;
	string mCurrentSong;
	string mCurrentMap;
	string mCurrentBackground = "Background";
};