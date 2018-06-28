#pragma once

template <class G>
class CEdge
{
public:
	typedef typename G::Node Node;
	typedef typename G::E E;

	Node *m_nodes[2];
	bool m_direc;

	CEdge();
	CEdge(Node *A, Node *B, bool direc);
	void Print();
	~CEdge();
};

