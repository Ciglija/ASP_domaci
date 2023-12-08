#ifndef TREE_H_
#define TREE_H_

#include "Node.h"
#include "Stack.h"
#include "sstream"

class Tree
{
public:
	Tree() : root(nullptr) {}
	Tree& makeTree();
	Tree& insert(string* s, int n);
	Tree& deletePS(string* ps, int n);
	Tree& freeTree();
	void preOrderTraversal();
	Node* getRoot() { return root; }
	friend int numOfFunctions(Tree& nt);
	friend Stack& finishedFunctions(Tree& nt);
private:
	Node* root;
};
#endif
