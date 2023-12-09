#include "RandomConsumablesGenerator.h"
#include "IConsumable.h"
#include "Utils.h"

IConsumable* RandomConsumablesGenerator::getConsumable()
{
	return Utils::getRandomElementFromList(consumables);
}
