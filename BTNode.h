#pragma once
#include <string>

struct BTNode {
	char info;
	bool hasRight;
	BTNode* left;
	BTNode* right;

	BTNode(char info) {
		this->info = info;
		this->hasRight = false;
		this->left = NULL;
		this->right = NULL;
	}
};

void insertBTRight(BTNode* tree, BTNode* node);
void insertBTLeft(BTNode* tree, BTNode* node);
BTNode* buildBinaryTree(std::string treeSpec);
