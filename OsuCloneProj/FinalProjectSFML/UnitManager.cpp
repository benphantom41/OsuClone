#include "UnitManager.h"
#include "Unit.h"

UnitManager::UnitManager()
{

}

UnitManager::~UnitManager()
{
	
}

void UnitManager::addUnit(Unit newUnit)
{
	mUnitList.push_back(newUnit);
}

void UnitManager::removeUnit(int x, int y)
{
	for (unsigned i = 0; i < mUnitList.size(); i++)
	{
		if (mUnitList[i].getLocX() > x && mUnitList[i].getLocX() < x + 30 || mUnitList[i].getLocX() < x && mUnitList[i].getLocX() > x - 30)
		{
			if (mUnitList[i].getLocY() > y && mUnitList[i].getLocY() < y + 30 || mUnitList[i].getLocY() < y && mUnitList[i].getLocY() > y - 30)
			{
				mUnitList.erase(mUnitList.begin() + i);
				mUnitList.shrink_to_fit();
			}
		}
	}
}

void UnitManager::removeAll()
{
	for (unsigned i = 0; i < mUnitList.size(); i++)
	{
		mUnitList[i].cleanup();
	}
	mUnitList.clear();
	mUnitList.shrink_to_fit();
}

void UnitManager::drawUnits()
{
	for (unsigned i = 0; i < mUnitList.size(); i++)
	{
		mUnitList[i].draw();
	}
}

void UnitManager::updateUnits(float time)
{
	for (unsigned i = 0; i < mUnitList.size(); i++)
	{
		mUnitList[i].update(time);
	}
}

void UnitManager::swapAnimation()
{
	for (unsigned i = 0; i < mUnitList.size(); i++)
	{
		//mUnitList[i].getAnimation().
	}
}
