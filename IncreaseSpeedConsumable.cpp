#include "IncreaseSpeedConsumable.h"

IncreaseSpeedConsumable::~IncreaseSpeedConsumable() = default;

void IncreaseSpeedConsumable::executeConsumableEffect(ISnakeEffects* snake)
{
	snake->increaseSpeed();
}
