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

    private:
        BSTNode<T> *root;
    };
}
