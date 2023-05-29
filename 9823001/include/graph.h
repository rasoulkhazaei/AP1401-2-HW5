#ifndef GRAPH_H
#define GRAPH_H

#include <functional>
#include <iostream>
#include <vector>
template <typename T>
class Graph {
public:
    Graph() = default;

    void addVertex(const T&);
    void addEdge(const T&, const T&, int, std::function<bool(T, T)>);

private:
    class Node {
    public:
        T value;
        int weight {};
        Node* next {};
    };
    std::vector<Node*> head;
};

struct Node { //// for part 2
    int value;
    Node* left;
    Node* right;

    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node*, int);
void deleteNode(Node*&, int);
Node* find(Node*, int);
void printInOrder(Node*);

#include "graph.hpp"

#endif
