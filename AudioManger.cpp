//
//  AudioManger.cpp
//  ludum_dare_28
//
//  Created by Brett Beers on 12/15/13.
//  Copyright (c) 2013 Brett Beers. All rights reserved.
//

#include "AudioManger.h"

namespace LD28
{
    AudioManager* AudioManager::instance = nullptr;
    
    AudioManager* AudioManager::Instance()
    {
        if(instance == nullptr)
        {
            instance = new AudioManager();
        }
        
        return instance;
    }
    
    AudioManager::AudioManager()
    {
        Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
    }
    
    bool AudioManager::Load(std::string fileName, std::string key, SOUND_TYPE type)
    {
        bool success = false;
        
        switch(type)
        {
            case AUDIO_MANAGER_MUSIC:
            {
                Mix_Music* tmpMusic = Mix_LoadMUS(fileName.c_str());
                
                if(!tmpMusic)
                    break;
                
                music[key] = tmpMusic;
                success = true;
                
                break;
            }
            case AUDIO_MANAGER_SFXS:
            {
                Mix_Chunk* tmpChunk = Mix_LoadWAV(fileName.c_str());
                
                if(!tmpChunk)
                    break;
                
                sfxs[key] = tmpChunk;
                success = true;
                
                break;
            }
        }
        
        return success;
    }
    
    void AudioManager::PlaySound(std::string key, int loop)
    {
        Mix_PlayChannel(-1, sfxs[key], loop);
    }
    
    void AudioManager::PlayMusic(std::string key, int loop)
    {
        Mix_PlayMusic(music[key], loop);
    }
    
    void AudioManager::StopMusic()
    {
        Mix_HaltMusic();
    }
    
        
}