// BinaryTrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "BTNode.h"
#include "TNode.h"
#include "traversal.h"
#include <iostream>
#include <functional>

void tree_correspondance_demo();
void traversal_demo();

int main()
{
    tree_correspondance_demo();
}

void traversal_demo() {
    BTNode* head = buildBinaryTree(""
        "A("
        "   B("
        "       _"
        "       C("
        "           K"
        "           _"
        "       )"
        "   )"
        "   D("
        "       E("
        "           H"
        "           F("
        "               J"
        "               G"
        "           )"
        "       )"
        "   )"
        ")"
    );

    std::cout << std::endl << "traversing the binary tree in inorder:" << std::endl;
    traverseBinaryTree(head, [=](BTNode* node) {
        std::cout << node->info;
        });
    std::cout << std::endl << "traversing the binary tree in preorder:" << std::endl;
    traverseBinaryTree(head, [=](BTNode* node) {
        std::cout << node->info;
        }, TraversalOrder::PREORDER);
}

void tree_correspondance_demo() {
    TNode* head = buildTree("(A(B,C(K)),D(E(H),F(J),G))");

    std::cout << head->info << std::endl;
    BTNode * bhead = toBinaryTree(head);

    std::cout << std::endl << "traversing the binary tree in inorder:" << std::endl;
    traverseBinaryTree(bhead, [=](BTNode* node) {
        std::cout << node->info;
        });
    std::cout << std::endl << "traversing the binary tree in preorder:" << std::endl;
    traverseBinaryTree(bhead, [=](BTNode* node) {
        std::cout << node->info;
        }, TraversalOrder::PREORDER);
}