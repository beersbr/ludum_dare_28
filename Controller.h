#ifndef __ludum_dare_28__Controller__
#define __ludum_dare_28__Controller__

#include <iostream>
#include <SDL2/SDL.h>

namespace LD28
{
    class Controller
    {
    public:
        static Controller* GetController();
        
        void Update();
        bool KeyDown(const SDL_Scancode key) const;
        void ClearKeys();
        
        
    private:
        Controller(){};
        Controller(Controller const&){};
        static Controller* instance;
        
        const Uint8* keyState;
        
    };
}

#endif /* defined(__ludum_dare_28__Controller__) */
