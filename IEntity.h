//
//  IEntity.h
//  ludum_dare_28
//
//  Created by Brett Beers on 12/15/13.
//  Copyright (c) 2013 Brett Beers. All rights reserved.
//

#ifndef __ludum_dare_28__IEntity__
#define __ludum_dare_28__IEntity__

#include <iostream>
#include <SDL2/SDL.h>

#include "Vector.h"

namespace LD28
{
    class IEntity
    {
        virtual ~IEntity();
        
        Vector position, velocity;
    };
}

#endif /* defined(__ludum_dare_28__IEntity__) */
