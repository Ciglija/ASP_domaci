#ifndef NODE_H_
#define NODE_H_

#include  <iostream>
#include <string>
#include <fstream>

using namespace std;

class Node
{
public:
    string function;
    Node* first;
    Node* next;
    Node(string function) : function(function), first(nullptr), next(nullptr) {}
};
#endif

