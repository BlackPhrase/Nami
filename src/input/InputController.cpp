/// @file

#include "InputController.hpp"

//cInputController::cInputController(iInputImpl *apImpl) : mpImpl(apImpl){}
cInputController::~cInputController() = default;

bool cInputController::IsKeyDown(int anKey) const
{
	return mpImpl->IsKeyDown(anKey);
};

bool cInputController::AnyKeyDown() const
{
	return mpImpl->AnyKeyDown();
};

bool cInputController::KeyWasPressed(int anKey) const
{
	return mpImpl->KeyWasPressed(anKey);
};

bool cInputController::KeyWasReleased(int anKey) const
{
	return mpImpl->KeyWasReleased(anKey);
};