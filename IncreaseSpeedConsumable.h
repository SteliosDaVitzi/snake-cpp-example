#pragma once
#include "IConsumable.h"

class IncreaseSpeedConsumable : public IConsumable
{
public:
	~IncreaseSpeedConsumable() override;
	void executeConsumableEffect(ISnakeEffects* snake) override;
};
