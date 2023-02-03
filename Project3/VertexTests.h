#pragma once

#include <cassert>
#include <iostream>

#include "Vertex.h"
#include "Edge.h"

using namespace std;

class unittest_Vertex {
private:
	static void test() {
		Vertex<int> vertex = Vertex<int>();

		Edge<int> edge1 = Edge<int>(1, 2, 10);
		Edge<int> edge2 = Edge<int>(2, 3, 20);

		vertex.appendIncomingEdge(edge1);
		vertex.appendOutgoingEdge(edge2);

		assert(vertex.getIncomingIncidenceArrayLength() == 1);
		assert(vertex.getIncomingEdge(0).getIncomingVertexID() == 2);
		assert(vertex.getIncomingEdge(0).getOutgoingVertexID() == 1);
		assert(vertex.getIncomingEdge(0).getWeight() == 10);

		assert(vertex.getOutgoingIncidenceArrayLength() == 1);
		assert(vertex.getOutgoingEdge(0).getOutgoingVertexID() == 2);
		assert(vertex.getOutgoingEdge(0).getIncomingVertexID() == 3);
		assert(vertex.getOutgoingEdge(0).getWeight() == 20);
	}

	static void test_assign() {
		Vertex<int> vertex1 = Vertex<int>();
		Vertex<int> vertex2 = Vertex<int>();

		Edge<int> edge1 = Edge<int>(1, 2, 10);
		Edge<int> edge2 = Edge<int>(2, 3, 20);

		vertex1.appendIncomingEdge(edge1);
		vertex1.appendOutgoingEdge(edge2);

		Edge<int> edge3 = Edge<int>(4, 5, 30);
		Edge<int> edge4 = Edge<int>(5, 6, 40);

		vertex2.appendIncomingEdge(edge3);
		vertex2.appendOutgoingEdge(edge4);

		vertex1 = vertex2;

		assert(vertex1.getIncomingIncidenceArrayLength() == 1);
		assert(vertex1.getIncomingEdge(0).getIncomingVertexID() == 5);
		assert(vertex1.getIncomingEdge(0).getOutgoingVertexID() == 4);
		assert(vertex1.getIncomingEdge(0).getWeight() == 30);

		assert(vertex1.getOutgoingIncidenceArrayLength() == 1);
		assert(vertex1.getOutgoingEdge(0).getOutgoingVertexID() == 5);
		assert(vertex1.getOutgoingEdge(0).getIncomingVertexID() == 6);
		assert(vertex1.getOutgoingEdge(0).getWeight() == 40);
	}
public:
	static void run() {
		test();
		test_assign();

		cout << "All Vertex tests finished successfully\n";
	}
};