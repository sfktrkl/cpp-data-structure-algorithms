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
        void insert(const T &key);
        void print() const;

    private:
        int t;
        Node<T> *root;

        Node<T> *search(const T &key, Node<T> *node) const;
        void split(Node<T> *x, int i);
        void insert(Node<T> *x, const T &key);
        void print(Node<T> *node, int depth = 0) const;
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

    template <typename T>
    void BTree<T>::split(Node<T> *x, int i)
    {
        Node<T> *y = x->children[i];

        Node<T> *z = new Node<T>(y->isLeaf);
        x->children.insert(x->children.begin() + i + 1, z);

        x->keys.insert(x->keys.begin() + i, y->keys[t - 1]);

        z->keys = std::vector<T>(y->keys.begin() + t, y->keys.end());
        y->keys = std::vector<T>(y->keys.begin(), y->keys.begin() + t - 1);

        if (!y->isLeaf)
        {
            z->children = std::vector<Node<T> *>(y->children.begin() + t, y->children.end());
            y->children = std::vector<Node<T> *>(y->children.begin(), y->children.begin() + t - 1);
        }
    }

    template <typename T>
    void BTree<T>::insert(const T &key)
    {
        Node<T> *root = this->root;
        if (root->keys.size() == 2 * t - 1)
        {
            Node<T> *newRoot = new Node<T>();
            this->root = newRoot;
            newRoot->children.push_back(root);
            split(newRoot, 0);
            insert(newRoot, key);
        }
        else
            insert(root, key);
    }

    template <typename T>
    void BTree<T>::insert(Node<T> *x, const T &key)
    {
        int i = x->keys.size() - 1;

        if (x->isLeaf)
        {
            x->keys.push_back(key);
            while (i >= 0 && key < x->keys[i])
            {
                x->keys[i + 1] = x->keys[i];
                --i;
            }
            x->keys[i + 1] = key;
        }
        else
        {
            while (i >= 0 && key < x->keys[i])
            {
                x->keys[i + 1] = x->keys[i];
                --i;
            }
            ++i;
            if (x->children[i]->keys.size() == 2 * t - 1)
            {
                split(x, i);
                if (key > x->keys[i])
                    ++i;
            }
            insert(x->children[i], key);
        }
    }

    template <typename T>
    void BTree<T>::print() const
    {
        if (root != nullptr)
            print(root);
    }

    template <typename T>
    void BTree<T>::print(Node<T> *node, int depth) const
    {
        if (node != nullptr)
        {
            for (int i = 0; i < depth; ++i)
                std::cout << "  ";

            for (const auto &key : node->keys)
                std::cout << key << ' ';
            std::cout << '\n';

            if (!node->isLeaf)
            {
                for (const auto &child : node->children)
                    print(child, depth + 1);
            }
        }
    }
}
