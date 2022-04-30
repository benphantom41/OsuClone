#include "UIManager.h"
#include <fstream>

void UIManager::addUI(UI* ui)
{
	mpUI.push_back(ui);
}

void UIManager::cleanup()
{
	unsigned size = mpUI.size();

	for (unsigned i = 0; i < size; i++)
	{
		mpUI[i]->cleanup();
		delete mpUI[i];
	}
	mpUI.clear();
	mpUI.shrink_to_fit();

}

void UIManager::update()
{
}

void UIManager::draw(int lowerBound, int upperBound)
{
	for (int i = lowerBound; i <= upperBound; i++)
	{
		mpUI[i]->draw();
	}
}

void UIManager::draw(int index)
{
	mpUI[index]->draw();
}


void UIManager::addLanguage()
{
	fstream language;
	language.open("Languages.txt");
	string text;

	for (unsigned i = 0; i < mpUI.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			getline(language, text);

			mpUI[i]->addToLanguageVec(text);
		}
	}
}

void UIManager::switchLanguage(int language)
{
	for (unsigned i = 0; i < mpUI.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{

			mpUI[i]->setLanguage(language);
		}
	}
}
