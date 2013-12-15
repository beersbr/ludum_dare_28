//
//  TextureManager.cpp
//  ludum_dare_28
//
//  Created by Brett Beers on 12/15/13.
//  Copyright (c) 2013 Brett Beers. All rights reserved.
//

#include "TextureManager.h"

namespace LD28 {
    
    TextureManager* TextureManager::instance = nullptr;
    
    TextureManager* TextureManager::Instance()
    {
        if(instance == nullptr)
        {
            instance = new TextureManager();
        }
        return instance;
    }
    
    TextureManager::TextureManager()
    {
        
    }
    
    bool TextureManager::Load(std::string fileName, std::string key, SDL_Renderer* renderContext)
    {
        SDL_Surface* tmpSurface = IMG_Load(fileName.c_str());
        
        if(!tmpSurface)
            return false;
        
        SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderContext, tmpSurface);
        
        SDL_FreeSurface(tmpSurface);
        
        if(!tmpTexture)
            return false;
        
        textures[key] = tmpTexture;
        
        return true;
    }
    

    void TextureManager::Draw(std::string key, int srcX, int srcY, int srcW, int srcH, int dstX, int dstY, int dstW, int dstH, SDL_Renderer *renderContext, SDL_RendererFlip flip)
    {
        
        // http://wiki.libsdl.org/SDL_RenderCopyEx
        SDL_Rect src = {srcX, srcY, srcW, srcH };
        SDL_Rect dst = {dstX, dstY, dstW, dstH };
        
        SDL_RenderCopyEx(renderContext, textures[key], &src, &dst, 0.0, nullptr, flip);
    }
}