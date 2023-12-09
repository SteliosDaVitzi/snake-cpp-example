#include "InscreaseSizeConsumable.h"

IncreaseSizeConsumable::~IncreaseSizeConsumable() = default;


void IncreaseSizeConsumable::executeConsumableEffect(ISnakeEffects* snake)
{
	snake->increaseSize();
}