#pragma once

class ISnakeEffects
{
public:
    virtual ~ISnakeEffects() = default;
    virtual void increaseSize() = 0;
    virtual void increaseSpeed() = 0;
};