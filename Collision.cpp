//
//  Collision.cpp
//  ludum_dare_28
//
//  Created by Brett Beers on 12/15/13.
//  Copyright (c) 2013 Brett Beers. All rights reserved.
//

#include "Collision.h"

namespace LD28
{
    bool Colliding(SDL_Rect* a, SDL_Rect* b)
    {
        if(a->x > b->x+b->w) return false;
        if(a->x+a->w < b->x) return false;
        if(a->y > b->y+b->h) return false;
        if(a->y+a->h < b->y) return false;
        return true;
    }
    
    Vector GetCollisionReturnVector(const SDL_Rect* a, const SDL_Rect* b)
    {
        Vector va = { a->x + (a->w / 2), a->y + (a->h / 2), 0};
        Vector vb = { b->x + (b->w / 2), b->y + (b->h / 2), 0};
        
        Vector distance = (va-vb);
        Vector minDistance = { a->w + b->w, a->h+b->h, 0 };
        
        if(distance.x < minDistance.x && distance.y < minDistance.y)
        {
            return distance;
        }
        
        return {0, 0, 0};
    }
}