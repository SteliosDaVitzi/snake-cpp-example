#pragma once
#include "ISnakeEffects.h"
#include "VisualComponents.h"

class IConsumable
{
public:
	virtual ~IConsumable() = default;
	Color color;
	Rect rect;
	virtual void executeConsumableEffect(ISnakeEffects* snake) = 0;
};
