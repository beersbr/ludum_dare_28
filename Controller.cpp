#include "Controller.h"

namespace LD28
{
    Controller* Controller::instance = nullptr;
    
    Controller* Controller::Instance()
    {
        if(instance == nullptr)
        {
            instance = new Controller;
        }
        
        return instance;
    }
    
    
    
    void Controller::Update()
    {
        keyState = SDL_GetKeyboardState(0);
    }
    
    bool Controller::KeyDown(const SDL_Scancode key) const
    {
        if(keyState == nullptr) return false;
        return (keyState[key] ? true : false);
    }
}