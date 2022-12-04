// CMP201.2022 AX1.7 Pathfinding over DiGraphs
// Author William Kavanagh
// Partial Framework

// Solved by Sam Collier - 2100259

#include "Graph.h"

// digraph constructor.
// initialise size and vertices (a pointer to an array of graphVertex pointers)
// set all LLs to nullptrs, then use getAdjacencyList to add each edge to the adjacency list.
Graph::Graph(graphEdge edges[], int numEdges, int numVertices)
{
	// Assessed: 1 mark

	// Dummy values for initial compilation, remove.
	size = 0;
	vertices = new graphVertex*[1]();
}

// Builds a string representation of the graph showing the edges going from each vertex in the following form:
// e.g.: vertex 12 with edges to vertex 3 of weight 5 and vertex 13 of weight 1 would look like:
// "v12: 3 (w=5), 13 (w=1) 
// Notice the spaces, commas (not trailing). Also each vertex is on it's own line.
// Nothing should be printed by this method.
// hint: Use std::to_string(int val) to convert from integers to strings
std::string Graph::display()
{
	// Assessed: 1 mark
	return "";
}

// Use Dijkstra's algorithm to find the shortest path from start to end.
// returns a structure with the path length and a stack with all vertices on the path with the start on the top.
// You can assume all edge weights will be under 1000.
// pathInformation is defined at the top of Graph.h
// HINT:	pQueue.top() gets a reference to the first element, but does not remove it. 
//			pQueue.pop() removes the first element but does not get a reference to it.
//				.. so use both.
pathInformation Graph::dijkstra(int start, int end)
{
	// Assessed: 3 marks

	// Initial DSs, provided.
	std::map<int, int> distanceTo;	// maps from vertices to best distance found to start (start->start = 0)
	std::map<int, int> pathTaken;	// maps from vertices to last vertex visited as part of best distance found so far.
	std::map<int, bool> visited;	// maps from vertices to whether or not the vertex has been visited yet so we do not visit vertices multiple times.
	// priority queue of distances to vertices yet to visit alongside their index. DISTANCE FIRST, index second.
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> frontier;

	// TODO
	// Set initial distances to arbitrarily high value and set start distance to 0. 
	// Add start to frontier.
	

	// TODO
	// main loop:
	// while the frontier has vertices yet to visit.
	// get a reference to the vertex, if the vertex has been visited, continue
	// remove from frontier, set visited to true and iterate over all edges from the vertex in the adjacency list.
		// check if the distance via the visited vertex along the edge is smaller than the currently found shortest distance
			// update the distance and path maps if a new shorter path is found, add the edge vertex to the frontier with the new distance.
	

	// TODO
	// Create a return structure and store the length as the distance to the end.
	// Create an int stack and iterate backwards over the pathTo map, pushing onto the stack from end until start has been pushed.
	// Store the stack in the structure and return it.


	return pathInformation();
	
}

// Sample main included for testing purposes. Remove or commment out or [-1].
int main()
	{
	// small graph test
	std::cout << "=====\nSmaller graph test\n=====\n";
	graphEdge edges[] =
	{
		{0, 1, 7}, {1, 2, 2}, {1, 3, 3}, {2, 4, 5}, {3, 5, 4}, {3, 6, 2}, {4, 6, 1}, {6, 7, 3}, {6, 8, 6}, {7, 8, 2}
	};
	Graph g(edges, 10, 9);		// construct graph.

	// test display.
	std::cout << "Displaying graph from lecture 12B, should be of the form:\nv0: 1 (w=7)\nv1: 3 (w=3), 2 (w=2), ... etc\n~~~" << std::endl;
	std::cout << g.display();

	// disjktra test
	pathInformation pS = g.dijkstra(0, 8);
	std::cout << "~~~\nThe path from 0 to 8 should have a length of 17, we found: " << pS.length << std::endl;
	std::stack<int> pathToEight = pS.path;
	std::cout << "The path from 0 to 8 should visit vertices [0, 1, 3, 6, 7, 8], we found: [";
	while (!pathToEight.empty() && pathToEight.size() != 1)
	{
		std::cout << pathToEight.top() << ", ";
		pathToEight.pop();
	}
	std::cout << pathToEight.top() << "]" << std::endl;

	// medium graph test
	std::cout << "\n\n=====\nLarger graph test\n=====\n";
	graphEdge edges2[] =
	{
		{0, 1, 3}, {0, 2, 4}, {0, 3, 5}, {1, 4, 5}, {2, 4, 4}, {2, 5, 3}, {3, 5, 4},
		{4, 6, 1}, {4, 7, 4}, {4, 8, 7}, {5, 6, 8}, {5, 7, 5}, {5, 8, 2},
		{6, 9, 4}, {6, 10, 4}, {7, 10, 5}, {7, 15, 21}, {7, 11, 7}, {8, 11, 13}, {8, 12, 4},
		{9, 13, 6}, {10, 13, 7}, {11, 15, 2}, {12, 14, 2}, {13, 15, 12}, {14, 11, 3}
	};

	Graph g2(edges2, 26, 16);

	std::cout << "Displaying graph from lab sheet, should be of the form:\nv0: 3 (w=5), 2 (w=4), 1 (w=3)\n... etc\n~~~" << std::endl;
	std::cout << g2.display();
	pathInformation pS2 = g2.dijkstra(0, 15);

	std::cout << "~~~\nThe path from 0 to 15 should have a length of 20, we found: " << pS2.length << std::endl;
	std::stack<int> pathToFifteen = pS2.path;
	std::cout << "The path from 0 to 8 should visit vertices [0, 2, 5, 8, 12, 14, 11, 15], we found: [";
	while (!pathToFifteen.empty() && pathToFifteen.size() != 1)
	{
		std::cout << pathToFifteen.top() << ", ";
		pathToFifteen.pop();
	}
	std::cout << pathToFifteen.top() << "]" << std::endl;
	
	return 0;
}
