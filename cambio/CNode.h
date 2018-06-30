#pragma once
#include <vector>

template <class G>
class CNode
{
public:
	typedef typename G::N N;

	N m_x;
	N m_y;
	N m_data;
	N m_isla;
	N sector;
	std::vector<CNode*> m_relation;

	CNode(N x, N y, N data);
	~CNode();
};