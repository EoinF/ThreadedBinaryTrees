#include "BTNode.h";

void insertBTRight(BTNode* tree, BTNode* node) {
    node->right = tree->right;
    tree->right = node;
    node->hasRight = tree->hasRight;
    tree->hasRight = true;
}

void insertBTLeft(BTNode* tree, BTNode* node) {
    node->left = tree->left;
    tree->left = node;

    if (node->left != NULL && !node->left->hasRight) {
        node->left->right = node;
    }
    if (!node->hasRight) {
        node->right = tree;
    }
}

BTNode* buildBinaryTree(std::string treeSpec) {
    BTNode* head;
    BTNode* current;
    bool isNextLeftSubtree = true;
    bool isAfterLeftInstance = false;

    auto it = treeSpec.begin();
    // Treat the head as a special case
    // and create that node first
    while (!isalpha(*it)) {
        it++;
    }
    head = new BTNode(*it);
    current = head;

    // skip past the first opening brace
    while ('(' != *it) {
        it++;
        if (it == treeSpec.end()) {
            return head;
        }
    }
    it++;

    for (;it < treeSpec.end() && current != NULL; it++) {
        char c = *it;
        if (c == ' ' || c == '\n') {
            continue;
        }
        if (c == '(') {
            isNextLeftSubtree = true;
            isAfterLeftInstance = false;
        }
        else if (c == ')') {
            current = current->right;
            isNextLeftSubtree = false;
            isAfterLeftInstance = false;
        }
        else if (c == '_') {
            isNextLeftSubtree = !isNextLeftSubtree;
        }
        else {
            if (isNextLeftSubtree) {
                insertBTLeft(current, new BTNode(c));
                isNextLeftSubtree = false;
                isAfterLeftInstance = true;
                current = current->left;
            }
            else {
                if (isAfterLeftInstance) {
                    current = current->right;
                }
                isAfterLeftInstance = false;
                insertBTRight(current, new BTNode(c));
                current = current->right;
            }
        }
    }
    return head;
}
