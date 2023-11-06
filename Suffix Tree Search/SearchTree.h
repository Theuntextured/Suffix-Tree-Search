#pragma once
#include "Node.h"
#include <vector>
#include <algorithm>



struct SearchTree
{
public:
	void generateTree(const std::vector<std::string>& words, const std::vector<char>& wordDividers);
	std::vector<std::string> getSubstrings(std::string s) const;
	
	std::vector<std::string> Search(std::string substring) const;
private:
	Node* root;
	std::vector<char> dividers;
	std::vector<std::string> words;
};

std::vector<int> Intersection(const std::vector<int>& a, const std::vector<int>& b);