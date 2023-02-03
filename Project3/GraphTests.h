#pragma once

#include <cassert>
#include <iostream>

#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include "Sequence.h"

using namespace std;



class unittest_Graph {
private:
	static void test_append() {
		Graph<int> graph = Graph<int>();

		Vertex<int> v1 = Vertex<int>();
		Vertex<int> v2 = Vertex<int>();
		Vertex<int> v3 = Vertex<int>();

		Edge<int> edge1 = Edge<int>(0, 1, 10);
		Edge<int> edge2 = Edge<int>(1, 2, 20);

		v1.appendOutgoingEdge(edge1);
		v2.appendIncomingEdge(edge1);
		v2.appendOutgoingEdge(edge2);
		v3.appendIncomingEdge(edge2);

		graph.appendVertex(v1);
		graph.appendVertex(v2);
		graph.appendVertex(v3);

		assert(graph.getSize() == 3);

		for (int i = 0; i < graph.getSize(); ++i) {
			if (i != 1) {
				assert(graph.get(i).getIncomingIncidenceArrayLength() + graph.get(i).getOutgoingIncidenceArrayLength() == 1);
			}
			else {
				assert(graph.get(i).getIncomingIncidenceArrayLength() + graph.get(i).getOutgoingIncidenceArrayLength() == 2);
			}
		}

		Edge<int> edge4 = Edge<int>(0, 2, 100);

		graph.appendEdge(edge4);

		assert(graph.get(0).getOutgoingIncidenceArrayLength() == 2);
		assert(graph.get(2).getIncomingIncidenceArrayLength() == 2);
	}

	static void test_dijkstra() {
		Edge<int> edge1 = Edge<int>(0, 2, 9);
		Edge<int> edge2 = Edge<int>(0, 5, 14);
		Edge<int> edge3 = Edge<int>(0, 1, 7);

		Edge<int> edge4 = Edge<int>(1, 2, 10);
		Edge<int> edge5 = Edge<int>(1, 3, 15);

		Edge<int> edge6 = Edge<int>(2, 5, 2);
		Edge<int> edge7 = Edge<int>(2, 3, 11);

		Edge<int> edge8 = Edge<int>(3, 4, 6);

		Edge<int> edge9 = Edge<int>(5, 4, 9);


		Vertex<int> vertex1 = Vertex<int>();
		vertex1.appendOutgoingEdge(edge1);
		vertex1.appendOutgoingEdge(edge2);
		vertex1.appendOutgoingEdge(edge3);

		Vertex<int> vertex2 = Vertex<int>();
		vertex2.appendOutgoingEdge(edge4);
		vertex2.appendOutgoingEdge(edge5);

		edge3.swapVertices();
		vertex2.appendIncomingEdge(edge3);

		Vertex<int> vertex3 = Vertex<int>();
		vertex3.appendOutgoingEdge(edge6);
		vertex3.appendOutgoingEdge(edge7);

		edge1.swapVertices();
		vertex3.appendIncomingEdge(edge1);
		edge4.swapVertices();
		vertex3.appendIncomingEdge(edge4);

		Vertex<int> vertex4 = Vertex<int>();
		vertex4.appendOutgoingEdge(edge8);

		edge5.swapVertices();
		vertex4.appendIncomingEdge(edge5);
		edge7.swapVertices();
		vertex4.appendIncomingEdge(edge7);

		Vertex<int> vertex5 = Vertex<int>();
		edge8.swapVertices();
		vertex5.appendIncomingEdge(edge8);
		vertex5.appendIncomingEdge(edge9);

		Vertex<int> vertex6 = Vertex<int>();
		vertex6.appendOutgoingEdge(edge9);

		edge6.swapVertices();
		vertex6.appendIncomingEdge(edge6);

		Graph<int> graph = Graph<int>();

		graph.appendVertex(vertex1);
		graph.appendVertex(vertex2);
		graph.appendVertex(vertex3);
		graph.appendVertex(vertex4);
		graph.appendVertex(vertex5);
		graph.appendVertex(vertex6);

		ArraySequence<int> res = graph.dijkstra(0, 1000000);

		assert(res[0] == 0);
		assert(res[1] == 7);
		assert(res[2] == 9);
		assert(res[3] == 20);
		assert(res[4] == 20);
		assert(res[5] == 11);

	}

	static void test_coloring() {
		Edge<int> edge1 = Edge<int>(0, 1, 10);
		Edge<int> edge2 = Edge<int>(1, 2, 10);
		Edge<int> edge3 = Edge<int>(2, 3, 10);
		Edge<int> edge4 = Edge<int>(3, 0, 10);

		Vertex<int> vertex1 = Vertex<int>();
		Vertex<int> vertex2 = Vertex<int>();
		Vertex<int> vertex3 = Vertex<int>();
		Vertex<int> vertex4 = Vertex<int>();

		vertex1.appendOutgoingEdge(edge1);
		vertex2.appendOutgoingEdge(edge2);
		vertex3.appendOutgoingEdge(edge3);
		vertex4.appendOutgoingEdge(edge4);

		vertex2.appendIncomingEdge(edge1);
		vertex3.appendIncomingEdge(edge2);
		vertex4.appendIncomingEdge(edge3);
		vertex1.appendIncomingEdge(edge4);

		Graph<int> graph = Graph<int>();

		graph.appendVertex(vertex1);
		graph.appendVertex(vertex2);
		graph.appendVertex(vertex3);
		graph.appendVertex(vertex4);

		ArraySequence<int> res = graph.coloring();

		assert(res[0] == 0);
		assert(res[1] == 1);
		assert(res[2] == 0);
		assert(res[3] == 1);

	}

public:
	static void run() {
		test_append();
		test_dijkstra();
		test_coloring();

		cout << "All Graph tests finished successfully\n";
	}
};