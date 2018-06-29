#include "stdafx.h"
#include "CFun.h"
#include "CHashTable.h"

template<class T, unsigned long z >
T CFun<T, z>::operator()(T x) {
	return (x + 50) % z;
}