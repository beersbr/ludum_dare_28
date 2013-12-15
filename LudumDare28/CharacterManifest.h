#ifndef __CHARMANIFEST_H
#define __CHARMANIFEST_H

#include "Manifest.h"

namespace LD28
{
	class CharacterManifest : Manifest
	{
	public:
		CharacterManifest(GameString charName);
		~CharacterManifest();
	private:
		virtual void parseManifest();
		void findFile();
		//We need members here to define hit/hurt boxes
		//Also need members for animations defining moves
		
	};

}

#endif