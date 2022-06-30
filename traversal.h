#pragma once
#include <functional>
#include "BTNode.h"

enum TraversalOrder {
    PREORDER,
    INORDER,
};
void traverseBinaryTree(BTNode* head, std::function<void(BTNode*)> visit, TraversalOrder order = TraversalOrder::INORDER);
