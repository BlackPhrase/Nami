/// @file

#pragma once

#include "IInputImpl.hpp"

class cInputSDL final : public iInputImpl
{
public:
	cInputSDL();
	~cInputSDL();
	
	bool IsKeyDown(int anKey) const override;
	bool KeyWasPressed(int anKey) const override;
	bool KeyWasReleased(int anKey) const override;
};