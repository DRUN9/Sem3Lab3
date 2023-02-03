#pragma once

#include <set>
#include <iostream>

#include "Edge.h"
#include "Vertex.h"
#include "Sequence.h"

using namespace std;

template<typename T> class Graph {
private:
	ArraySequence<Vertex<T>> vertexArray;
public:
	Graph() {}

	int getSize() {
		return this->vertexArray.getSize();
	}

	Vertex<T>& get(int index) {
		return this->vertexArray[index];
	}

	void appendVertex(Vertex<T> vertex) {
		this->vertexArray.append(vertex);
	}

	void appendEdge(Edge<T> edge) {
		this->vertexArray[edge.getOutgoingVertexID()].appendOutgoingEdge(edge);
		this->vertexArray[edge.getIncomingVertexID()].appendIncomingEdge(edge);
	}

	ArraySequence<T> dijkstra(int start, T inf) {
		set<pair<T, int>> s;

		ArraySequence<T> dist = ArraySequence<T>(this->getSize());
		for (int i = 0; i < dist.getSize(); ++i) {
			dist[i] = inf;
		}

		dist[start] = 0;
		s.insert(make_pair(inf, start));

		while (s.size() != 0) {
			int startV = s.begin()->second;
			s.erase(s.begin());

			for (int i = 0; i < this->vertexArray[startV].getOutgoingIncidenceArrayLength(); ++i) {
				int endV = this->vertexArray[startV].getOutgoingEdge(i).getIncomingVertexID();
				T weight = this->vertexArray[startV].getOutgoingEdge(i).getWeight();

				if (dist[startV] + weight < dist[endV]) {
					s.erase(make_pair(dist[endV], endV));

					dist[endV] = dist[startV] + weight;
					s.insert(make_pair(dist[endV], endV));
				}
			}
		}

		return dist;
	}

	ArraySequence<int> coloring() {
		ArraySequence<int> colors = ArraySequence<int>(this->getSize());
		for (int i = 0; i < colors.getSize(); ++i) {
			colors[i] = -1;
		}

		for (int i = 0; i < this->getSize(); ++i) {
			ArraySequence<bool> availableColors = ArraySequence<bool>(this->getSize());
			for (int j = 0; j < availableColors.getSize(); ++j) {
				availableColors[i] = true;
			}

			for (int j = 0; j < this->vertexArray[i].getOutgoingIncidenceArrayLength(); ++j) {
				int incindenceVertex = this->vertexArray[i].getOutgoingEdge(j).getIncomingVertexID();

				if (colors[incindenceVertex] != -1) {
					availableColors[colors[incindenceVertex]] = false;
				}
			}

			for (int j = 0; j < this->vertexArray[i].getIncomingIncidenceArrayLength(); ++j) {
				int incindenceVertex = this->vertexArray[i].getIncomingEdge(j).getOutgoingVertexID();

				if (colors[incindenceVertex] != -1) {
					availableColors[colors[incindenceVertex]] = false;
				}
			}

			int c = 0;
			while (!availableColors[c]) {
				++c;
			}

			colors[i] = c;
		}

		return colors;
	}
};