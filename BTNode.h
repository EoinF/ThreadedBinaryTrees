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

/**
	Inserts a node as the left subtree of the given tree
	If the tree already has a left node, then that left node
	becomes the left subtree of the new node
*/
void insertBTLeft(BTNode* tree, BTNode* node);

/**
	Inserts a node as the right subtree of the given tree
	If the tree already has a right node, then that right node
	becomes the right subtree of the new node
*/
void insertBTRight(BTNode* tree, BTNode* node);

/**
	Iteratively build a binary tree from a given string spec
*/
BTNode* buildBinaryTree(std::string treeSpec);

/**
	Creates a deep copy of the given binary tree
*/
BTNode* copyBinaryTree(char rootValue, BTNode* left = NULL, BTNode* right = NULL);