/// @file

#pragma once

#include "CommonTypes.hpp"

class cActor
{
public:
	cActor() : msName("Kid"), msDisplayName(L"UI_ACTOR_KID"), msImage(""){}
	cActor(const tWString &asName, const tString &asImage);
	~cActor();
	
	/// Update the actor
	void Update();
	
	/// Set a new display name
	void SetDisplayName(const tWString &asName){msDisplayName = asName;}
	
	/// @return current display name
	const tWString &GetDisplayName() const {return msDisplayName;}
	
	/// Set a new internal name
	void SetName(const tString &asName){msName = asName;}
	
	/// @return current internal name
	const tString &GetName() const {return msName;}
	
	/// Set a new image set representing the actor
	void SetImage(const tString &asImage){msImage = asImage;}
	
	/// @return current image set used
	const tString &GetImage() const {return msImage;}
	
	/// Set a new pose
	void SetPose(const tString &asPose){msPose = asPose;}
	
	/// @return current pose
	const tString &GetPose() const {return msPose;}
	
	///
	void SetPosition(const tVec3n &avPos){mvPos = avPos;}
	
	///
	const tVec3n &GetPosition() const {return mvPos;}
private:
	tWString msDisplayName{L""}; ///< Display name (supports wide characters)
	tString msName{""}; ///< Internal name
	tString msImage{""}; ///< Current image
	tString msPose{""}; ///< Current pose type
	
	tVec3n mvPos{0};
};