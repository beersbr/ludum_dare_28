//
//  TextureManager.h
//  ludum_dare_28
//
//  Created by Brett Beers on 12/15/13.
//  Copyright (c) 2013 Brett Beers. All rights reserved.
//

#ifndef __ludum_dare_28__TextureManager__
#define __ludum_dare_28__TextureManager__

#include <iostream>

namespace LD28
{
    class TextureManager
    {
    public:
        static TextureManager* Instance();
        
        
    private:
        static TextureManager* instance;
        
        TextureManager();
        TextureManager(const TextureManager&);
        TextureManager& operator=(const TextureManager&);
        
        
        
    };
}

#endif /* defined(__ludum_dare_28__TextureManager__) */
