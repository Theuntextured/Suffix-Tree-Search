#pragma once
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "Suffix.h"
#include "Edge.h"

class Edge;

class Node {
public:
	Node();
	Node(int word);
	Node(Edge* edge);
	void ProcessSuffix(Suffix s);
	Edge* getEdge(const char key) const;
	void addWords(std::vector<int>& out) const;
	void Search(Suffix& s, std::vector<int>& out) const;

	std::map<char, Edge*> edges;
	std::vector<int> words;
};

bool contains(const std::vector<int>& v, const int item, int& index);