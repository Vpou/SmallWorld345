#include "stdafx.h"
#include <iostream>

#include "Graph.h"

Node::Node(Region r) {
	region = r;
	next = NULL;
}

Graph::Graph(int v) {
	this->nbRegions = v;
	map = new Vertex[nbRegions];

	for (int i = 0; i < v-1; i++) {
		map[i].head = NULL;
	}
}

Node* Graph::createNode(Region r) {
	Node* newNode = new Node(r);
	newNode->region = r;
	newNode->next = NULL;

	return newNode;
}

void Graph::createEdge(Region src, Region dest) {

	int srcIdx = src.getIndex();
	int destIdx = dest.getIndex();

	Node* newNode = createNode(dest);
	newNode->next = map[srcIdx].head;
	map[srcIdx].head = newNode;

	newNode = createNode(src);
	newNode->next = map[destIdx].head;
	map[destIdx].head = newNode;
}

void Graph::show() {
	for (int v = 0; v < nbRegions; ++v)
	{
		Node* pointer = map[v].head;
		std::cout << "\n Adjacency list of Region index " << v << "\n head ";
		while (pointer)
		{
			std::cout << "-> " << pointer->region.getIndex();
			pointer = pointer->next;
		}
		std::cout << std::endl;
	}
}