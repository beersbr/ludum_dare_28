//
//  AudioManger.h
//  ludum_dare_28
//
//  Created by Brett Beers on 12/15/13.
//  Copyright (c) 2013 Brett Beers. All rights reserved.
//

#ifndef __ludum_dare_28__AudioManger__
#define __ludum_dare_28__AudioManger__

#include <iostream>
#include <map>

#include <SDL2_mixer/SDL_mixer.h>

namespace LD28
{
    enum SOUND_TYPE{
        AUDIO_MANAGER_MUSIC,
        AUDIO_MANAGER_SFXS
    };
    
    enum AUDIO_MANAGER_ERROR{
        FILE_NOT_FOUND
    };
    
    class AudioManager
    {
    public:
        static AudioManager* Instance();
        
        bool Load(std::string fileName, std::string key, SOUND_TYPE type);
        
        void Clean();
        
        int PlaySound(std::string key, const int loop);
        void PlayMusic(std::string key, const int loop);
        
        void StopSfxs(const int channel) const;
        void StopMusic();
        
    private:
        static AudioManager* instance;
        
        AudioManager();
        AudioManager(const AudioManager&);
        AudioManager& operator=(const AudioManager&);
        
        std::map<std::string, Mix_Chunk*> sfxs;
        std::map<std::string, Mix_Music*> music;
    };
}

#endif /* defined(__ludum_dare_28__AudioManger__) */
