#pragma once
#include <functional>
#include <iostream>
#include <optional>
#include <queue>

namespace DataStructures
{
    template <typename T>
    class BSTNode
    {
    public:
        T key;
        BSTNode<T> *left;
        BSTNode<T> *right;
        BSTNode<T> *parent;
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

        void levelorder()
        {
            levelorder(root);
            std::cout << std::endl;
        }

        bool search(T key)
        {
            return search(root, key);
        }

        std::optional<T> min()
        {
            return min(root);
        }

        std::optional<T> max()
        {
            return max(root);
        }

        std::optional<T> successor(T key)
        {
            BSTNode<T> *node = search(root, key);
            return successor(node);
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
                node->parent = nullptr;
            }
            else if (key < node->key)
            {
                node->left = insert(node->left, key);
                node->left->parent = node;
            }
            else
            {
                node->right = insert(node->right, key);
                node->right->parent = node;
            }
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

        void levelorder(BSTNode<T> *node)
        {
            if (!node)
                return;

            std::queue<BSTNode<T> *> q;
            q.push(node);
            while (!q.empty())
            {
                BSTNode<T> *n = q.front();
                std::cout << n->key << " ";
                q.pop();

                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
        }

        BSTNode<T> *search(BSTNode<T> *node, T key)
        {
            if (!node)
                return nullptr;
            else if (key == node->key)
                return node;
            else if (key < node->key)
                return search(node->left, key);
            else
                return search(node->right, key);
        }

        std::optional<T> min(BSTNode<T> *node)
        {
            if (!node)
                return std::nullopt;
            else if (!node->left)
                return node->key;
            else
                return min(node->left);
        }

        std::optional<T> max(BSTNode<T> *node)
        {
            if (!node)
                return std::nullopt;
            else if (!node->right)
                return node->key;
            else
                return max(node->right);
        }

        std::optional<T> successor(BSTNode<T> *node)
        {
            if (node->right)
                return min(node->right);
            else
            {
                BSTNode<T> *parent = node->parent;
                BSTNode<T> *current = node;
                while (parent && current == parent->right)
                {
                    current = parent;
                    parent = current->parent;
                }

                return parent ? std::make_optional(parent->key) : std::nullopt;
            }
        }

    private:
        BSTNode<T> *root;
    };
}
