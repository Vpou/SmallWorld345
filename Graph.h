#include "Region.h"

struct Node {

	Node(Region r);

	Region region;
	struct Node *next;
};

struct Vertex {
	struct Node *head;
};

class Graph {

public:
	Graph(int V);
	void createEdge(Region srcReg, Region destReg);

	void show();


private:
	int nbRegions;
	struct Vertex* map;

	Node* createNode(Region r);

};