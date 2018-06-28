#include "stdafx.h"
#include "CGraph.h"

template <class N, class E>
CGraph<N, E>::CGraph()
{
}

template<class N, class E>
bool CGraph<N, E>::FindNode(Node * A, int &i)
{
	Node *tem = m_nodes[0];
	for (i = 0; i < m_nodes.size() && tem != A; i++)
		tem = m_nodes[i];
	return ((tem != NULL) && (tem == A));;
}

template<class N, class E>
bool CGraph<N, E>::InsNode(N data, N x, N y)
{
	m_nodes.push_back(new Node(data, x, y));
	return true;
}

template<class N, class E>
bool CGraph<N, E>::InsEdge(Node * A, Node * B, bool d)
{
	Edge *tem = new Edge(A, B, d);
	A->m_edges.push_back(tem);
	B->m_edges.push_back(tem);

	return true;
}

template<class N, class E>
bool CGraph<N, E>::InsEdge(int A, int B, bool d)
{
	Edge *tem = new Edge(m_nodes[A - 1], m_nodes[B - 1], d);
	m_nodes[A-1]->m_edges.push_back(tem);
	m_nodes[B-1]->m_edges.push_back(tem);

	return true;
}

template<class N, class E>
void CGraph<N, E>::Print()
{
	for (int i = 0; i < m_nodes.size(); i++)
	{
		(*m_nodes[i]).Print();
		cout << " " << m_nodes[i]->m_data << " ->";
		for (int j = 0; j < m_nodes[i]->m_edges.size(); j++)
		{
			if (!m_nodes[i]->m_edges[j]->m_direc)// && (m_nodes[i] == m_nodes[i]->m_edges[j]->m_nodes[0])
				cout << " |" << m_nodes[i]->m_edges[j]->m_nodes[0]->m_data << " <-> " << m_nodes[i]->m_edges[j]->m_nodes[1]->m_data << "|";
			else if (m_nodes[i] == m_nodes[i]->m_edges[j]->m_nodes[0])
				cout << " |" << m_nodes[i]->m_edges[j]->m_nodes[0]->m_data << " --> " << m_nodes[i]->m_edges[j]->m_nodes[1]->m_data << "|";
		}
		cout << endl;
	}
}

template<class N, class E>
double CGraph<N, E>::DEuclidiana(N A, N B)
{
	return sqrt(pow(m_nodes[B-1]->m_x - m_nodes[A - 1]->m_x, 2) + pow(m_nodes[B - 1]->m_y - m_nodes[A - 1]->m_y, 2));
}

template<class N, class E>
bool CGraph<N, E>::Dijkstra(N A, N B)
{
	vector<Node*> recorrido;
	Node* next;
	bool *pas = new bool[m_nodes.size()];
	double dis = DEuclidiana(A, B);
	double dtem = dis, t;
	recorrido.push_back(m_nodes[A - 1]);

	while (recorrido[0]->m_data != B)
	{
		next = NULL;
		for (int i = 0; i < recorrido[0]->m_edges.size(); i++)
		{
			if (recorrido[0]->m_edges[i]->m_nodes[0] != recorrido[0])
			{
				t = DEuclidiana(recorrido[0]->m_edges[i]->m_nodes[0]->m_data, B);
			}
			else
			{
				t = DEuclidiana(recorrido[0]->m_edges[i]->m_nodes[1]->m_data, B);
			}
			if (t < dtem)
			{
				dtem = t;
				if (recorrido[0]->m_edges[i]->m_nodes[0] != recorrido[0])
					next = recorrido[0]->m_edges[i]->m_nodes[0];
				else
					next = recorrido[0]->m_edges[i]->m_nodes[1];
			}
		}
		if ((next) && (dtem < dis))
		{
			recorrido.insert(recorrido.begin(), next);
			dis = dtem;
		}
		else
			break;
	}

	if (dis == 0)
	{
		for (int i = 0; i < recorrido.size(); i++)
			cout << "re " << recorrido[i]->m_data << endl;
		return true;
	}

	return false;
}

template <class N, class E>
CGraph<N, E>::~CGraph()
{
}

template class CGraph<int, int>;