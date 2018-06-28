#include "stdafx.h"
#include "CNode.h"
#include "CGraph.h"

template<class G>
CNode<G>::CNode(N data, N x, N y)
{
	m_data = data;
	m_x = x;
	m_y = y;
}

template<class G>
void CNode<G>::Print()
{
	cout << m_x << " " << m_y;
}

template <class G>
CNode<G>::~CNode()
{
}

template class CNode<CGraph<int, int>>;