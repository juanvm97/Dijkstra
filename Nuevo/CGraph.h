#pragma once
#include "CNode.h"
#include <vector>

template <class N>
class CGraph
{
public:
	typedef CGraph<N> Self;
	typedef CNode<Self> Node;
	typedef N N;

	std::vector<Node*> m_nodes;

	CGraph();
	bool InsNode(N x, N y, N data);
	bool InsEdge(Node *A, Node *B);
	void Print();

	~CGraph();
};