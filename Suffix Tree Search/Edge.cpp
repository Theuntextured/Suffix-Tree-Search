#include "Edge.h"

Edge::Edge(Suffix s)
{
	suffix = s.suffix;
	target = new Node(s.index);
}

Edge::Edge(Edge* e, int prefixToRemove)
{
	target = e->target;
	suffix = e->suffix;
	for (int i = 0; i < prefixToRemove; ++i) suffix.erase(suffix.begin());
}

void Edge::ProcessSuffix(Suffix s)
{
	auto newSuffix = s.getCommonPrefix(suffix);
	if (suffix == newSuffix) {
		s.Shrink(suffix.size());
		target->ProcessSuffix(s);
		return;
	}

	target = new Node(new Edge(this, newSuffix.size()));
	suffix = newSuffix;
	s.Shrink(suffix.size());

	target->ProcessSuffix(s);
}

void Edge::Search(Suffix& s, std::vector<int>& out) const
{
	auto t = min(suffix.size(), s.suffix.size());
	if (std::string(s.suffix.begin(), s.suffix.begin() + t) == std::string(suffix.begin(), suffix.begin() + t)) {
		s.Shrink(t);
		target->Search(s, out);
	}
}