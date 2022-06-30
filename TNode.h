#pragma once
#include <string>

struct TNode {
	std::string info;
	bool hasRight;
	TNode* left;
	TNode* right;

	TNode(std::string info) {
		this->info = info;
		this->hasRight = false;
		this->left = NULL;
		this->right = NULL;
	}
};