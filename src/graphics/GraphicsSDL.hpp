/// @file

#pragma once

#include "IGraphicsImpl.hpp"

using SDL_Window = struct SDL_Window;
using SDL_Renderer = struct SDL_Renderer;

class cGraphicsSDL final : public iGraphicsImpl
{
public:
	cGraphicsSDL();
	~cGraphicsSDL();
	
	bool Init(int anWidth, int anHeight, bool abFullScreen) override;
private:
	SDL_Window *mpWindow{nullptr};
	SDL_Renderer *mpRenderer{nullptr};
};