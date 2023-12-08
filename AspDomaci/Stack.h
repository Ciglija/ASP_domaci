#ifndef STACK_H_
#define STACK_H_

#include "Node.h"

class Stack
{
public:
	Stack() : head(nullptr) {};
	Stack& push(Node* root);
	Node* pop();
	bool isEmpty();
private:
	struct stackNode {
		Node* root;
		stackNode* next;
		stackNode(Node* root) : root(root), next(nullptr) {}
	};
	stackNode* head;
};
#endif
