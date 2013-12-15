
#include <iostream>
#include <SDL2/SDL.h>

#include "game.h"

int main(int argv, char* argc[])
{
    LD28::Game* game = new LD28::Game();
    
    try {
        game->Init();
        game->Run();
    } catch (int exception) {
        std::cout << "Unrecoverable error: " << exception << std::endl;
    }
    
}