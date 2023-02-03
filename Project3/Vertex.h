#pragma once

#include "Sequence.h"
#include "Edge.h"

using namespace std;

template<typename T> class Vertex {
private:
	ArraySequence<Edge<T>> outgoingIncidenceArray;
	ArraySequence<Edge<T>> incomingIncidenceArray;
public:
	Vertex() {}

	void appendOutgoingEdge(Edge<T> edge) {
		this->outgoingIncidenceArray.append(edge);
	}

	void appendIncomingEdge(Edge<T> edge) {
		this->incomingIncidenceArray.append(edge);
	}

	int getOutgoingIncidenceArrayLength() {
		return this->outgoingIncidenceArray.getSize();
	}

	int getIncomingIncidenceArrayLength() {
		return this->incomingIncidenceArray.getSize();
	}

	Edge<T>& getOutgoingEdge(int index) {
		return this->outgoingIncidenceArray[index];
	}

	Edge<T>& getIncomingEdge(int index) {
		return this->incomingIncidenceArray[index];
	}

	Vertex<T>& operator=(const Vertex<T>& vertex) {
		this->incomingIncidenceArray = vertex.incomingIncidenceArray;
		this->outgoingIncidenceArray = vertex.outgoingIncidenceArray;

		return *this;
	}
};