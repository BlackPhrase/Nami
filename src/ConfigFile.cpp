/// @file

#include <iniparser.h>
#include "ConfigFile.hpp"

cConfigFile::cConfigFile() = default;

cConfigFile::cConfigFile(const tString &asPath)
{
	//if(!mpDict)
		//throw std::runtime_error("Can't load config file \"" + asPath + "\"!");
	
	LoadFromFile(asPath); // TODO
};

cConfigFile::~cConfigFile()
{
	if(mpDict)
		iniparser_freedict(mpDict);
};

bool cConfigFile::LoadFromFile(const tString &asPath)
{
	if(mpDict)
		iniparser_freedict(mpDict);
	
	mpDict = iniparser_load(asPath.c_str());
	
	if(!mpDict)
		return false;
	
	return true;
};

bool cConfigFile::SaveToFile(const tString &asPath)
{
	auto pFile{fopen(asPath.c_str(), "w")};
	
	if(!pFile)
		return false;
	
	iniparser_dump_ini(mpDict, pFile);
	fclose(pFile);
	
	return true;
};

void cConfigFile::SetString(const tString &asKey, const tString &asValue)
{
	iniparser_set(mpDict, asKey.c_str(), asValue.c_str());
};

const char *cConfigFile::GetString(const tString &asKey const tString &asDefVal) const
{
	return iniparser_getstring(mpDict, asKey.c_str(), asDefVal.c_str());
};

int cConfigFile::GetInt(const tString &asKey, int anDefVal) const
{
	return iniparser_getint(mpDict, asKey.c_str(), anDefVal);
};

float cConfigFile::GetFloat(const tString &asKey, float afDefVal) const
{
	return iniparser_getdouble(mpDict, asKey.c_str(), afDefVal);
};

bool cConfigFile::GetBool(const tString &asKey, bool abDefVal) const
{
	return iniparser_getboolean(mpDict, asKey.c_str(), abDefVal);
};