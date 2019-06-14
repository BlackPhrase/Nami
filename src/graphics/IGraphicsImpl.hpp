/// @file

#pragma once

struct iGraphicsImpl
{
	///
	virtual bool Init(int anWidth, int anHeight, bool abFullScreen) = 0;
};