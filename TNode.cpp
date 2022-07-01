#include <stack>
#include "TNode.h"

TNode* buildTree(std::string treeSpec)
{
	std::stack<TNode*> parents;

	TNode* current = new TNode();

	auto it = treeSpec.begin();

	for (;it < treeSpec.end(); it++) {
		char c = *it;
		if (c == ' ' || c == '\n') {
			continue;
		}
		if (c == '(') {
			parents.push(current);
			TNode * newNode = new TNode();
			current->children.push_back(newNode);
			current = newNode;
		}
		else if (c == ')') {
			current = parents.top();
			parents.pop();
		}
		else if (c == ',') {
			TNode* newNode = new TNode();
			parents.top()->children.push_back(newNode);
			current = newNode;
		}
		else {
			current->info = c;
		}
	}
	return current;
}

void buildLeftSubtree(TNode* head, BTNode* bhead);
void buildRightSubtree(TNode* head, BTNode* bhead);

void buildRightSubtree(TNode* head, BTNode* bhead)
{
	for (auto i = head->children.size() - 1; i > 0; i--) {
		TNode* nextTree = head->children[i];
		// Insert siblings to the right subtree
		insertBTRight(bhead, new BTNode(nextTree->info));
		if (!nextTree->children.empty()) {
			buildLeftSubtree(nextTree, bhead->right);
		}
	}
}

void buildLeftSubtree (TNode* head, BTNode * bhead)
{
	if (head->children.empty()) {
		return;
	}

	TNode* firstTree = head->children[0];
	BTNode* current = new BTNode(firstTree->info);
	insertBTLeft(bhead, current);
	if (!firstTree->children.empty()) {
		buildLeftSubtree(firstTree, current);
	}
	buildRightSubtree(head, current);
}


BTNode* toBinaryTree(TNode* head)
{
	if (!head->children.empty()) {
		TNode* firstTree = head->children[0];
		BTNode* bhead = new BTNode(firstTree->info);
		buildLeftSubtree(firstTree, bhead);
		buildRightSubtree(head, bhead);
		return bhead;
	}
	return NULL;
}
