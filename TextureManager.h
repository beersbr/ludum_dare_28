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
#include <map>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

namespace LD28
{
    class TextureManager
    {
    public:
        static TextureManager* Instance();
        
        bool Load(std::string fileName, std::string key, SDL_Renderer* renderContext);
        void Draw(std::string key, int srcX, int srcY, int srcW, int srcH, int dstX, int dstY, int dstW, int dstH, SDL_Renderer* renderContext, SDL_RendererFlip flip);
        
    private:
        static TextureManager* instance;
        
        TextureManager();
        TextureManager(const TextureManager&);
        TextureManager& operator=(const TextureManager&);
        
        std::map<std::string, SDL_Texture*> textures;
    };
}

#endif /* defined(__ludum_dare_28__TextureManager__) */
