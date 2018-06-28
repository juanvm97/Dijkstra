#pragma once
#include "CNode.h"
#include "CEdge.h"
#include <vector>

template <class N, class E>
class CGraph
{
public:
	typedef CGraph<N, E> Self;
	typedef CNode<Self> Node;
	typedef CEdge<Self> Edge;
	typedef N N;
	typedef E E;

	std::vector<Node*> m_nodes;

	CGraph();
	bool FindNode(Node *A, int &i);
	bool InsNode(N data, N x, N y);
	bool InsEdge(Node *A, Node *B, bool d=0);
	bool InsEdge(int A, int B, bool d = 0);
	void Print();
	double DEuclidiana(N A, N B);
	bool Dijkstra(N A, N B);
	~CGraph();
};

