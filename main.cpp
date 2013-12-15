#include <iostream>
#include <SDL2/SDL.h>

#include "game.h"
#include <SDL2_mixer/SDL_mixer.h>

int main(int argv, char* argc[])
{
    LD28::Game* game = new LD28::Game();
    
    
    Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
    Mix_Chunk* chunk = Mix_LoadWAV("./sounds/song.wav");
    Mix_PlayChannel(-1, chunk, true);
    
    try {
        game->Init();
        game->Run();
    } catch (int exception) {
        std::cout << "Unrecoverable error: " << exception << std::endl;
    }
    
	return 0;
}