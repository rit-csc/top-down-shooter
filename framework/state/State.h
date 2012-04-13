#ifndef State_h
#define State_h

class StateManager;

class State {
 public:
    virtual void State(void  StateManager) = 0;
    virtual void updateLoop(void  dt) = 0;
    virtual void render() = 0;
    virtual void onBecomeState() = 0;
    virtual void onReleaseState() = 0;
};

#endif // State_h
