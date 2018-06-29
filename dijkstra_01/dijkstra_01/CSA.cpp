#include "stdafx.h"
#include "CSA.h"
#include "CHashTable.h"

template<class T>
bool CSA<T>::ins(T x) {
	set.insert(x);
	return 1;
}

template<class T>
bool CSA<T>::rem(T x) {
	set.erase(x);
	return 1;
}

template<class T>
bool CSA<T>::find(T x) {
	if (set.find(x) != set.end())
		return true;
	else
		return false;
}
