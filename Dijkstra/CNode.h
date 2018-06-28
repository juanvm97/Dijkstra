#pragma once
#include <vector>

template <class G>
class CNode
{
public:
	typedef typename G::Edge Edge;
	typedef typename G::N N;

	N m_data;
	N m_x;
	N m_y;
	std::vector<Edge*> m_edges;

	CNode(N data, N x, N y);
	void Print();
	~CNode();
};