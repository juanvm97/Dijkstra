#include "stdafx.h"
//#include "CFun.h"
//#include "CSA.h"
//
#include "CHashTable.h"

template<class T, class F, class E, unsigned long z>
bool CHashTable<T, F, E, z>::ins(T x) {
	return m_ht[m_F(x) % z].ins(x);
}

template<class T, class F, class E, unsigned long z>
bool CHashTable<T, F, E, z>::rem(T x) {
	return m_ht[m_F(x) % z].rem(x);
}

template<class T, class F, class E, unsigned long z>
bool CHashTable<T, F, E, z>::find(T x) {
	return m_ht[m_F(x) % z].find(x);
}


