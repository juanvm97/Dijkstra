#pragma once

template<class T>

struct CSA {
	std::set<T> set;
	bool ins(T x);
	bool rem(T x);
	bool find(T x);

};