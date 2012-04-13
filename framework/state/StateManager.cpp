#include "StateManager.h"

void StateManager::push(State newState)
{
    this.states.push(newState);
}

void StateManager::pop()
{
    this.states.pop();
}

void StateManager::unwind()
{
    while(states.empty()) 
    {
        this.states.pop();
    }
}
