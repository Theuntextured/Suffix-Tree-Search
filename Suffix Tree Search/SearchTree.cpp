#include "SearchTree.h"

void SearchTree::generateTree(const std::vector<std::string>& words, const std::vector<char>& wordDividers)
{
	if (root) delete root;

	dividers = wordDividers;
	root = new Node();

	this->words = words;
	int breakPoint = INT_MAX;

	for (int i = 0; i < words.size(); ++i) {
		auto p = words[i];
		while(p.size())
		{
			breakPoint = p.size() - 1;
			for (auto d : dividers) {
				breakPoint = min(breakPoint, p.find_first_of(d));
			}

			Suffix s(std::string(p.begin(), p.begin() + breakPoint + 1), i);
			while (s.suffix.size() > 0) {
				root->ProcessSuffix(s);
				s.Shrink();
			}
			p.erase(p.begin(), p.begin() + breakPoint + 1);
		}
	}
}

std::vector<std::string> SearchTree::getSubstrings(std::string s)
{
	//todo and replace the subdivision method.
}

std::vector<std::string> SearchTree::Search(std::string substring) const
{
	std::vector<int> indices;
	std::vector<int> finalIndices;
	bool skipUnion = true;
	while (substring.size()) {
		int breakPoint = substring.size();
		for (auto d : dividers) {
			breakPoint = min(breakPoint, substring.find_first_of(d));
		}

		Suffix suf(std::string(substring.begin(), substring.begin() + breakPoint));

		std::cout << "Searching for: \"" << suf.suffix << "\"\n";
		
		root->Search(suf, indices);
		if (!skipUnion) {
			finalIndices = Intersection(finalIndices, indices);
		}
		else {
			finalIndices = indices;
		}
		skipUnion = false;

		substring.erase(substring.begin(), substring.begin() + min(substring.size(), breakPoint + 1));
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
