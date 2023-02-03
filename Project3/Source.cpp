#include <iostream>
#include <fstream>

#include "EdgeTests.h"
#include "VertexTests.h"
#include "GraphTests.h"
#include "SequenceTests.h"
#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include "Menu.h"

using namespace std;

void readGraph(string fileName, Graph<int>& graph) {
	ifstream fin;

	fin.open("Graphs\\" + fileName);

	if (!fin.is_open()) {
		cout << "Could not open the file\n";
		return;
	}

	int vertexNumber;

	fin >> vertexNumber;

	for (int i = 0; i < vertexNumber; ++i) {
		int outgoingEdgesNumber, incomingEdgesNumber;
		Vertex<int> v = Vertex<int>();

		fin >> outgoingEdgesNumber >> incomingEdgesNumber;

		for (int i = 0; i < outgoingEdgesNumber; ++i) {
			Edge<int> edge = Edge<int>();
			int from, to, weight;

			fin >> from >> to >> weight;
			edge.set(from - 1, to - 1, weight);

			v.appendOutgoingEdge(edge);
		}

		for (int i = 0; i < incomingEdgesNumber; ++i) {
			Edge<int> edge = Edge<int>();
			int from, to, weight;

			fin >> from >> to >> weight;
			edge.set(from - 1, to - 1, weight);

			v.appendIncomingEdge(edge);
		}

		graph.appendVertex(v);
	}

	fin.close();
}

template<typename T> ostream& operator<<(ostream& out, Edge<T>& edge) {
	out << edge.getOutgoingVertexID() + 1 << " -> " << edge.getIncomingVertexID() + 1 << " W = " << edge.getWeight();

	return out;
}

template<typename T> istream& operator>>(istream& in, Edge<T>& edge) {
	int outgoingVertexID, incomingVertexID, weight;

	if (&in == &cin) {
		cout << "Enter outgoing vertex ID: ";
	}
	in >> outgoingVertexID;

	if (&in == &cin) {
		cout << "Enter incoming vertex ID: ";
	}
	in >> incomingVertexID;

	if (&in == &cin) {
		cout << "Enter weight of the edge: ";
	}
	in >> weight;

	edge.set(outgoingVertexID - 1, incomingVertexID - 1, weight);

	return in;
}

template<typename T> ostream& operator<<(ostream& out, Vertex<T>& vertex) {
	out << "\tIncoming Edges:\n";
	for (int i = 0; i < vertex.getIncomingIncidenceArrayLength(); ++i) {
		out << "\t\t" << vertex.getIncomingEdge(i) << '\n';
	}

	out << "\n\tOutgoing Edges:\n";
	for (int i = 0; i < vertex.getOutgoingIncidenceArrayLength(); ++i) {
		out << "\t\t" << vertex.getOutgoingEdge(i);

		if (i != vertex.getOutgoingIncidenceArrayLength() - 1) {
			out << '\n';
		}
	}

	return out;
}

template<typename T> ostream& operator<<(ostream& out, Graph<T>& graph) {
	for (int i = 0; i < graph.getSize(); ++i) {
		out << "V = " << i + 1 << '\n';
		out << graph.get(i);

		if (i != graph.getSize() - 1) {
			out << '\n';
		}
	}

	return out;
}

template<typename T> void edgeInput(Graph<T>& graph, Edge<T>& edge) {
	while (edge.getIncomingVertexID() > graph.getSize() || edge.getIncomingVertexID() <= 0 || edge.getOutgoingVertexID() > graph.getSize() || edge.getOutgoingVertexID() <= 0) {
		cin >> edge;

		if (edge.getIncomingVertexID() > graph.getSize() || edge.getIncomingVertexID() <= 0 || edge.getOutgoingVertexID() > graph.getSize() || edge.getOutgoingVertexID() <= 0) {
			cout << "Error - wrong edge data, try again\n";
		}
	}
}

int main() {
	int optionResponse = -1;

	Graph<int> graph = Graph<int>();

	while (optionResponse != 9) {
		optionResponse = optionMenu<int>();
		while (optionResponse < 1 || optionResponse > 9) {
			optionResponse = optionMenu<int>();

			if (optionResponse < 1 || optionResponse > 9) {
				cout << "Wrong option, try again\n";
			}
		}
		if (optionResponse == 1) {
			string fileName;
			//cin >> fileName;

			cout << "Enter the file name: ";

			cin >> fileName;

			readGraph(fileName, graph);
		}

		if (optionResponse == 2) {
			cout << graph << '\n';
			cout << '\n';
		}
		else if (optionResponse == 3) {
			cout << "Graph's number of vertices: " << graph.getSize() << '\n';
		}
		else if (optionResponse == 4) {
			if (graph.getSize() <= 1) {
				cout << "Error - graph's size is less than 2\n";
			}
			else {
				Edge<int> edge = Edge<int>(-1, -1, -1);

				while (edge.getIncomingVertexID() >= graph.getSize() || edge.getIncomingVertexID() < 0 || edge.getOutgoingVertexID() >= graph.getSize() || edge.getOutgoingVertexID() < 0) {
					cin >> edge;

					if (edge.getIncomingVertexID() >= graph.getSize() || edge.getIncomingVertexID() < 0 || edge.getOutgoingVertexID() >= graph.getSize() || edge.getOutgoingVertexID() < 0) {
						cout << "Error - wrong edge data, try again\n";
					}
				}

				graph.appendEdge(edge);
			}
		}
		else if (optionResponse == 5) {
			Vertex<int> vertex = Vertex<int>();

			cout << "Enter the data of the vertex " << graph.getSize() << ":\n";

			int numberOfIncomingEdges = -1;
			int numberOfOutgoingEdges = -1;

			while (numberOfIncomingEdges < 0 || numberOfIncomingEdges > graph.getSize()) {
				cout << "Enter the number of incoming edges: ";
				cin >> numberOfIncomingEdges;

				if (numberOfIncomingEdges < 0 || numberOfIncomingEdges > graph.getSize()) {
					cout << "Wrong value\n";
				}
			}

			while (numberOfOutgoingEdges < 0 || numberOfOutgoingEdges > graph.getSize()) {
				cout << "Enter the number of outgoing edges: ";
				cin >> numberOfOutgoingEdges;

				if (numberOfOutgoingEdges < 0 || numberOfOutgoingEdges > graph.getSize()) {
					cout << "Wrong value\n";
				}
			}

			graph.appendVertex(vertex);

			cout << "Enter the data of incoming edges:\n";
			for (int i = 0; i < numberOfIncomingEdges; ++i) {
				Edge<int> edge = Edge<int>();

				cin >> edge;

				graph.appendEdge(edge);
			}

			cout << "Enter the data of outgoing edges:\n";
			for (int i = 0; i < numberOfOutgoingEdges; ++i) {
				Edge<int> edge = Edge<int>();

				cin >> edge;

				graph.appendEdge(edge);
			}
		}
		else if (optionResponse == 6) {
			int dijkstraResponse = -1;

			while (dijkstraResponse >= graph.getSize() || dijkstraResponse < 0) {
				cout << "Enter the number of starting vertex: ";
				cin >> dijkstraResponse;

				if (dijkstraResponse >= graph.getSize() || dijkstraResponse < 0) {
					cout << "Wrong option, try again\n";
				}
			}

			ArraySequence<int> res = graph.dijkstra(dijkstraResponse - 1, 1e6);

			cout << "The least distances from vertex " << dijkstraResponse << ":\n";

			for (int i = 0; i < res.getSize(); ++i) {
				cout << "To vertex " << i + 1 << ": " << res[i] << '\n';
			}
		}
		else if (optionResponse == 7) {
			ArraySequence<int> res = graph.coloring();

			cout << "Coloring graph:\n";

			for (int i = 0; i < res.getSize(); ++i) {
				cout << "Vertex " << i + 1 << " color: " << res[i] << '\n';
			}
		}
		else if (optionResponse == 8) {
			cout << "Running unit tests:\n";
			unittest_DynamicArray::run();
			unittest_LinkedList::run();
			unittest_ArraySequence::run();
			unittest_ListSequence::run();
			unittest_Edge::run();
			unittest_Vertex::run();
			unittest_Graph::run();

			cout << '\n';
		}
		else if (optionResponse == 9) {
			cout << "Ending program\n";

			return 0;
		}
	}

	return 0;
}