/// @file

#pragma once

struct iGameState;
class cDisplayController;
class cSoundController;
class cInputController;

class cGameController
{
public:
	cGameController(cDisplayController *apDisplayController, cSoundController *apSoundController, cInputController *apInputController)
		: mpDisplayController(apDisplayController), mpSoundController(apSoundController), mpInputController(apInputController){}
	~cGameController();
	
	void PushState(iGameState *apState);
	void PopState();
private:
	cDisplayController *mpDisplayController{nullptr};
	cSoundController *mpSoundController{nullptr};
	cInputController *mpInputController{nullptr};
	
	iGameState *mpCurrentState{nullptr};
};