#include "CharacterManifest.h"

namespace LD28
{

	CharacterManifest::CharacterManifest(GameString charName)
	{
		this->entName = charName;
		this->entType = EntType::CHARACTER;

		//Look for file

	}
	
	bool CharacterManifest::parseManifest()
	{
		std::stringstream sStream;
		//We need to open and load the document ourselves.
		std::ifstream inFile(this->filePath);
		if(inFile.is_open())
		{
			GameString curLine;
			while( std::getline( inFile, curLine) )
			{
				sStream << curLine;
			}

		}
		else
		{
			//ERROR -> failed to oepn manifest document
			return false;
		}
		//Parse a character file
		rapidjson::Document manDoc;

		manDoc.Parse<0>(sStream.str().c_str());

		//Character manifests can be described as follows:
		//
		// { 
		//	"Texture" : "<s:FilePath>" # Character sheet
		//  "MoveList" : [ <MoveName1> , <MoveName2> , ... , <MoveNameN> ] #might not need this
		//  "MoveSet" : {
		//				   "Label" : <s:MoveNameN>
		//				   "input" : [ <btn1>, <btn2>, .. <btnN> ]
		//				   "damage" : <i:damage>
		//				   "blockFlags" : <s:blockStr>
		//				   "blockStun" : <i:blockFrames>
		//				   "hitStun" : <i:hitFrames>
		//				   "startFrames" : {
		//										"count" : <i:numFrames>
		//										"frameData" : [ { 
		//															"frameNo" : "<i:FrameIndex>"
		//															"sRect" : [ x, y, width, height] #Source rectangle size and position, maps to the texture
		//															"hurtBoxes" : [ [offx, offy, width, height], ...] 
		//														}, { ... } ]
		//								   }
		//				   "activeFrames" : {
		//										"count" : <i:numFrames>
		//										"frameData" : [ {
		//															"frameNo" : "<i:FrameIndex>"
		//															"sRect" : [x, y, width, height]
		//															"hurtBoxes" : [ [offx, offy, width, height], ...]
		//															"hitBox " : [offx, offy, width, height] 
		//														}, { ... } ]
		//				  "recoveryFrames" : {
		//										"count" : <i:numFrames>
		//										"frameData" : [ {
		//															"frameNo" : "<i:FrameIndex>"
		//															"sRect" : [x, y, width, height]
		//															"hurtBoxes" : [ [offx, offy, width, height], ...]
		//														}, { ... } ]
		//				}
		// "Animations" : {
		//					 "ForwardWalk": {
		//									"count" : <i:numFrames>
		//									"speed" : <i:speed>
		//									"frameData" : [ { ... } , { ... } ] 
		//					 "BackwardWalk": { ... }
		//					 "ForwardDash" : { ... }
		//					 "BackwardDash" : { ... } 
		//					 "Jump" :{ "count" : <i:numFrames>
		//							   "speed" : <i:speed>
		//							   "height" : <i: height>
		//							 }
		//					"BlockHigh" : { ... }
		//					"BlockLow"  : { ... }
		//

		return true;
	}
}