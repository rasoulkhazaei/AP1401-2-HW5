#include "graph.h"

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
