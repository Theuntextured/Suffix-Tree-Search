#include "SearchTree.h"

void SearchTree::generateTree(const std::vector<std::string>& words, const std::vector<char>& wordDividers)
{
	if (root) delete root;

	dividers = wordDividers;
	root = new Node();

	this->words = words;
	int breakPoint = INT_MAX;

	for (int i = 0; i < words.size(); ++i) {
		auto p = getSubstrings(words[i]);
		for(auto sub : p)
		{
			Suffix s(sub, i);
			while (s.suffix.size() > 0) {
				root->ProcessSuffix(s);
				s.Shrink();
			}
		}
	}
}

std::vector<std::string> SearchTree::getSubstrings(std::string s) const
{
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	std::string tmp;
	std::vector< std::string> out;
	for (auto i : s) {
		if (std::count(dividers.begin(), dividers.end(), i)) {
			out.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += i;
		}
	}
	if(tmp != "") out.push_back(tmp);
	return out;
}

std::vector<std::string> SearchTree::Search(std::string substring) const
{
	std::vector<int> indices;
	std::vector<int> finalIndices;
	bool skipUnion = true;
	auto subs = getSubstrings(substring);
	for (auto i : subs) {
		Suffix suf(i);
		root->Search(suf, indices);
		if (!skipUnion) {
			finalIndices = Intersection(finalIndices, indices);
		}
		else {
			finalIndices = indices;
		}
		skipUnion = false;
	}

	std::vector<std::string> out;
	for (auto i : finalIndices) out.push_back(words[i]);
	return out;
}

std::vector<int> Intersection(const std::vector<int>& a, const std::vector<int>& b)
{
	std::vector<int> out;
	for (auto i : a) {
		int tmp;
		if (contains(b, i, tmp)) {
			out.push_back(i);
		}
	}
	return out;
}
