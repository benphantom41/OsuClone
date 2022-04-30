#pragma once

#include "Trackable.h"
#include "UI.h"
#include <vector>

class UI;

class UIManager : public Trackable
{
public:

	UIManager() {};
	~UIManager() { cleanup(); };

	void addUI(UI* ui);

	void cleanup();

	void update();

	void draw(int lowerBound, int upperBound);

	void draw(int index);

	void addLanguage();

	void switchLanguage(int language);

	std::vector<UI*> getUIVec() { return mpUI; };

	enum UINames
	{
		INVALID_UI_NAME = -1,
		UI_SCORE,
		UI_COMBO,
		UI_MENU_QUIT,
		UI_MENU_RETURN,
		UI_MAIN_MENU_START, //Sends you to the Level Select
		UI_MAIN_MENU_LOAD, //Loads a Saved Game
		UI_MAIN_MENU_OPTIONS, //Sends you to the Options Menu
		UI_MAIN_MENU_TITLE, //Title Message
		UI_LEVEL_SELECT_OPTION1,
		UI_LEVEL_SELECT_OPTION2,
		UI_LEVEL_SELECT_OPTION3,
		UI_OPTIONS_VOLUME_UP,
		UI_OPTIONS_VOLUME_DOWN,
		UI_OPTIONS_LANGUAGE, //Sends you to the Language Select Menu
		UI_LANGUAGE_ENG,
		UI_LANGUAGE_SPN,
		UI_LANGUAGE_FRN,
		UI_RESULTS_SCORE,
		UI_RESULTS_HITPERCENT,
		UI_RESULTS_GREATEST_COMBO,
		UI_RESULTS_HIT,
		UI_RESULTS_MISSED,
		UI_RESULTS_PASSFAIL,
		NUM_UI_NAMES
	};

private:
	std::vector<UI*> mpUI;

};
