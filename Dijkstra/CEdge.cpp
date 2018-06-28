#include "stdafx.h"
#include "CEdge.h"
#include "CGraph.h"

template<class G>
CEdge<G>::CEdge()
{
}

template <class G>
CEdge<G>::CEdge(Node *A, Node *B, bool direc)
{
	m_nodes[0] = A;
	m_nodes[1] = B;
	m_direc = direc;
}

template<class G>
void CEdge<G>::Print()
{
	cout << "0" << endl;
}

template <class G>
CEdge<G>::~CEdge()
{
}

template class CEdge<CGraph<int, int>>;