#pragma once
#include <vector>
#include <iostream>

namespace DataStructures
{
    template <typename T>
    class Node
    {
    public:
        Node(bool isLeaf = false) : isLeaf(isLeaf) {}

        ~Node()
        {
            for (auto child : children)
                delete child;
        }

        bool isLeaf;
        std::vector<T> keys;
        std::vector<Node<T> *> children;
    };

    template <typename T>
    class BTree
    {
    public:
        BTree(int t) : t(t), root(new Node<T>(true)) {}

        ~BTree()
        {
            delete root;
        }

        Node<T> *search(const T &key) const;

    private:
        int t;
        Node<T> *root;

        Node<T> *search(const T &key, Node<T> *node) const;
    };

    template <typename T>
    Node<T> *BTree<T>::search(const T &key) const
    {
        return search(key, root);
    }

    template <typename T>
    Node<T> *BTree<T>::search(const T &key, Node<T> *node) const
    {
        int i = 0;
        while (i < node->keys.size() && key > node->keys[i])
            ++i;

        if (i < node->keys.size() && key == node->keys[i])
            return node;
        else if (node->isLeaf)
            return nullptr;
        else
            return search(key, node->children[i]);
    }
}
