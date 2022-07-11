#include "BTNode.h";
#include "traversal.h";

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

void copyBranch(BTNode * current, BTNode * newTreeCurrent) {
	while (current != NULL) {
		if (current->left != NULL) {
			BTNode* newNode = new BTNode(current->left->info);
			insertBTLeft(newTreeCurrent, newNode);
			newTreeCurrent = newTreeCurrent->left;
			current = current->left;
			continue;
		}
		while (!current->hasRight) {
			if (current->right == NULL) {
				return;
			}
			// Use the threads to continue traversing the tree in inorder
			current = current->right;
			newTreeCurrent = newTreeCurrent->right;
		}
		if (current->hasRight) {
			BTNode* newNode = new BTNode(current->right->info);
			insertBTRight(newTreeCurrent, newNode);
			newTreeCurrent = newTreeCurrent->right;
			current = current->right;
			continue;
		}
	}
}

BTNode* copyBinaryTree(char rootValue, BTNode* left, BTNode* right) {
	BTNode* newTree = new BTNode(rootValue);

	if (left != NULL) {
		BTNode* newLeft = new BTNode(left->info);
		insertBTLeft(newTree, newLeft);
		copyBranch(left, newLeft);
	}
	if (right != NULL) {
		BTNode* newRight = new BTNode(right->info);
		insertBTRight(newTree, newRight);
		copyBranch(right, newRight);
	}
	return newTree;
}
