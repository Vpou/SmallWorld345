// Small_World.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>

#include "Graph.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	Graph map = Graph(5);
	Region A = Region();
	Region B = Region();
	Region C = Region();
	Region D = Region();
	Region E = Region();

	Region arrayRegion[] = { A, B, C, D, E };

	char letter = 'A';
		
	for (int i = 0; i < 5; i++)
		cout << (char)(letter + i) << " has index " << arrayRegion[i].getIndex() << endl;

	map.createEdge(A,B);
	map.createEdge(A, C); 
	map.createEdge(D, B); 
	map.createEdge(E,A);
	map.createEdge(C, E);

	map.show();


return 0;
}
