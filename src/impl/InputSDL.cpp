/// @file

#include "InputSDL.hpp"

cInputSDL::cInputSDL() = default;
cInputSDL::~cInputSDL() = default;

bool cInputSDL::IsKeyDown(int anKey) const
{
	return oldbuttons[anKey] == true && buttons[anKey] == true;
};

bool cInputSDL::KeyWasPressed(int anKey) const
{
	return oldbuttons[anKey] == false && buttons[anKey] == true;
};

bool cInputSDL::KeyWasReleased(int anKey) const
{
	return oldbuttons[anKey] == true && buttons[anKey] == false;
};