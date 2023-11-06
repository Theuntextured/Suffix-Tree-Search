#pragma once
#include "Suffix.h"
#include "Node.h"

class Node;

class Edge {
public:
	Edge(Suffix s);
	Edge(Edge* e, int prefixToRemove);
	void ProcessSuffix(Suffix s);
	void Search(Suffix& s, std::vector<int>& out) const;

	Node* target;
	std::string suffix;
};