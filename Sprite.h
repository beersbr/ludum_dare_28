//
//  Sprite.h
//  ludum_dare_28
//
//  Created by Brett Beers on 12/15/13.
//  Copyright (c) 2013 Brett Beers. All rights reserved.
//

#ifndef __ludum_dare_28__Sprite__
#define __ludum_dare_28__Sprite__

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "TextureManager.h"

/************************************************
 
 Sprite should know how many frames there are and where the frames are
 
 ***********************************************/

namespace LD28
{
    class Sprite
    {
    public:
        Sprite(/*...*/);
        Sprite(const Sprite&);
        Sprite& operator=(const Sprite&);
        
        bool Init();
        void Draw();
        
        ~Sprite();
        
    private:
        std::vector<SDL_Rect> frames;
        Uint8 maxFrames;
        
        
    };
}

#endif /* defined(__ludum_dare_28__Sprite__) */
