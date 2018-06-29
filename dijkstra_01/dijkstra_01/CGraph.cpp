#include "stdafx.h"
#include "CGraph.h"

template <class N>
CGraph<N>::CGraph()
{
}

template<class N>
bool CGraph<N>::InsNode(N x, N y, N data)
{
	m_nodes.push_back(new Node(x, y, data));
	return true;
}

template<class N>
bool CGraph<N>::InsEdge(Node * A, Node * B)
{
	A->m_relation.push_back(B);
	B->m_relation.push_back(A);

	return true;
}

template<class N>
void CGraph<N>::Print()
{
	for (int i = 0; i < m_nodes.size(); i++)
	{
		cout << " " << m_nodes[i]->m_data << " ->";
		for (int j = 0; j < m_nodes[i]->m_relation.size(); j++)
		{
			cout << " | -> " << m_nodes[i]->m_relation[j]->m_data << "|";
		}
		cout << endl;
	}
}

template <class N>
CGraph<N>::~CGraph()
{
}

template class CGraph<int>;