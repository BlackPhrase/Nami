/// @file

#pragma once

#include <string>
#include <deque>

//class cScriptCmd;
//using tScriptCmdQue = std::deque<cScriptCmd*>;

using tString = std::string;
using tStringDeque = std::deque<tString>;

class cCmdContainer;

class cCmdProcessor
{
public:
	cCmdProcessor(cCmdContainer *apCmdContainer);
	~cCmdProcessor();
	
	enum class Position
	{
		Insert,
		Append
	};
	
	/// Add the specified text to the command queue
	void AddText(const tString &asText, Position aePos);
	
	/// Execute the text right away
	void ExecText(const tString &asText);
	
	/// Execute all queued commands
	void Exec();
private:
	tStringDeque mCmdQue;
	
	cCmdContainer *mpCmdContainer{nullptr};
};