#include "CharacterManifest.h"
#include <rapidjson\document.h>

namespace LD28
{

	CharacterManifest::CharacterManifest(GameString charName)
	{
		this->entName = charName;
		this->entType = EntType::CHARACTER;

		//Look for file
	}
	
	void CharacterManifest::parseManifest()
	{
		//Parse a character file
		rapidjson::Document manifestDoc;

	}
}