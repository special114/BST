#ifndef TESTS_H
#define TESTS_H

#include "BST.hpp"

void rootDeletion ()
{
    cout << "Deleting the root\n";
    MyBST<int, int> tree1;
    tree1.insert(23,4);
    tree1.insert(4,4);
    tree1.insert(17,4);
    tree1.insert(35,4);
    tree1.insert(18, 4);
    tree1.insert(14, 4);
    tree1.insert(3, 4);
    tree1.insert(2, 4);
    cout << tree1;
    cout << endl;
    tree1.deleteNode(23);
    cout << "BST after deletion\n";
    cout << tree1;
}

void leafDeletion ()
{
    cout << "Deleting a leaf\n";
    MyBST<int, int> tree2;
    tree2.insert(23,4);
    tree2.insert(5,4);
    tree2.insert(17,4);
    tree2.insert(35,4);
    tree2.insert(18,4);
    tree2.insert(14,4);
    tree2.insert(3,4);
    tree2.insert(2,4);
    cout << tree2;
    cout << endl;
    tree2.deleteNode(14);
    cout << "BST after deletion\n";
    cout << tree2;
}

void oneChildNodeDeletion ()
{
    cout << "Deleting a node with one child\n";
    MyBST<int, int> tree1;
    tree1.insert(23,4);
    tree1.insert(4,4);
    tree1.insert(17,4);
    tree1.insert(35,4);
    tree1.insert(18, 4);
    tree1.insert(14, 4);
    tree1.insert(3, 4);
    tree1.insert(2, 4);
    cout << tree1;
    cout << endl;
    tree1.deleteNode(3);
    cout << "BST after deletion\n";
    cout << tree1;
}

void twoChildrenNodeDeletion ()
{
    cout << "Deleting a node with two children\n";
    MyBST<int, int> tree1;
    tree1.insert(23,4);
    tree1.insert(4,4);
    tree1.insert(17,4);
    tree1.insert(35,4);
    tree1.insert(18, 4);
    tree1.insert(14, 4);
    tree1.insert(3, 4);
    tree1.insert(2, 4);
    cout << tree1;
    cout << endl;
    tree1.deleteNode(4);
    cout << "BST after deletion\n";
    cout << tree1;
}

void wholeTreeDeletion ()
{
    cout << "Deleting whole tree\n";
    MyBST<int, int> tree1;
    tree1.insert(23,4);
    tree1.insert(4,4);
    tree1.insert(17,4);
    tree1.insert(35,4);
    tree1.insert(18, 4);
    tree1.insert(14, 4);
    tree1.insert(3, 4);
    tree1.insert(2, 4);
    cout << tree1;
    cout << endl;
    tree1.deleteNode(23);
    tree1.deleteNode(4);
    tree1.deleteNode(17);
    tree1.deleteNode(35);
    tree1.deleteNode(18);
    tree1.deleteNode(14);
    tree1.deleteNode(3);
    tree1.deleteNode(2);
    cout << "BST after deletion\n";
    cout << tree1;
}

void notExistingNodeDeletion()
{
    cout << "Deleting a node that doesn't exist\n";
    MyBST<int, int> tree1;
    tree1.insert(23,4);
    tree1.insert(4,4);
    tree1.insert(17,4);
    tree1.insert(35,4);
    tree1.insert(18, 4);
    tree1.insert(14, 4);
    tree1.insert(3, 4);
    tree1.insert(2, 4);
    cout << tree1;
    cout << endl;
    tree1.deleteNode(100);
    cout << "BST after deletion\n";
    cout << tree1;
}

#endif // TESTS_H
