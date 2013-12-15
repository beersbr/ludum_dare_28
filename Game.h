//
//  Game.h
//  ludum_dare_28
//
//  Created by Brett Beers on 12/14/13.
//  Copyright (c) 2013 Brett Beers. All rights reserved.
//

#ifndef __ludum_dare_28__Game__
#define __ludum_dare_28__Game__

#include <iostream>

namespace LD28
{
    enum GAME_ERROR {
        SDL_INIT_ERROR,
        SDL_WINDOW_INIT_ERROR,
        SDL_RENDERER_INIT_ERROR
    };
    
    class Game
    {
    public:
        Game();
        ~Game();
        
        void Init();
        void Run();
        void Render();
        void Update();
        void HandleEvents();
        void Clean();
        
    private:
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderContext;
        
        int frameStart, frameTime;
    };
}


#endif /* defined(__ludum_dare_28__Game__) */
