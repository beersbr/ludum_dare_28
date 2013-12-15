//
//  Controller.cpp
//  ludum_dare_28
//
//  Created by Brett Beers on 12/14/13.
//  Copyright (c) 2013 Brett Beers. All rights reserved.
//

#include "Controller.h"

namespace LD28
{
    Controller* Controller::instance = nullptr;
    
    Controller* Controller::GetController()
    {
        if(Controller::instance == nullptr)
        {
            Controller::instance = new Controller::Controller();
        }
        
        return Controller::instance;
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