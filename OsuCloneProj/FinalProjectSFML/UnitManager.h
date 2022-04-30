#ifndef UnitManager_h
#define UnitManager_h

#include "Trackable.h"
#include "Unit.h"
#include <vector>

class Unit;

using namespace std;

class UnitManager : public Trackable
{

public:

	UnitManager();

	~UnitManager();

	void addUnit(Unit newUnit);

	void removeUnit(int x, int y);

	void removeAll();

	void drawUnits();

	void updateUnits(float time);

	void swapAnimation();

private:

	vector<Unit> mUnitList;

};

#endif
