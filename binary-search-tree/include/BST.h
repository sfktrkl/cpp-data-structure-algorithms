#pragma once
#include <functional>

namespace DataStructures
{
    template <typename T>
    class BSTNode
    {
    public:
        T key;
        BSTNode<T> *left;
        BSTNode<T> *right;
    };

    template <typename T>
    class BST
    {
    public:
        BST() : root(nullptr) {}
        ~BST()
        {
            std::function<void(BSTNode<T> *)> destroyTree;
            destroyTree = [&](BSTNode<T> *node)
            {
                if (node)
                {
                    destroyTree(node->left);
                    destroyTree(node->right);
                    delete node;
                }
            };
            destroyTree(root);
        }

        void insert(T key)
        {
            root = insert(root, key);
        }

    protected:
        BSTNode<T> *insert(BSTNode<T> *node, T key)
        {
            if (node == nullptr)
            {
                node = new BSTNode<T>;
                node->key = key;
                node->left = nullptr;
                node->right = nullptr;
            }
            else if (node->key < key)
                node->right = insert(node->right, key);
            else
                node->left = insert(node->left, key);
            return node;
        }

    private:
        BSTNode<T> *root;
    };
}
