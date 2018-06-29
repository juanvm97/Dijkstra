#include "stdafx.h"
#include "CNode.h"
#include "CGraph.h"

template<class G>
CNode<G>::CNode(N x, N y, N data)
{
	m_x = x;
	m_y = y;
	m_data = data;
}

template <class G>
CNode<G>::~CNode()
{
}

template class CNode<CGraph<int>>;



