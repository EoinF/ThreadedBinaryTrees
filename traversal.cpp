#include "traversal.h"

/**
    Traverse the tree in inorder while visiting the nodes in the order specified by the 'order' param
*/
void traverseBinaryTree(BTNode* head, std::function<void(BTNode*)> visit, TraversalOrder order) {
    BTNode* current = head;

    while (current != NULL) {
        if (order == TraversalOrder::PREORDER) {
            visit(current);
        }
        // Complete the first step of inorder traversal
        // until a left leaf node is reached
        while (current->left != NULL) {
            if (order == TraversalOrder::PREORDER) {
                visit(current->left);
            }
            current = current->left;
        }

        // Follow the right threads upwards in the tree
        // until we reach a right subtree that can be expanded
        bool hasRight = false;
        do {
            if (order == TraversalOrder::INORDER) {
                visit(current);
            }
            hasRight = current->hasRight;
            current = current->right;
        } while (!hasRight && current != NULL);
    }
}