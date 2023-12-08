#include "Stack.h"

Stack& Stack::push(Node* root)
{
	if (head == nullptr) {
		head = new stackNode(root);
		return *this;
	}
	stackNode* tmp = new stackNode(root);
	tmp->next = head;
	head = tmp;
	return *this;
}

Node* Stack::pop()
{
	Node* tmp = head->root;
	stackNode* d = head;
	head = head->next;
	delete d;
	d = nullptr;
	return tmp;
}

bool Stack::isEmpty() {
	return head == nullptr;
}