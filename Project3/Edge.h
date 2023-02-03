#pragma once

#include <iostream>

using namespace std;

template<typename T> class Edge {
private:
    int outgoingVertexID = 0;
    int incomingVertexID = 0;
    T weight;
public:
    Edge() {}

    Edge(int outgoingVertexID, int incomingVertexID, T weight) {
        this->outgoingVertexID = outgoingVertexID;
        this->incomingVertexID = incomingVertexID;
        this->weight = weight;
    }

    void set(int outgoingVertexID, int incomingVertexID, T Weight) {
        this->outgoingVertexID = outgoingVertexID;
        this->incomingVertexID = incomingVertexID;
        this->weight = Weight;
    }

    int getOutgoingVertexID() {
        return this->outgoingVertexID;
    }

    void setOutgoingVertexID(int outgoingVertexID) {
        this->outgoingVertexID = outgoingVertexID;
    }

    int getIncomingVertexID() {
        return this->incomingVertexID;
    }

    void setIncomingVertexID(int incomingVertexID) {
        this->incomingVertexID = incomingVertexID;
    }

    T getWeight() {
        return this->weight;
    }

    void setWeight(T weight) {
        this->weight = weight;
    }

    void swapVertices() {
        int tmp = this->getOutgoingVertexID();
        this->setOutgoingVertexID(this->getIncomingVertexID());
        this->setIncomingVertexID(tmp);
    }

    Edge<T>& operator=(const Edge<T>& edge) {
        this->outgoingVertexID = edge.outgoingVertexID;
        this->incomingVertexID = edge.incomingVertexID;
        this->weight = edge.weight;

        return *this;
    }
};