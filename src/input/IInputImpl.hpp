/// @file

#pragma once

struct iInputImpl
{
	///
	virtual bool IsKeyDown(int anKey) const = 0;
	
	///
	virtual bool KeyWasPressed(int anKey) const = 0;
	
	///
	virtual bool KeyWasReleased(int anKey) const = 0;
};