#ifndef BST_HPP
#define BST_HPP


/* BST Tree basic implementation
 * Author: Rafał Surdej
 * 16.12.2019
 */

#include <iostream>
#include <stdexcept>

using namespace std;

class DuplicationError : public runtime_error
{
public:
    explicit DuplicationError(): runtime_error("A node of that key already exsists in BST!"){}
};

class NoKeyError : public runtime_error
{
public:
    explicit NoKeyError(): runtime_error("A node of that key does not exist!"){}
};

template<typename K, typename V>
class MyBST
{
    struct node
    {
        K key;
        V value;
        node* left;
        node* right;
    };

    node* root;

public:
    using key_type = K;
    using mapped_type = V;
    using value_type = pair<const key_type, mapped_type>;

    MyBST(): root(nullptr) {}

    node* insert(const key_type& k, const mapped_type& v)
    {
        node* new_node = new(node);
        new_node->key = k;
        new_node->value = v;
        new_node->left = nullptr;
        new_node->right = nullptr;
        insertIntoBST (new_node, root);
        return new_node;
    }

    void insertIntoBST(node* &new_n, node* &n)
    {
        if (n == nullptr)
        {
            n = new_n;
        }
        else if (new_n->key > n->key)
        {
            insertIntoBST(new_n, n->right);
        }
        else if (new_n->key < n->key)
        {
            insertIntoBST(new_n, n->left);
        }
        else
        {
            throw DuplicationError();
        }
    }

    node* findMinInSubtree(node* &n) const
    {
        node* tmp = n;
        while (tmp->left != nullptr)
        {
            tmp = tmp->left;
        }
        return tmp;
    }

    void deleteNode(const key_type &k)
    {
        deleteFromBST(k, root);
    }

    node* deleteFromBST(const key_type &k, node* &n)
    {
        if (n == nullptr)
        {
            throw NoKeyError();
        }
        else if(k < n->key)
        {
            n->left = deleteFromBST(k, n->left);
        }
        else if(k > n->key)
        {
            n->right = deleteFromBST(k, n->right);
        }
        else
        {
            node* tmp = n;
            if (n->left == nullptr)
            {
                n = n->right;
            }
            else if (n->right == nullptr)
            {
                n = n->left;
            }
            else
            {

                node* next = n->right;
                node* par_next = n->right;
                while (next->left != nullptr) // we're looking for the smallest element bigger than our n and its parent
                {
                    par_next = next;
                    next = next->left;
                }
                if (next != par_next)  // avoiding looping at first element
                {
                    par_next->left = next->right;
                    next->right = tmp->right;
                }
                next->left = tmp->left;
                n = next;
            }
            delete tmp;
        }
        return n;
    }

    void printBST(ostream& os, node* n, int level) const
    {
        if(n)
        {
            printBST(os, n->right, level + 1);
            for (int i = 0; i < level; ++i)
            {
                os << "     ";
            }
            os << n->key << endl;
            printBST(os, n->left, level + 1);
        }
    }

    friend ostream& operator<<(ostream& os, const MyBST& pr)
    {
        if (pr.root)
        {
            pr.printBST(os, pr.root, 0);
        }
        else
            os << "BST is empty!\n";
        return os;
    }


    void destrRec(node* &n)
    {
        if (n)
        {
            destrRec(n->left);
            destrRec(n->right);
            delete n;
        }
    }

    ~MyBST()
    {
        destrRec(root);
    }
};

#endif // BST_HPP















