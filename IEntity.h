#ifndef __ludum_dare_28__IEntity__
#define __ludum_dare_28__IEntity__

#include <iostream>
#include <SDL2/SDL.h>

#include "Vector.h"

namespace LD28
{
    class IEntity
    {
	public:
        virtual ~IEntity();
		virtual bool init();
	private:
		SDL_Texture* texture;
		SDL_Rect sourceRect; //Where in the sprite sheet the current animation is
		SDL_Rect destRect;   //Where on the screen it should be drawn (This can be calculated from the position vector, the destRect x and y need to be the top left hand corner, though.)
        Vector position, velocity;
	};
}

#endif /* defined(__ludum_dare_28__IEntity__) */
