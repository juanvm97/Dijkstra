// Dijkstra.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "CGraph.h"

int main()
{
	CGraph<int, int> g;
	
	ifstream archivo;
	archivo.open("nodes_20_graph_3.dat", ios::in);
	string texto, d1, d2;
	if (archivo.fail())
	{
		cout << "no" << endl;
		exit(1);
	}
	int i;
	getline(archivo, texto);
	for(int j=1; j<=20 && !archivo.eof(); j++)
	{
		d1 = "";
		d2 = "";
		getline(archivo, texto);
		for(i=0; i<texto.size() && texto[i] != ' '; i++)
			d1 += texto[i];
		i++;
		for (; i<texto.size(); i++)
			d2 += texto[i];

		g.InsNode(j, stoi(d1), stoi(d2));
	}

	getline(archivo, texto);
	for (int j = 1; j <= 39 && !archivo.eof(); j++)
	{
		d1 = "";
		d2 = "";
		getline(archivo, texto);
		for (i = 0; i<texto.size() && texto[i] != ' '; i++)
			d1 += texto[i];
		i++;
		for (; i<texto.size(); i++)
			d2 += texto[i];

		g.InsEdge(stoi(d1), stoi(d2));
	}

	archivo.close();

	g.Dijkstra(3, 17);
	
	g.Print();

    return 0;
}

