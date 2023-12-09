#pragma once
#include "IConsumable.h"

class IncreaseSizeConsumable : public IConsumable
{
public:
	~IncreaseSizeConsumable() override;
	void executeConsumableEffect(ISnakeEffects* snake) override;
};
