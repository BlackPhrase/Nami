/// @file

#include <cstdio>
#include "CmdProcessor.hpp"
#include "CmdContainer.hpp"
#include "CmdArgs.hpp"

cCmdProcessor::cCmdProcessor(cCmdRegistry *apCmdContainer) : mpCmdContainer(apCmdContainer){}
cCmdProcessor::~cCmdProcessor() = default;

void cCmdProcessor::AddText(const tString &asText, Position aePos)
{
	switch(aePos)
	{
	case Insert:
		mCmdQue.emplace_front(asText);
		break;
	case Append:
		mCmdQue.emplace_back(asText);
		break;
	};
};

void cCmdProcessor::ExecText(const tString &asText)
{
	cCmdArgs CmdArgs(asText);
	
	auto pCmd{mpCmdContainer->Find(CmdArgs.GetByIndex(0))};
	
	if(pCmd)
	{
		pCmd->Exec(CmdArgs);
		return;
	};
	
	printf("Unknown command: \"%s\"\n", CmdArgs.GetByIndex(0));
};

void cCmdProcessor::Exec()
{
	// Empty? Then just leaving
	if(mCmdQue.empty())
		return;
	
	while(!mCmdQue.empty())
	{
		auto CurrentCmd{mCmdQue.front()};
		ExecText(CurrentCmd);
		mCmdQue.pop_front();
	};
};