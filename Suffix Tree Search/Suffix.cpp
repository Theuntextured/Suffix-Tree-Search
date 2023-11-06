#include "Suffix.h"

#define endChar "$"

Suffix::Suffix(std::string str, int index)
{
	suffix = str + endChar;;
	this->index = index;
}

Suffix::Suffix(std::string str)
{
	suffix = str;
	this->index = -1;
}

void Suffix::Shrink(int amount)
{
	suffix.erase(suffix.begin(), suffix.begin() + amount);
}

std::string Suffix::getCommonPrefix(std::string& other) const
{
	int j = min(suffix.size(), other.size());
	std::string out;
	for (int i = 0; i < j; ++i) {
		if (suffix[i] == other[i]) out += suffix[i];
		else return out;
	}
	return out;
}
