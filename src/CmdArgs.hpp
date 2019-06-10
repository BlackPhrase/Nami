/// @file
/// @brief command arguments

#pragma once

#include <string>

class cCmdArgs
{
public:
	cCmdArgs(const tString &asArgs);
	//CCmdArgs(int argc, char *argv);
	~cCmdArgs();
	
	///
	int Contains(const tString &asArg) const; // TODO: bool?
	
	///
	const tString &GetByIndex(unsigned anIndex) const;
	
	///
	unsigned GetCount() const;
	
	///
	const tString &ToString() const;
private:
	std::string msString{""};
};