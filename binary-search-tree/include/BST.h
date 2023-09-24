#pragma once
#include <functional>
#include <iostream>

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

        void preorder()
        {
            preorder(root);
            std::cout << std::endl;
        }

        void inorder()
        {
            inorder(root);
            std::cout << std::endl;
        }

        void postorder()
        {
            postorder(root);
            std::cout << std::endl;
        }

    protected:
        BSTNode<T> *insert(BSTNode<T> *node, T key)
        {
            if (!node)
            {
                node = new BSTNode<T>;
                node->key = key;
                node->left = nullptr;
                node->right = nullptr;
            }
            else if (key < node->key)
                node->left = insert(node->left, key);
            else
                node->right = insert(node->right, key);
            return node;
        }

        void preorder(BSTNode<T> *node)
        {
            if (!node)
                return;

            std::cout << node->key << " ";
            preorder(node->left);
            preorder(node->right);
        }

        void inorder(BSTNode<T> *node)
        {
            if (!node)
                return;

            inorder(node->left);
            std::cout << node->key << " ";
            inorder(node->right);
        }

        void postorder(BSTNode<T> *node)
        {
            if (!node)
                return;

            postorder(node->left);
            postorder(node->right);
            std::cout << node->key << " ";
        }

    private:
        BSTNode<T> *root;
    };
}
