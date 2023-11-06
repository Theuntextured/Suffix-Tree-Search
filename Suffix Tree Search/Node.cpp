#include "Node.h"

Node::Node()
{

}

Node::Node(int word)
{
	words.push_back(word);
}

Node::Node(Edge* edge)
{
	edges[edge->suffix[0]] = edge;
}

void Node::ProcessSuffix(Suffix s)
{
	if (s.suffix.size() == 0) {
		words.push_back(s.index);
		return;
	}
	auto c = s.suffix[0];
	Edge* targetEdge = edges[c];
	if (targetEdge) {
		targetEdge->ProcessSuffix(s);
	}
	else {
		targetEdge = new Edge(s);
		edges[c] = targetEdge;
	}
}

Edge* Node::getEdge(const char key) const
{
	return edges.at(key);
}

bool contains(const std::vector<int>& v, const int item, int& index) {
	if (v.empty()) {
		index = 0;
		return false;
	}
	if (item < v[0] || item > v.back()) {
		index = item < v[0] ? 0 : v.size();
		return false;
	}
	int min = 0;
	int max = v.size() - 1;
	int current = max / 2;
	while (max - min > 1) {
		if (v[current] == item) {
			index = current;
			return true;
		}
		(v[current] > item ? max : min) = current;
		current = (min + max) / 2;
	}

	index = max;
	return v[min] == item || v[max] == item;
}

void Node::addWords(std::vector<int>& out) const
{
	for (auto i : words) {
		int k = -1;
		if(!contains(out, i, k)) out.emplace(out.begin() + k, i);
	}
	for (auto k : edges) k.second->target->addWords(out);
}

void Node::Search(Suffix& s, std::vector<int>& out) const
{
	if (s.suffix.size() == 0) {
		addWords(out);
		return;
	}
	Edge* targetEdge = nullptr;
	if (edges.count(s.suffix[0])) targetEdge = edges.at(s.suffix[0]);
	if (targetEdge) targetEdge->Search(s, out);
}

