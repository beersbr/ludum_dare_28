#include "Game.h"

namespace LD28
{
    Game::Game()
    {
        gameState = STARTUP;
    }
    
    
    Game::~Game()
    {
        
    }
    
    
    void Game::Init()
    {
        if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
            throw SDL_INIT_ERROR;
        
        window = SDL_CreateWindow("You Only Get 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
        
        if(window == nullptr)
            throw SDL_WINDOW_INIT_ERROR;
        
        renderContext = SDL_CreateRenderer(window, -1, 0);
        
        if(renderContext == nullptr)
            throw SDL_RENDERER_INIT_ERROR;
        
        SDL_SetRenderDrawColor(renderContext, 255, 0, 255, 255);
        
    }
    
    
    void Game::Run()
    {
        const float TargetFps = 60.0f;
        const float DelayTime = 1000.0f / TargetFps;
        
        gameState = RUNNING;
        
        while(gameState == RUNNING)
        {
            frameStart = SDL_GetTicks();
            
            HandleEvents();
            Update();
            Render();
            
            
            frameCount += 1;
            frameTime = SDL_GetTicks() - frameStart;
            
            if(frameStart < DelayTime)
            {
                SDL_Delay((int)(DelayTime - frameTime));
            }
            
        }
        
        Clean();
    }
    
    
    void Game::Render()
    {
        SDL_RenderClear(renderContext);
        SDL_RenderPresent(renderContext);
    }
    
    void Game::Update()
    {
        Controller::Instance()->Update();
    }
    
    
    void Game::HandleEvents()
    {
        SDL_Event event;
        if(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    gameState = QUIT;
                    break;
                    
                default:
                    break;
            }
        }
    }
    
    
    void Game::Clean()
    {
        SDL_DestroyRenderer(renderContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    
}