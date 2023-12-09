#pragma once
#include <list>
#include "IConsumable.h"
using namespace std;

class IConsumablesGenerator
{
public:
	virtual ~IConsumablesGenerator()
	{
		for (IConsumable* consumable : consumables)
			delete consumable;
	}
	list<IConsumable*> consumables;
	virtual IConsumable* getConsumable() = 0;
};
