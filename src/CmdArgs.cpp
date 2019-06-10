/// @file

#include "CmdArgs.hpp"

cCmdArgs::cCmdArgs(const tString &asText)
{
	msString = asText; // TODO
};

cCmdArgs::~cCmdArgs() = default;

int cCmdArgs::Containt()
{
};

const char *cCmdArgs::GetByIndex(int anIndex) const
{
	return msString.c_str(); // TODO
};

int cCmdArgs::GetCount() const
{
	return 0; // TODO
};

const char *cCmdArgs::ToString() const
{
	return msString.c_str(); // TODO
};