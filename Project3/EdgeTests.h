#pragma once

#include <cassert>
#include <iostream>

#include "Edge.h"

using namespace std;

class unittest_Edge {
private:
	static void test_set() {
		Edge<int> edge = Edge<int>();

		edge.set(1, 2, 10);

		assert(edge.getOutgoingVertexID() == 1);
		assert(edge.getIncomingVertexID() == 2);
		assert(edge.getWeight() == 10);

		edge.setIncomingVertexID(3);
		assert(edge.getIncomingVertexID() == 3);

		edge.setOutgoingVertexID(4);
		assert(edge.getOutgoingVertexID() == 4);

		edge.setWeight(100);
		assert(edge.getWeight() == 100);
	}

	static void test_get() {
		Edge<int> edge = Edge<int>(1, 2, 10);

		assert(edge.getOutgoingVertexID() == 1);
		assert(edge.getIncomingVertexID() == 2);
		assert(edge.getWeight() == 10);
	}

	static void test_swap() {
		Edge<int> edge = Edge<int>(1, 2, 10);

		edge.swapVertices();

		assert(edge.getOutgoingVertexID() == 2);
		assert(edge.getIncomingVertexID() == 1);
		assert(edge.getWeight() == 10);
	}

	static void test_assign() {
		Edge<int> edge1 = Edge<int>(1, 2, 10);
		Edge<int> edge2 = Edge<int>(3, 4, 100);

		edge1 = edge2;

		assert(edge1.getIncomingVertexID() == edge2.getIncomingVertexID());
		assert(edge1.getOutgoingVertexID() == edge2.getOutgoingVertexID());
		assert(edge1.getWeight() == edge2.getWeight());
	}
public:
	static void run() {
		test_get();
		test_set();
		test_swap();
		test_assign();

		cout << "All Edge tests finished successfully\n";
	}
};