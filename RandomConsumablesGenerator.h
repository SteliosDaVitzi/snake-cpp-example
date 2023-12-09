#pragma once
#include "IConsumablesGenerator.h"

class RandomConsumablesGenerator : public IConsumablesGenerator
{
public:
	IConsumable* getConsumable() override;
};
