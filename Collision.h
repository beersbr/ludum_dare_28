//
//  Collision.h
//  ludum_dare_28
//
//  Created by Brett Beers on 12/15/13.
//  Copyright (c) 2013 Brett Beers. All rights reserved.
//

#ifndef __ludum_dare_28__Collision__
#define __ludum_dare_28__Collision__

#include <iostream>
#include <SDL2/SDL.h>

#include "vector.h"

namespace LD28
{
    bool Colliding(SDL_Rect* a, SDL_Rect* b);
    Vector* CollidingEx(const SDL_Rect* a, const SDL_Rect* b);
}

#endif /* defined(__ludum_dare_28__Collision__) */
