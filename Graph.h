#pragma once
#include <iostream>
#include <queue>			// for pQueue
#include <map>				// for unordered map
#include <string>
#include <stack>

struct pathInformation
{
	int length;
	std::stack<int> path;
};

// edges have a value between 2 indexed vertices.
struct graphEdge
{
	int from, to, weight;
};

// vertices are actually LL nodes with where they are going and with what weight, and a pointer
struct graphVertex
{
	int to, weight;
	graphVertex* next;
};

class Graph
{
public:
	// returns graphVertex.pushFront, does not update structure
	graphVertex* getAdjacencyList(int dest, int edge, graphVertex* start)
	{
		graphVertex* newVertex = new graphVertex;
		newVertex->to = dest;
		newVertex->weight = edge;
		newVertex->next = start;
		return newVertex;
	}

	graphVertex** vertices;		// adjacency list
	int size;					// number of nodes.

	// constructor, takes edge array and dimensions.
	Graph(graphEdge edges[], int numEdges, int numVertices);
	
	// destructor
	~Graph()
	{
		for (int i = 0; i < size; i++)
		{
			delete[] vertices[i];
		}
		delete[] vertices;
	}

	//bool addEdge(int start, int end, int weight);
	std::string display();
	pathInformation dijkstra(int start, int end);
};

