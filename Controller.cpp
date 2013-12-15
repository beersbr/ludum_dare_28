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