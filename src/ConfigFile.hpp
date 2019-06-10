/// @file

#pragma once

#include "CommonTypes.hpp"

using dictionary = struct _dictionary_;

class CConfigFile
{
public:
	CConfigFile();
	CConfigFile(const tString &asPath);
	~CConfigFile();
	
	///
	bool LoadFromFile(const tString &asPath);
	
	///
	bool SaveToFile(const tString &asPath);
	
	///
	void SetString(const tString &asKey, const tString &asValue);
	
	///
	const char *GetString(const tString &asKey, const tString &asDefVal) const;
	
	///
	int GetString(const tString &asKey, int anDefVal) const;
	
	///
	float GetString(const tString &asKey, float afDefVal) const;
	
	///
	bool GetString(const tString &asKey, bool abDefVal) const;
private:
	dictionary *mpDict{nullptr};
};