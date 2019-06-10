/// @file

#pragma once

#include <memory>

struct iGraphicsImpl;
struct iSoundImpl;
struct iInputImpl;
class cGameController;
class cSoundController;
class cInputController;
class cScene;

class cGame
{
public:
	cGame();
	~cGame();
	
	void Run();
private:
	bool Init();
	void Shutdown();
	
	void Cleanup();
	
	bool InitGraphics();
	bool InitSound();
	bool InitInput();
	bool InitScript();
	bool InitScene();
	
	std::unique_ptr<iGraphicsImpl> mpGraphicsImpl;
	std::unique_ptr<iSoundImpl> mpSoundImpl;
	std::unique_ptr<iInputImpl> mpInputImpl;
	
	std::unique_ptr<cGameController> mpGameController;
	std::unique_ptr<cSoundController> mpSoundController;
	std::unique_ptr<cInputController> mpInputController;
	
	std::unique_ptr<cScene> mpScene;
};