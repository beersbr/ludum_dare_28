#ifndef __ludum_dare_28__Game__
#define __ludum_dare_28__Game__

#include <iostream>
#include <SDL2/SDL.h>
#include "Controller.h"

namespace LD28
{
    enum GAME_ERROR {
        SDL_INIT_ERROR,
        SDL_WINDOW_INIT_ERROR,
        SDL_RENDERER_INIT_ERROR
    };
    
    enum GAME_STATE{
        STARTUP,
        RUNNING,
        PAUSED,
        MENU,
        QUIT
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
        SDL_Window* window;
        SDL_Renderer* renderContext;
        
        int frameStart, frameTime;
        int frameCount;
        GAME_STATE gameState;
    };
}


#endif /* defined(__ludum_dare_28__Game__) */
