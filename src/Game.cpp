/// @file

#include <cstdlib>
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "GraphicsSDL.hpp"
#include "SDLSound.hpp"
#include "InputSDL.hpp"

#include "GameController.hpp"
#include "SoundController.hpp"
#include "InputController.hpp"

#include "Scene.hpp"

constexpr auto WINDOW_WIDTH{1280};
constexpr auto WINDOW_HEIGHT{600};
constexpr auto WINDOW_FULLSCREEN{false};

constexpr auto SOUND_FREQUENCY{44100}; //22050
constexpr auto SOUND_CHANNELS{2};
constexpr auto SOUND_SAMPLESIZE{4096};

cGame::cGame() = default;
cGame::~cGame() = default;

void cGame::Run()
{
	if(!Init()) // TODO: Init is private, genius!
		return;
	
	mpSoundController->StartMusic("Zweitestock.mp3"); // TODO: temp
	
	SDL_Event SDLEvent;
	
	bool bQuit{false};
	
	while(!bQuit)
	{
		// Handle events in queue
		while(SDL_PollEvent(&SDLEvent))
		{
			switch(SDLEvent.type)
			{
			case SDL_QUIT:
				bQuit = true;
				break;
			case SDL_KEYDOWN:
				switch(SDLEvent.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					bQuit = true;
					break;
				default:
					//mpInputEventDispatcher->KeyDown(SDLKeyToInternalKey(SDLEvent.key.keysym.sym));
					break;
				};
			case SDL_MOUSEBUTTONDOWN:
				//mpInputEventDispatcher->MouseButtonDown();
				break;
			default:
				break;
			};
		};
		
		//mpDisplayController->ClearScreen();
		
		// Clear screen
		SDL_RenderClear(gpRenderer);
		
		//RenderTexture(image, gpRenderer, x, y);
		//mpScene->Draw();
		
		// Update screen
		SDL_RenderPresent(gpRenderer);
	};
};

bool cGame::Init()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL2 initialization failed! (" << SDL_GetError() << ")" << std::endl;
		return false;
	};
	
	if(!InitGraphics())
		return false;
	
	if(!InitSound())
		return false;
	
	if(!InitInput())
		return false;
	
	if(!InitScript())
		return false;
	
	if(!InitScene())
		return false;
	
	mpGameController = std::make_unique<cGameController>(nullptr, mpSoundController.get(), mpInputController.get());
	
	return true;
};

void cGame::Shutdown()
{
	Cleanup();
};

void cGame::Cleanup()
{
	if(IMG_WasInit())
		IMG_Quit();
	
	if(SDL_WasInit())
		SDL_Quit();
};

bool cGame::InitGraphics()
{
	mpGraphicsImpl = std::make_unique<cGraphicsSDL>();
	
	if(!mpGraphicsImpl->Init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FULLSCREEN))
		return false;
	
	int nImageFlags{IMG_INIT_PNG | IMG_INIT_BMP};
	
	if(!(IMG_Init(nImageFlags) & nImageFlags))
	{
		std::cout << "SDL2_image initialization failed! (" << IMG_GetError() << ")" << std::endl; 
		return false;
	};
	
	gpScreenSurface = SDL_GetWindowSurface(gpWindow);
	
	return true;
};

bool cGame::InitSound()
{
	mpSoundImpl = std::make_unique<cSoundSDL>();
	mpSoundController = std::make_unique<cSoundController>(mpSoundImpl.get());
	
	if(!mpSoundImpl->Init(SOUND_FREQUENCY, SOUND_CHANNELS, SOUND_SAMPLESIZE))
		return false;
	
	return true;
};

bool cGame::InitInput()
{
	mpInputImpl = std::make_unique<cInputSDL>();
	mpInputController = std::make_unique<cInputController>(mpInputImpl.get());
	
	return true;
};

bool cGame::InitScript()
{
	// TODO
	return true;
};

bool cGame::InitScene()
{
	mpScene = std::make_unique<cScene>();
	return true;
};