#ifndef StateManager_h
#define StateManager_h

#include <stack>
#include <vector>
#include "State.h"


class StateManager {
private:
    stack<State, std::vector<State>> states;
    
public:
    virtual void push(State newState);
    virtual void pop();
    virtual void unwind();
};

#endif // StateManager_h
