#pragma once

#include <set>

template<class T, class F, class E, unsigned long z>
struct CHashTable {
//	typedef CHashTable<T,F,E,z> Self;
//	typedef CSA<Self> E;
//	typedef CFun<Self> F;
//	typedef z z;
	


	E m_ht[z];
	F m_F;
	bool ins(T x);
	bool rem(T x);
	bool find(T x);
};
