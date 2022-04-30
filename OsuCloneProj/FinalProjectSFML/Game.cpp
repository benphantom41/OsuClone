#include "Game.h"
#include "Unit.h"
#include "InputSystem.h"
#include "InputTranslator.h"
#include "ButtonManager.h"
#include <fstream>

Game* Game::mpGameInstance = NULL;

void Game::saveGame()
{
	ofstream save;
	save.open("Save.txt");

	save << mCurrentSong << "\n";
	save << mCurrentMap << "\n";
	save << mCurrentBackground << "\n";
	save << mpNoteManager->getElapsedTime() << "\n";
	save << mpNoteManager->getSize() << "\n";
	save << mScore << "\n";
	save << mCombo << "\n";
	save << mCurrentLanguage << "\n";
	save << mpSystem->getMusicSystem()->getVolume();

	save.close();
	
}

void Game::loadGame()
{
	ifstream save;
	save.open("Save.txt");
	unsigned size;
	float time;
	float newVolume;

	save >> mCurrentSong;
	save >> mCurrentMap;
	save >> mCurrentBackground;
	save >> time;
	save >> size;
	save >> mScore;
	save >> mCombo;
	save >> mCurrentLanguage;
	save >> newVolume;
	mpSystem->getMusicSystem()->setVolume(newVolume);

	mpNoteManager->resizeNoteVector(size);
	mpNoteManager->setElapsedTime(time - LOAD_GAME_BUFFER);

	save.close();
	mpSystem->getMusicSystem()->init(ASSET_PATH + mCurrentSong);
	mpNoteManager->createMap(mCurrentMap);
	mCurrentScreen = GAME_SCREEN;
}

void Game::handleEvent(const Event & theEvent)
{
	if (theEvent.getType() == MOVE_CURSOR_EVENT)
	{
		const MoveCursorEvent& movedMouse = static_cast<const MoveCursorEvent&>(theEvent);
		setMouse(movedMouse.getX(), movedMouse.getY());
	}

	if (theEvent.getType() == LEFT_CLICK_CIRCLE_EVENT)
	{
		const LeftClickCircleEvent& leftMouse = static_cast<const LeftClickCircleEvent&>(theEvent);
		if (mCurrentScreen != GAME_SCREEN)
		{
			if (mButtonPressTimer.getElapsedTime() >= 500) //Buttons may only be pressed every .5 seconds
			{
				//The manager sees if any buttons on the current screen have been pressed
				mpButtonManager->clickButton(mCurrentScreen, leftMouse.getX(), leftMouse.getY());
			}	
		}
		mCatHandDown = false;
		if(mpNoteManager->getSize() > 0)
		{
			
			mpNoteManager->checkCollision(leftMouse.getX(), leftMouse.getY());
		}
	}
	else if (theEvent.getType() == Z_PRESS_CIRCLE_EVENT)
	{
		mCatHandDown = true;
		mCatTimer.start();
		if (mpCatHand->getCurrentSprite() == 1) // If the current sprite is at the "X" position, then...
		{
			mpCatHand->swapSprite(); // Switch to the "Z" sprite.
		}
		if (mpNoteManager->getSize() > 0)
		{
			const ZPressCircleEvent& zPress = static_cast<const ZPressCircleEvent&>(theEvent);
			mpNoteManager->checkCollision(zPress.getX(), zPress.getY());
		}
	}
	else if (theEvent.getType() == RIGHT_CLICK_CIRCLE_EVENT)
	{
		mCatHandDown = false;
		if (mpNoteManager->getSize() > 0)
		{
			const RightClickCircleEvent& rightMouse = static_cast<const RightClickCircleEvent&>(theEvent);
			mpNoteManager->checkCollision(rightMouse.getX(), rightMouse.getY());
		}
	}
	else if (theEvent.getType() == X_PRESS_CIRCLE_EVENT)
	{
		mCatHandDown = true;
		mCatTimer.start();
		if (mpCatHand->getCurrentSprite() == 0) // If the current sprite is at the "Z" position, then...
		{
			mpCatHand->swapSprite(); //Switch to the "X" sprite.
		}
		if (mpNoteManager->getSize() > 0)
		{
			const XPressCircleEvent& xPress = static_cast<const XPressCircleEvent&>(theEvent);
			mpNoteManager->checkCollision(xPress.getX(), xPress.getY());
		}
	}
	else if (theEvent.getType() == CHANGE_SCREEN_EVENT)
	{
		const ChangeScreenEvent& change = static_cast<const ChangeScreenEvent&>(theEvent);
		mCurrentScreen = change.getScreen();
		mButtonPressTimer.start();
	}
	else if (theEvent.getType() == VOLUME_UP_EVENT)
	{
		if (mButtonPressTimer.getElapsedTime() >= 300) //Buttons may only be pressed every .3 seconds
		{
			const VolumeUpEvent& volume = static_cast<const VolumeUpEvent&>(theEvent);
			bool up = volume.getUpOrDown();
			if (up)
			{
				mpSystem->getMusicSystem()->increaseVolume();
			}
			else if (!up)
			{
				mpSystem->getMusicSystem()->decreaseVolume();
			}
		}
		mButtonPressTimer.start();
	}
	else if (theEvent.getType() == SELECT_SONG_EVENT)
	{
		const SelectSongEvent& song = static_cast<const SelectSongEvent&>(theEvent);
		if (song.getSong() == 0)
		{
			mCurrentSong = SANDSTORM_SONG_FILENAME;
			mCurrentMap = SANDSTORM_MAP_FILENAME;
			mCurrentBackground = "Sandstorm_Background";
			//mpSystem->getMusicSystem()->init(ASSET_PATH + SANDSTORM_SONG_FILENAME);
			//mpNoteManager->createMap(SANDSTORM_MAP_FILENAME);
		}
		else if (song.getSong() == 1)
		{
			mCurrentSong = MEGALOVANIA_SONG_FILENAME;
			mCurrentMap = MEGALOVANIA_MAP_FILENAME;
			mCurrentBackground = "Megalovnia_Background";
			//mpSystem->getMusicSystem()->init(ASSET_PATH + MEGALOVANIA_SONG_FILENAME);
			//mpNoteManager->createMap(MEGALOVANIA_MAP_FILENAME);
		}
		else if (song.getSong() == 2)
		{
			mCurrentSong = RUNNING_SONG_FILENAME;
			mCurrentMap = RUNNING_MAP_FILENAME;
			mCurrentBackground = "Running_Background";
			//mpSystem->getMusicSystem()->init(ASSET_PATH + RUNNING_SONG_FILENAME);
			//mpNoteManager->createMap(RUNNING_MAP_FILENAME);
		}
		mpSystem->getMusicSystem()->init(ASSET_PATH + mCurrentSong);
		mpNoteManager->createMap(mCurrentMap);
		mCurrentScreen = GAME_SCREEN;
		mSongSize = int(mpNoteManager->getSize());
	}
	else if (theEvent.getType() == SWITCH_LANGUAGE_EVENT)
	{
		const SwitchLanguageEvent& lang = static_cast<const SwitchLanguageEvent&>(theEvent);
		mCurrentLanguage = lang.getLanguage();
		mpUIManager->switchLanguage(mCurrentLanguage);
	}
	else if (theEvent.getType() == QUIT_EVENT)
	{
		mpSystem->getMusicSystem()->stopMusic();
		saveGame();

		mLoop = false;
	}
}

void Game::hitNote()
{
	mScore = mScore + (300 * mCombo);
	mCombo++;
	if (mCombo > mGreatestCombo)
	{
		mGreatestCombo = mCombo;
	}

	mpUIManager->getUIVec()[mpUIManager->UI_SCORE]->setMessage(" " + to_string(mScore));
	mpUIManager->getUIVec()[mpUIManager->UI_COMBO]->setMessage(" " + to_string(mCombo));
}

void Game::missNote()
{
	mCombo = 1;
	mpUIManager->getUIVec()[mpUIManager->UI_COMBO]->setMessage(" " + to_string(mCombo));
	mMissednotesCounter++;
}


Game::Game()
{

}

Game::~Game()
{
	cleanup();
}

void Game::init()
{
	mpSystem = new System;
	mpSystem->initSystem();

	mpSystem->getGraphicsSystem()->initializeDisplay(DISPLAY_WIDTH, DISPLAY_HEIGHT);

	mpUnitManager = new UnitManager;
	mpGraphicsBufferManager = new GraphicsBufferManager;
	mpInputTranslator = new InputTranslator;
	mpInputTranslator->init();
	mpSystem->getInputSystem()->init(mpSystem->getGraphicsSystem()->getWindow());

	EventSystem::getInstance()->addListener(MOVE_CURSOR_EVENT, this);
	EventSystem::getInstance()->addListener(LEFT_CLICK_CIRCLE_EVENT, this);
	EventSystem::getInstance()->addListener(RIGHT_CLICK_CIRCLE_EVENT, this);
	EventSystem::getInstance()->addListener(Z_PRESS_CIRCLE_EVENT, this);
	EventSystem::getInstance()->addListener(X_PRESS_CIRCLE_EVENT, this);
	EventSystem::getInstance()->addListener(QUIT_EVENT, this);
	EventSystem::getInstance()->addListener(CHANGE_SCREEN_EVENT, this);
	EventSystem::getInstance()->addListener(VOLUME_UP_EVENT, this);
	EventSystem::getInstance()->addListener(SELECT_SONG_EVENT, this);
	EventSystem::getInstance()->addListener(SWITCH_LANGUAGE_EVENT, this);

	mpGraphicsBufferManager->createAndManageGraphicsBuffer("Background", ASSET_PATH + BACKGROUND_FILENAME);
	mpGraphicsBufferManager->createAndManageGraphicsBuffer("Sandstorm_Background", ASSET_PATH + SANDSTORM_BACKGROUND_FILENAME);
	mpGraphicsBufferManager->createAndManageGraphicsBuffer("Megalovnia_Background", ASSET_PATH + MEGALOVANIA_BACKGROUND_FILENAME);
	mpGraphicsBufferManager->createAndManageGraphicsBuffer("Running_Background", ASSET_PATH + RUNNING_BACKGROUND_FILENAME);
	mpGraphicsBufferManager->createAndManageGraphicsBuffer("cursor", ASSET_PATH + CURSOR_FILENAME);

	mpNoteManager = new NoteManager;
	mpNoteManager->init();

	mpUIManager = new UIManager;
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 24, 575, 25)); //Score
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 24, 25, 550)); //Combo
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 24, 20, 25)); //Quit
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 24, 690, 550)); //Return
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 300, 250)); //Start Game
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 300, 375)); //Load Game
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 300, 500)); //Options
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 275, 100)); //Final Project
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 300, 250)); //Level 1
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 300, 375)); //Level 2
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 300, 500)); //Level 3
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 100, 295, 330)); //Volume Up
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 100, 445, 330)); //Volume Down
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 300, 500)); //Languages
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 300, 250)); //English
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 300, 375)); //Spanish
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 300, 500)); //French
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 40, 250, 100)); //Results Screen Score
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 345, 400)); //Results Screen Hit%
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 345, 350)); //Results Screen Combo
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 100, 350)); //Results Screen Hit
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 100, 400)); //Results Screen Miss
	mpUIManager->addUI(new UI(ASSET_PATH + FONT_PATH, 35, 100, 500)); //Results Screen Pass/Fail

	mpUIManager->addLanguage();

	mpCat = new Cat;

	for (int i = 1; i <= 9; i++)
	{
		mpGraphicsBufferManager->createAndManageGraphicsBuffer("Cat" + to_string(i), ASSET_PATH + "BongoCatMouse\\" + "Hand" + to_string(i) + ".png");
		mpCat->addSprite(new Sprite(mpGraphicsBufferManager->getGraphicsBuffer("Cat" + to_string(i)), 0, 0, 640, 640));
	}

	mpCatHand = new CatHand;
	for (int i = 1; i <= 2; i++)
	{
		mpGraphicsBufferManager->createAndManageGraphicsBuffer("CatHand" + to_string(i), ASSET_PATH + "BongoCatHand\\" + "KeyTapHand" + to_string(i) + ".png");
		mpCatHand->addSprite(new Sprite(mpGraphicsBufferManager->getGraphicsBuffer("CatHand" + to_string(i)), 0, 0, 640, 640));
	}

	mpButtonManager = new ButtonManager;
	//Create all of the buttons for the menus
	mpButtonManager->addButton(BUTTON_MENU_QUIT, mpButtonManager->SQUARE_BUTTON, 0, 0); //Quit the game
	mpButtonManager->addButton(BUTTON_MENU_RETURN, mpButtonManager->SQUARE_BUTTON, 700, 500); //Return to the Main Menu
	mpButtonManager->addButton(BUTTON_MAIN_MENU_START, mpButtonManager->RECTANGLE_BUTTON, 175, 225); //Start the game normally
	mpButtonManager->addButton(BUTTON_MAIN_MENU_LOAD, mpButtonManager->RECTANGLE_BUTTON, 175, 350); //Load from a saved game
	mpButtonManager->addButton(BUTTON_MAIN_MENU_OPTIONS, mpButtonManager->RECTANGLE_BUTTON, 175, 475); //Open the Options Menu
	mpButtonManager->addButton(BUTTON_OPTIONS_VOLUME_UP, mpButtonManager->SQUARE_BUTTON, 275, 350); //Volume Up
	mpButtonManager->addButton(BUTTON_OPTIONS_VOLUME_DOWN, mpButtonManager->SQUARE_BUTTON, 425, 350); //Volume Down
	mpButtonManager->addButton(BUTTON_OPTIONS_LANGUAGE, mpButtonManager->RECTANGLE_BUTTON, 175, 475); //Open Language Menu
	mpButtonManager->addButton(BUTTON_LEVEL_SELECT_OPTION1, mpButtonManager->RECTANGLE_BUTTON, 175, 225); //Open Song Option 1
	mpButtonManager->addButton(BUTTON_LEVEL_SELECT_OPTION2, mpButtonManager->RECTANGLE_BUTTON, 175, 350); //Open Song Option 2
	mpButtonManager->addButton(BUTTON_LEVEL_SELECT_OPTION3, mpButtonManager->RECTANGLE_BUTTON, 175, 475); //Open Song Option 3
	mpButtonManager->addButton(BUTTON_LANGUAGE_ENG, mpButtonManager->RECTANGLE_BUTTON, 175, 225); //Open Language Option 1
	mpButtonManager->addButton(BUTTON_LANGUAGE_FRN, mpButtonManager->RECTANGLE_BUTTON, 175, 350); //Open Language Option 2
	mpButtonManager->addButton(BUTTON_LANGUAGE_SPN, mpButtonManager->RECTANGLE_BUTTON, 175, 475); //Open Language Option 3

	mButtonPressTimer.start();
}

void Game::cleanup()
{
	delete mpSystem;
	mpSystem = NULL;

	delete mpGraphicsBufferManager;
	mpGraphicsBufferManager = NULL;

	delete mpUnitManager;
	mpUnitManager = NULL;

	delete mpInputTranslator;
	mpInputTranslator = NULL;

	mpNoteManager->cleanup();
	delete mpNoteManager;
	mpNoteManager = NULL;

	delete mpBaseSprite;
	mpBaseSprite = NULL;

	mpUIManager->cleanup();
	delete mpUIManager;
	mpUIManager = NULL;

	mpCat->cleanup();
	delete mpCat;
	mpCat = NULL;

	mpCatHand->cleanup();
	delete mpCatHand;
	mpCatHand = NULL;

	mpButtonManager->cleanup();
	delete mpButtonManager;
	mpButtonManager = NULL;
}

void Game::menuLoop()
{
	drawCurrentScreen();
}

void Game::gameLoop()
{
	if (mpSystem->getMusicSystem()->getStatus() == mpSystem->getMusicSystem()->STOPPED) //Plays music
	{
		//loadGame(); //Loads the game
		mpSystem->getMusicSystem()->playMusic(mpNoteManager->getElapsedTime());
	}

	mpNoteManager->update(MS_PER_FRAME);
	mpCat->swapSprite(getMouseX(), getMouseY());

	drawCurrentScreen();
	goToResults(); //Check if the song has ended or not.
}

void Game::doLoop()
{
	PerformanceTracker* pPerform = new PerformanceTracker();
	string mTracker = "Tracking";

	Sprite* cursor = new Sprite(mpGraphicsBufferManager->getGraphicsBuffer("cursor"), 0, 0, 50, 50);

	do
	{
		pPerform->clearTracker(mTracker);
		pPerform->startTracking(mTracker);
		mTimer.start();

		mpSystem->getInputSystem()->update(mpSystem->getGraphicsSystem()->getWindow());
		if (mCurrentScreen == GAME_SCREEN)
		{
			mButtonPressTimer.stop();
			gameLoop();
		}
		else if (mCurrentScreen == LOAD_GAME_SCREEN)
		{
			mButtonPressTimer.stop();
			loadGame();
		}
		else
		{
			drawCurrentScreen();
		}
		mpSystem->getGraphicsSystem()->simpleDraw(cursor, getMouseX() - 25, getMouseY() - 25);
			
		mpSystem->getGraphicsSystem()->flip();

		mTimer.sleepUntilElapsed(MS_PER_FRAME);
		pPerform->stopTracking(mTracker);
		//cout << pPreform->getElapsedTime(mTracker) << endl;

	} while (mLoop);

	delete cursor;
	cursor = NULL;

	delete pPerform;
	pPerform = NULL;
}

bool Game::goToResults()
{
	if (mpSystem->getMusicSystem()->getStatus() == mpSystem->getMusicSystem()->STOPPED) //Plays music
	{

		mCurrentScreen = RESULTS_SCREEN;
		return true;
	}
	return false;
}

void Game::drawCurrentScreen()
{
	mpSystem->getGraphicsSystem()->draw(mpGraphicsBufferManager->getGraphicsBuffer("Background"), 0, 0, 1600, 1200, 0, 0, 0.5, 0);
	switch (mCurrentScreen)
	{
	case MAIN_MENU_SCREEN: 
	{
		mpButtonManager->draw(MAIN_MENU_SCREEN);
		mpUIManager->draw(mpUIManager->UI_MENU_QUIT, mpUIManager->UI_MAIN_MENU_TITLE);
		break;
	}
	case OPTIONS_MENU_SCREEN: 
	{
		mpButtonManager->draw(OPTIONS_MENU_SCREEN);
		mpUIManager->draw(mpUIManager->UI_MENU_QUIT, mpUIManager->UI_MENU_RETURN);
		mpUIManager->draw(mpUIManager->UI_OPTIONS_VOLUME_UP, mpUIManager->UI_OPTIONS_LANGUAGE);
		break;
	}
	case SONG_SELECT_SCREEN: 
	{
		mpButtonManager->draw(SONG_SELECT_SCREEN);
		mpUIManager->draw(mpUIManager->UI_MENU_QUIT, mpUIManager->UI_MENU_RETURN);
		mpUIManager->draw(mpUIManager->UI_LEVEL_SELECT_OPTION1, mpUIManager->UI_LEVEL_SELECT_OPTION3);
		break;
	}
	case LANGUAGE_MENU_SCREEN:
	{
		mpButtonManager->draw(LANGUAGE_MENU_SCREEN);
		mpUIManager->draw(mpUIManager->UI_MENU_QUIT, mpUIManager->UI_MENU_RETURN);
		mpUIManager->draw(mpUIManager->UI_LANGUAGE_ENG, mpUIManager->UI_LANGUAGE_FRN);
		break;
	}
	case GAME_SCREEN:
	{

		mpSystem->getGraphicsSystem()->draw(mpGraphicsBufferManager->getGraphicsBuffer(mCurrentBackground), 0, 0, 1600, 1200, 0, 0, 1.0, 0);
		mpCat->draw();
		if (mCatHandDown)
		{
			mpCatHand->draw();
			if (mCatTimer.getElapsedTime() >= 30)
			{
				mCatHandDown = false;
			}
		}
		mpNoteManager->draw();
		mpUIManager->draw(mpUIManager->UI_SCORE, mpUIManager->UI_COMBO);
		break;
	}
	case RESULTS_SCREEN:
	{
		int numHit = 0;
		int hitPercent = 0;
		if (mSongSize > 0)
		{
			numHit = mSongSize - mMissednotesCounter;
			hitPercent = int(numHit * 100.f / mSongSize) ;
			if (numHit == mSongSize)
			{
				hitPercent = 100;
			}
		}
		string passFail = "Fail...";
		if (hitPercent >= 75)
		{
			passFail = "Pass!";
		}
		mpButtonManager->draw(RESULTS_SCREEN);
		mpUIManager->getUIVec()[mpUIManager->UI_RESULTS_SCORE]->setMessage(" " + to_string(mScore));
		mpUIManager->getUIVec()[mpUIManager->UI_RESULTS_HIT]->setMessage(" " + to_string(numHit));
		mpUIManager->getUIVec()[mpUIManager->UI_RESULTS_MISSED]->setMessage(" " + to_string(mMissednotesCounter));
		mpUIManager->getUIVec()[mpUIManager->UI_RESULTS_GREATEST_COMBO]->setMessage(" x" + to_string(mGreatestCombo));
		mpUIManager->getUIVec()[mpUIManager->UI_RESULTS_HITPERCENT]->setMessage(" " + to_string(hitPercent) + "%");
		mpUIManager->getUIVec()[mpUIManager->UI_RESULTS_PASSFAIL]->setMessage(" " + passFail);
		mpUIManager->draw(mpUIManager->UI_MENU_QUIT, mpUIManager->UI_MENU_RETURN);
		mpUIManager->draw(mpUIManager->UI_RESULTS_SCORE, mpUIManager->UI_RESULTS_PASSFAIL);
		break;
	}	
	}
}
