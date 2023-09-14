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
        void remove(const T &key);

    private:
        int t;
        Node<T> *root;

        Node<T> *search(const T &key, Node<T> *node) const;
        void split(Node<T> *x, int i);
        void insert(Node<T> *x, const T &key);
        void print(Node<T> *node, int depth = 0) const;
        void remove(Node<T> *x, const T &key);
        void removeInternalNode(Node<T> *x, const T &key, int i);
        T removePredecessor(Node<T> *x);
        T removeSuccessor(Node<T> *x);
        void removeMerge(Node<T> *x, int i, int j);
        void removeSibling(Node<T> *x, int i, int j);
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

    template <typename T>
    void BTree<T>::remove(const T &key)
    {
        remove(root, key);
    }

    template <typename T>
    void BTree<T>::remove(Node<T> *x, const T &key)
    {
        int i = 0;
        while (i < x->keys.size() && key > x->keys[i])
            ++i;

        if (x->isLeaf)
        {
            while (i < x->keys.size() && key == x->keys[i])
                x->keys.pop_back();
            return;
        }

        if (i < x->keys.size() && key == x->keys[i])
            removeInternalNode(x, key, i);
        else if (x->children[i]->keys.size() >= t)
            remove(x->children[i], key);
        else
        {
            if (i != 0 && i + 2 < x->children.size())
            {
                if (x->children[i - 1]->keys.size() >= t)
                    removeSibling(x, i, i - 1);
                else if (x->children[i + 1]->keys.size() >= t)
                    removeSibling(x, i, i + 1);
                else
                    removeMerge(x, i, i + 1);
            }
            else if (i == 0)
            {
                if (x->children[i + 1]->keys.size() >= t)
                    removeSibling(x, i, i + 1);
                else
                    removeMerge(x, i, i + 1);
            }
            else if (i + 1 == x->children.size())
            {
                if (x->children[i - 1]->keys.size() >= t)
                    removeSibling(x, i, i - 1);
                else
                    removeMerge(x, i, i - 1);
            }
            remove(x->children[i], key);
        }
    }

    template <typename T>
    void BTree<T>::removeInternalNode(Node<T> *x, const T &key, int i)
    {
        if (x->isLeaf)
        {
            if (x->keys[i] == key)
                x->keys.erase(x->keys.begin() + i);
            return;
        }

        if (x->children[i]->keys.size() >= t)
            x->keys[i] = removePredecessor(x->children[i]);
        else if (x->children[i + 1]->keys.size() >= t)
            x->keys[i] = removeSuccessor(x->children[i + 1]);
        else
        {
            removeMerge(x, i, i + 1);
            removeInternalNode(x->children[i], key, t - 1);
        }
    }

    template <typename T>
    T BTree<T>::removePredecessor(Node<T> *x)
    {
        if (x->isLeaf)
        {
            T value = x->keys.back();
            x->keys.pop_back();
            return value;
        }

        int n = x->keys.size() - 1;
        if (x->children[n]->keys.size() >= t)
            removeSibling(x, n + 1, n);
        else
            removeMerge(x, n, n + 1);
        return removePredecessor(x->children[n]);
    }

    template <typename T>
    T BTree<T>::removeSuccessor(Node<T> *x)
    {
        if (x->isLeaf)
        {
            T value = x->keys.front();
            x->keys.erase(x->keys.begin());
            return value;
        }

        int n = 0;
        if (x->children[n]->keys.size() >= t)
            removeSibling(x, n + 1, n);
        else
            removeMerge(x, n, n + 1);
        return removeSuccessor(x->children[n]);
    }

    template <typename T>
    void BTree<T>::removeMerge(Node<T> *x, int i, int j)
    {
        Node<T> *newNode;
        Node<T> *current = x->children[i];

        if (j > i)
        {
            Node<T> *right = x->children[j];
            current->keys.push_back(x->keys[i]);
            for (int k = 0; k < right->keys.size(); ++k)
            {
                current->keys.push_back(right->keys[k]);
                if (right->children.size() > 0)
                    current->children.push_back(right->children[k]);
            }
            if (right->children.size() > 0)
            {
                current->children.push_back(right->children.back());
                right->children.pop_back();
            }
            newNode = current;
            x->keys.erase(x->keys.begin() + i);
            x->children.erase(x->children.begin() + j);
            delete right;
        }
        else
        {
            Node<T> *left = x->children[j];
            left->keys.push_back(x->keys[j]);
            for (int k = 0; k < current->keys.size(); ++k)
            {
                left->keys.push_back(current->keys[k]);
                if (current->children.size() > 0)
                    left->children.push_back(current->children[k]);
            }
            if (current->children.size() > 0)
            {
                left->children.push_back(current->children.back());
                current->children.pop_back();
            }
            newNode = left;
            x->keys.erase(x->keys.begin() + j);
            x->children.erase(x->children.begin() + i);
            delete current;
        }

        if (x == root && x->keys.size() == 0)
        {
            root = newNode;
            delete x;
        }
    }

    template <typename T>
    void BTree<T>::removeSibling(Node<T> *x, int i, int j)
    {
        Node<T> *current = x->children[i];

        if (i < j)
        {
            Node<T> *right = x->children[j];
            current->keys.push_back(x->keys[i]);
            x->keys[i] = right->keys[0];
            if (right->children.size() > 0)
            {
                current->children.push_back(right->children.front());
                Node<T> *node = right->children.front();
                right->children.erase(right->children.begin());
                delete node;
            }
            right->keys.erase(right->keys.begin());
        }
        else
        {
            Node<T> *left = x->children[j];
            left->keys.insert(left->keys.begin(), x->keys[i - 1]);
            x->keys[i - 1] = left->keys.back();
            left->keys.pop_back();
            if (left->children.size() > 0)
            {
                current->children.insert(current->children.begin(), left->children.back());
                Node<T> *node = left->children.back();
                left->children.pop_back();
                delete node;
            }
        }
    }
}
