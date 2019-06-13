/// @file

#pragma once

#include <list>
#include "CommonTypes.hpp"

class cActor;
using tActorList = std::list<cActor*>;

class cScene
{
public:
	cScene();
	~cScene();
	
	void Update(float afTimeStep);
	
	/// create a new actor on the scene
	/// @return pointer to newly created actor
	cActor *CreateActor(const tString &asName, const tWString &asDisplayName);
	
	///
	void DestroyActor(cActor *apActor);
	
	///
	cActor *GetActor(const tString &asName) const;
	
	///
	cActor *GetActor(int anIndex) const;
	
	///
	void SetBackground(const tString &asBackground){msBackground = asBackground;}
	
	///
	const tString &GetBackground() const {return msBackground;}
private:
	tActorList mlstActors;
	
	tString msBackground{""};
};