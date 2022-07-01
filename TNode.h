#pragma once
#include <string>
#include <vector>
#include "BTNode.h"

struct TNode {
	char info;
	std::vector<TNode*> children;

	TNode() {
		this->info = NULL;
	}
};

/**
	Iteratively build a forest from a given string spec
	The treespec must be given in preorder format
*/
TNode* buildTree(std::string treeSpec);

/**
	Build a binary tree from a given forest of trees.
	The binary tree grows to the right for each sibling of a node
	and grows to the left for children of that same node
*/
BTNode* toBinaryTree(TNode* head);