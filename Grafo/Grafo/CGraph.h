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
	bool Revisado(bool * n, int & i, int size);
	void Marcado(Node * A, bool * n, int id_isla);
	void MarcarIslas();
	void PrintIslas();
	void Print();

	~CGraph();
};