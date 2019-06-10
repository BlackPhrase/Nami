/// @file

#include "GraphicsSDL.hpp"

cGraphicsSDL::cGraphicsSDL()
{
	if(!TTF_Init())
	{
		std::cout << "SDL2_ttf initialization failed! (" << TTF_GetError() << ")" << std::endl;
		//TTF_Quit();
		//return false; // TODO
	};
};

cGraphicsSDL::~cGraphicsSDL()
{
	if(TTF_WasInit())
		TTF_Quit();
	
	SDL_DestroyRenderer(mpRenderer);
	SDL_DestroyWindow(mpWindow);
};

bool cGraphicsSDL::Init(int anWidth, int anHeight, bool abFullScreen)
{
	int nWindowFlags{SDL_WINDOW_SHOWN};
	
	if(nWindowFlags)
		nWindowFlags |= SDL_WINDOW_FULLSCREEN;
	
	mpWindow = SDL_CreateWindow("TiefBlau Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, anWidth, anHeight, nWindowFlags);
	
	if(!mpWindow)
	{
		std::cout << "SDL2 window creation failed! (" << SDL_GetError() << ")" << std::endl; 
		SDL_Quit();
		return false;
	};
	
	mpRenderer = SDL_CreateRenderer(mpWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	if(!mpRenderer)
	{
		SDL_DestroyWindow(mpWindow);
		std::cout << "SDL2 renderer creation failed! (" << SDL_GetError() << ")" << std::endl; 
		SDL_Quit();
		return false;
	};
	
	return true;
};