#pragma once
#include <string>

#define min(a,b) (a > b ? b : a)

class Suffix
{
public:
	std::string suffix;
	int index;

	Suffix(std::string str, int index);
	Suffix(std::string str);
	void Shrink(int amount = 1);
	std::string getCommonPrefix(std::string& other) const;
};

