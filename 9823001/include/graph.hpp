#include "graph.h"

// Part1
template <typename T>
void Graph<T>::addVertex(const T& value)
{
    Node* node { new Node {} };
    node->value = value;
    head.push_back(node);
}
template <typename T>
void Graph<T>::addEdge(const T& value1, const T& value2, int weight, std::function<bool(T, T)> func)
{
    Node* node1 { nullptr };
    Node* node2 { nullptr };
    for (auto node : head) {
        if (func(node->value, value1))
            node1 = node;
        if (func(node->value, value2))
            node2 = node;
    }

    Node* copy { new Node {} };
    copy->value = node2->value;

    Node* current { node1 };

    if (node1 && node2) {
        while (current->next) {
            current = current->next;
            if (find(current->value, copy->value)) {
                current->weight = copy->weight;
                return;
            }
        }
        current->next = copy;
        current->weight = weight;
    }
}

// Part2

Node* insert(Node* root, int value)
{
    if (root == nullptr) {
        root = new Node { value };
        return root;
    }
    if (root->value > value)
        root->left = insert(root->left, value);
    else if (root->value < value)
        root->right = insert(root->right, value);

    return root;
}
void deleteNode(Node*& root, int value)
{
    if (root == nullptr) {
        return;
    }

    if (value < root->value) {
        deleteNode(root->left, value);
    } else if (value > root->value) {
        deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            root = temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            root = temp;
        } else {
            Node* minValueNode = root->right;
            while (minValueNode->left != nullptr) {
                minValueNode = minValueNode->left;
            }
            root->value = minValueNode->value;
            deleteNode(root->right, minValueNode->value);
        }
    }
}
Node* find(Node* root, int value)
{
    if (root == nullptr || root->value == value)
        return root;
    if (value < root->value)
        return find(root->left, value);
    return find(root->right, value);
}
void printInOrder(Node* root)
{
    if (root != nullptr) {
        printInOrder(root->left);
        std::cout << root->value << " ";
        printInOrder(root->right);
    }
}
