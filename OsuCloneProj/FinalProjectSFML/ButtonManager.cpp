#include "ButtonManager.h"


void ButtonManager::addButton(int buttonName, int buttonShape, int posX, int posY)
{
	
	if (buttonShape == SQUARE_BUTTON)
	{
		Button* tempButton = new Button(buttonName, 100, 100, float(posX), float(posY));
		mpButtons.push_back(tempButton);
	}
	else if (buttonShape == RECTANGLE_BUTTON)
	{
		Button* tempButton = new Button(buttonName, 450, 100, float(posX), float(posY));
		mpButtons.push_back(tempButton);
	}
}

void ButtonManager::cleanup()
{
	unsigned size = mpButtons.size();

	for (unsigned i = 0; i < size; i++)
	{
		mpButtons[i]->cleanup();
		delete mpButtons[i];
	}
	mpButtons.clear();
	mpButtons.shrink_to_fit();

}

void ButtonManager::update()
{
}

void ButtonManager::clickButton(int menuName, int x, int y)
{
	for (unsigned i = 0; i < mpButtons.size(); i++) //Check each Button to see if it collided
	{
		int buttonName = mpButtons[i]->getButtonName();
		int quitButton = Button::BUTTON_MENU_QUIT;
		int returnButton = Button::BUTTON_MENU_RETURN;
		/*int buttonX = int(mpButtons[i]->getX());
		int buttonY = int(mpButtons[i]->getY());
		int buttonWidth = mpButtons[i]->getWidth();
		int buttonHeight = mpButtons[i]->getHeight();*/
		switch (menuName)
		{
		case MAIN_MENU_SCREEN: 
			if (buttonName >= quitButton && buttonName <= mpButtons[i]->BUTTON_MAIN_MENU_OPTIONS) // From 0-4
				{
				if (findButtonBoundaries(i, x, y))
				{
					return;
				}
				}
			break;
		case OPTIONS_MENU_SCREEN: 
			if (buttonName == quitButton || buttonName == returnButton || (buttonName >= mpButtons[i]->BUTTON_OPTIONS_VOLUME_UP && buttonName <= mpButtons[i]->BUTTON_OPTIONS_LANGUAGE)) // Quit, Return, and 5-7
				{
				if (findButtonBoundaries(i, x, y))
				{
					return;
				}
				}
			break;
		case LANGUAGE_MENU_SCREEN: 
			if (buttonName == quitButton || buttonName == returnButton || (buttonName >= mpButtons[i]->BUTTON_LANGUAGE_ENG && buttonName <= mpButtons[i]->BUTTON_LANGUAGE_SPN)) // Quit, Return, and 11-13
				{
				if (findButtonBoundaries(i, x, y))
				{
					return;
				}
				}
			break;
		case SONG_SELECT_SCREEN: 
			if (buttonName == quitButton || buttonName == returnButton || (buttonName >= mpButtons[i]->BUTTON_LEVEL_SELECT_OPTION1 && buttonName <= mpButtons[i]->BUTTON_LEVEL_SELECT_OPTION3)) // Quit, Return, and 8-10
				{
				if (findButtonBoundaries(i, x, y))
				{
					return;
				}					
				}
			break;
		case RESULTS_SCREEN: 
			if (buttonName == quitButton || buttonName == returnButton) // Quit & Return
				{
				if (findButtonBoundaries(i, x, y))
				{
					return;
				}
				}
			break;
		}
	}
}

void ButtonManager::resolveButtonClick(int buttonName)
{
	switch (buttonName)
	{
	case  0: //BUTTON_MENU_QUIT
		EventSystem::getInstance()->fireEvent(EndGameEvent());
		break;
	case 1: //BUTTON_MENU_RETURN
		EventSystem::getInstance()->fireEvent(ChangeScreenEvent(MAIN_MENU_SCREEN));
		break;
	case 2: //BUTTON_MAIN_MENU_START
		EventSystem::getInstance()->fireEvent(ChangeScreenEvent(SONG_SELECT_SCREEN));
		break;
	case  3: //BUTTON_MAIN_MENU_LOAD
		EventSystem::getInstance()->fireEvent(ChangeScreenEvent(LOAD_GAME_SCREEN));
		break;
	case 4: //BUTTON_MAIN_MENU_OPTIONS
		EventSystem::getInstance()->fireEvent(ChangeScreenEvent(OPTIONS_MENU_SCREEN));
		break;
	case 5: //BUTTON_OPTIONS_VOLUME_UP
		EventSystem::getInstance()->fireEvent(VolumeUpEvent(true));
		break;
	case  6: //BUTTON_OPTIONS_VOLUME_DOWN
		EventSystem::getInstance()->fireEvent(VolumeUpEvent(false));
		break;
	case 7: //BUTTON_OPTIONS_LANGUAGE
		EventSystem::getInstance()->fireEvent(ChangeScreenEvent(LANGUAGE_MENU_SCREEN));
		break;
	case 8: //BUTTON_LEVEL_SELECT_OPTION1
		EventSystem::getInstance()->fireEvent(SelectSongEvent(0));
		break;
	case  9: //BUTTON_LEVEL_SELECT_OPTION2
		EventSystem::getInstance()->fireEvent(SelectSongEvent(1));
		break;
	case 10: //BUTTON_LEVEL_SELECT_OPTION3
		EventSystem::getInstance()->fireEvent(SelectSongEvent(2));
		break;
	case 11: //BUTTON_LANGUAGE_ENG
		EventSystem::getInstance()->fireEvent(SwitchLanguageEvent(0));
		break;
	case  12: //BUTTON_LANGUAGE_FRN
		EventSystem::getInstance()->fireEvent(SwitchLanguageEvent(1));
		break;
	case 13: //BUTTON_LANGUAGE_SPN
		EventSystem::getInstance()->fireEvent(SwitchLanguageEvent(2));
		break;
	}
}

void ButtonManager::draw(int menuName)
{
	for (unsigned i = 0; i < mpButtons.size(); i++)
	{
		int buttonName = mpButtons[i]->getButtonName();
		int quitButton = Button::BUTTON_MENU_QUIT;
		int returnButton = Button::BUTTON_MENU_RETURN;
		switch (menuName)
		{
		case MAIN_MENU_SCREEN: if (buttonName >= quitButton && buttonName <= mpButtons[i]->BUTTON_MAIN_MENU_OPTIONS) // From 0-4
		{
			mpButtons[i]->draw();
		}
		break;
		case OPTIONS_MENU_SCREEN: if (buttonName == quitButton || buttonName == returnButton || (buttonName >= mpButtons[i]->BUTTON_OPTIONS_VOLUME_UP && buttonName <= mpButtons[i]->BUTTON_OPTIONS_LANGUAGE)) // Quit, Return, and 5-7
		{
			mpButtons[i]->draw();
		}
		break;
		case LANGUAGE_MENU_SCREEN: if (buttonName == quitButton || buttonName == returnButton || (buttonName >= mpButtons[i]->BUTTON_LANGUAGE_ENG && buttonName <= mpButtons[i]->BUTTON_LANGUAGE_SPN)) // Quit, Return, and 11-13
		{
			mpButtons[i]->draw();
		}
		break;
		case SONG_SELECT_SCREEN: if (buttonName == quitButton || buttonName == returnButton || (buttonName >= mpButtons[i]->BUTTON_LEVEL_SELECT_OPTION1 && buttonName <= mpButtons[i]->BUTTON_LEVEL_SELECT_OPTION3)) // Quit, Return, and 8-10
		{
			mpButtons[i]->draw();
		}
		break;
		case RESULTS_SCREEN: if (buttonName == quitButton || buttonName == returnButton) // Quit & Return
		{
			mpButtons[i]->draw();
		}
		break;
		}
	}
}

bool ButtonManager::findButtonBoundaries(int buttonID, int clickAtX, int clickAtY)
{
	int buttonName = mpButtons[buttonID]->getButtonName();
	int buttonX = int(mpButtons[buttonID]->getX());
	int buttonY = int(mpButtons[buttonID]->getY());
	int buttonWidth = mpButtons[buttonID]->getWidth();
	int buttonHeight = mpButtons[buttonID]->getHeight();

	if (buttonX <= clickAtX && clickAtX <= buttonX + buttonWidth)
	{
		if (buttonY <= clickAtY && clickAtY <= buttonY + buttonHeight)
		{
			resolveButtonClick(buttonName);
			return true;
		}
	}
	return false;
}
