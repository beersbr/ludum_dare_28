#ifndef __MANIFEST_H
#define __MANIFEST_H
//Manifest class, describes the asset by name, and what should be loaded

#include "Common.h"

enum class EntType {CHARACTER, PROJECTILE, OBJECT};

namespace LD28
{
	class Manifest
	{
	public:
	private:
		virtual void parseManifest() = 0;
	protected:
		GameString entName; // Name of object, essntial to load and parse manifest
		EntType entType;
		GameString filePath;
	};
}

#endif