// BinaryTrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "BTNode.h"
#include "traversal.h"
#include <iostream>
#include <functional>

int main()
{
    BTNode* head2 = buildBinaryTree(""
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
    traverseBinaryTree(head2, [=](BTNode* node) {
        std::cout << node->info;
    });
    std::cout << std::endl << "traversing the binary tree in preorder:" << std::endl;
    traverseBinaryTree(head2, [=](BTNode* node) {
        std::cout << node->info;
    }, TraversalOrder::PREORDER);
}
