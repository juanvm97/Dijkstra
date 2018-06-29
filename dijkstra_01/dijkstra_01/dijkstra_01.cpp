
#include "stdafx.h"

template<class T, class F, class E, unsigned long z>
class CHashTable {
public:
	E m_ht[z];
	F m_F;
	bool ins(T x) {
		return m_ht[m_F(x) % z].ins(x);
	}
	bool rem(T x) {
		return m_ht[m_F(x) % z].rem(x);
	}
	bool find(T x) {
		return m_ht[m_F(x) % z].find(x);
	}


};
/*
template<class T>
class CSA {
public:
	std::set<T> set;
	bool ins(T x) {
		set.insert(x);
		return 1;
	}
	bool rem(T x) {
		set.erase(x);
		return 1;
	}

	bool find(T x) {
		if (set.find(x) != set.end())
			return true;
		else
			return false;
	}


};*/

template<class T> 
class CSA{
public:
	set<T> set;
	bool find(T x){
		if(set.find(x) != set.end())
			return true;
		else 
			return false;
	}
	
	
	bool ins(T x){
		if(find(x))
			return 0;
		else{
		set.insert(x);
		return 1;}
	}
	bool rem(T x){
		if(!find(x))
			return 0;
		else{
		set.erase(x);
		return 1;}
	}
	
	
	
};

template<class T, unsigned long z >
class CFun {
public:
	T operator()(T x) {
		return (x + 50) % z;
	}
};


void Cargar(CGraph<int> &g)
{
	ifstream archivo;
	archivo.open("nodes_15_graph_1.dat", ios::in);
	string texto, d1, d2;
	if (archivo.fail())
	{
		cout << "no" << endl;
		exit(1);
	}
	int i;
	getline(archivo, texto);
	for (int j = 1; j <= 15 && !archivo.eof(); j++)
	{
		d1 = "";
		d2 = "";
		getline(archivo, texto);
		for (i = 0; i<texto.size() && texto[i] != ' '; i++)
			d1 += texto[i];
		i++;
		for (; i<texto.size(); i++)
			d2 += texto[i];

		g.InsNode(stoi(d1), stoi(d2), j);
	}

	getline(archivo, texto);
	for (int j = 1; j <= 21 && !archivo.eof(); j++)
	{
		d1 = "";
		d2 = "";
		getline(archivo, texto);
		for (i = 0; i<texto.size() && texto[i] != ' '; i++)
			d1 += texto[i];
		i++;
		for (; i<texto.size(); i++)
			d2 += texto[i];

		g.InsEdge(g.m_nodes[stoi(d1) - 1], g.m_nodes[stoi(d2) - 1]);
	}

	archivo.close();

}

int main()
{
	CHashTable<int, CFun<int, 4>, CSA<int>, 4> H;
	H.ins(1);
	H.ins(2);
	H.ins(3);
	H.ins(4);
	H.ins(5);
	H.ins(6);
	H.ins(7);
	H.ins(8);
	H.ins(9);
	H.ins(10);
	H.ins(11);
	H.ins(12);

	cout<<H.find(4)<<endl;
	cout << H.find(12) << endl;
	cout << H.rem(12) << endl;
	cout << H.find(12) << endl;
	cout << H.find(13) << endl;
	CGraph<int> g;
	
	Cargar(g);
	
	g.Print();
	
    return 0;
}

