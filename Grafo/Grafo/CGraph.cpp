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
bool CGraph<N>::Revisado(bool * n, int & i, int size)
{
	while (i<size)
	{
		if (n[i] == 0)
			return true;
		i++;
	}

	return false;
}

template<class N>
void CGraph<N>::Marcado(Node *A, bool *n, int id_isla)
{
	n[A->m_data - 1] = 1;
	A->m_isla = id_isla;
	for (int i = 0; i < A->m_relation.size(); i++)
	{
		if (A->m_relation[i]->m_isla == -1)
		{
			n[A->m_relation[i]->m_data - 1] = 1;
			A->m_relation[i]->m_isla = id_isla;
			Marcado(A->m_relation[i], n, id_isla);
		}
	}
}

template<class N>
void CGraph<N>::MarcarIslas()
{
	int i = 0;
	int id_isla = 1;
	int size = m_nodes.size();
	bool *n;
	n = new bool[size];
	
	for (int j = 0; j < size; j++)
		n[j] = 0;

	while (Revisado(n, i, size))
	{
		cout << "i es: " << i << endl;
		n[i] = 1;
		m_nodes[i]->m_isla = id_isla;

		Marcado(m_nodes[i], n, id_isla);
		id_isla++;
	}
}

template<class N>
void CGraph<N>::PrintIslas()
{
	for (int i = 0; i < m_nodes.size(); i++)
	{
		cout << m_nodes[i]->m_data << " i: " << m_nodes[i]->m_isla << endl;
	}
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