#pragma once

#include <iostream>

#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"
#include "Data.h"

using namespace std;

int dataMenu() {
	int response;

	cout << "Choose the data type:\n";
	cout << "1 - int\n";
	cout << "2 - double\n";
	cout << "3 - complex\n";
	cout << "4 - person\n";

	cin >> response;

	return response;
}

template<typename T> int optionMenu() {
	int response;

	cout << "Choose the Graph option:\n";
	cout << "1 - read graph from file\n";
	cout << "2 - print Graph\n";
	cout << "3 - print Graph's number of vertices\n";
	cout << "4 - append edge into graph\n";
	cout << "5 - append vertex into graph\n";
	cout << "6 - Dijkstra's algorithm\n";
	cout << "7 - coloring the Graph\n";
	cout << "8 - run unit tests\n";
	cout << "9 - exit\n";

	cin >> response;

	return response;
}