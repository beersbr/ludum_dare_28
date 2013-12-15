#ifndef __CHARACTER_H
#define __CHARACTER_H

#include <SDL2/SDL.h>
#include <map>
#include <vector>

#include "Common.h"
#include "IEntity.h"


namespace LD28
{

	class Character : IEntity
	{
	public:
		Character();
		virtual ~Character();
		bool loadHitBoxes();
	private:
		GameString name;
		Map<GameString, DataVector<SDL_Rect>> hitBoxMap; //map of hitboxes i.e hitBoxMap['LP'] = list of hit boxes on a per-frame basis. Next frame should go to the next box
		Map<GameString, DataVector<SDL_Rect>> hurtBoxMap; //see hitboxmap
	};

}
#endif