#include "Tree.h"

Tree& Tree::makeTree()
{
    ifstream inputFile("AspTxt.txt");
    if (!inputFile.is_open()) {
        std::cout << "File ne postoji." << endl;
        return *this;
    }

    string line;
    while (getline(inputFile, line)) {
        string stackFunctions[10];
        int cnt = 0;
        stringstream ss(line);
        string word;
        while (ss >> word)
            stackFunctions[cnt++] =  word;

        insert(stackFunctions, cnt);
    }
    inputFile.close();
    return *this;
}

Tree& Tree::insert(string* s, int n) {
    int cnt = 0;
    if (root == nullptr)
        root = new Node(s[cnt]);

    Node* curr = root;
    while (cnt++ != n-1) {
            if (curr->first == nullptr) {
                curr->first = new Node(s[cnt]);
                curr = curr->first;
            }
            else {
                Node* sibling = curr->first;
                Node* prev = nullptr;
                bool found = false;
                while (sibling) {
                    if (sibling->function == s[cnt]) {
                        curr = sibling;
                        found = true;
                        break;
                    }
                    prev = sibling;
                    sibling = sibling->next;
                }
                if (!found) {
                    if (sibling != nullptr) {
                        sibling->next = new Node(s[cnt]);
                        curr = sibling->next;
                    }
                    else {
                        prev->next = new Node(s[cnt]);
                        curr = prev->next;
                    }
                }
            }
    }
    return *this;
}

Tree& Tree::deletePS(string* ps, int n)
{
    if (root == nullptr) {
        std::cout << "Stablo je Prazno." << endl;
        return *this;
    }

    Stack* s = new Stack();
    Node* curr = root;
    Node* parent = nullptr;
    int cnt = 0;

    while (cnt != n) {
        Node* prev = nullptr;
        while (curr) {
            if (curr->function == ps[cnt]) {
                cnt++;
                if (curr->first == nullptr) {
                    if (prev != nullptr) {
                        prev->next = curr->next;
                        delete curr;
                        curr = nullptr;
                    }
                    else {
                        if (curr->next == nullptr) {
                            parent->first = nullptr;
                            cnt = 0;
                            n--;
                            delete curr;
                            curr = root;
                        }
                        else {
                            parent->first = curr->next;
                            delete curr;
                            curr = nullptr;
                        }
                    }
                }
                else {
                    parent = curr;
                    curr = curr->first;
                }
                break;
            }
            prev = curr;
            curr = curr->next;
            if (!curr) {
                std::cout << "Funkcija ne postoji." << endl;
                return *this;
            }
        }
    }
    delete s;
    return *this;
}

void Tree::preOrderTraversal()
{
    if (root == nullptr) {
        std::cout << "Stablo je prazno.";
        return;
    }

    Stack* s = new Stack();
    s->push(root);
    while (!s->isEmpty()) {

        Node* next = s->pop();
        while (next) {
            std::cout << next->function << " ";
            if (next->next != nullptr)
                s->push(next->next);
            next = next->first;
        }
    }
    delete s;
}

Tree& Tree::freeTree()
{
    Stack* s = new Stack();
    s->push(root);
    while (!s->isEmpty()) {
        Node* next = s->pop();
        while (next) {
            if (next->next != nullptr)
                s->push(next->next);
            Node* tmp = next;
            next = next->first;
            delete tmp;
            tmp = nullptr;
        }
    }
    delete s;
    root = nullptr;
    return *this;
}

int numOfFunctions(Tree& nt)
{
    int cnt = 0;
    string functions[10];
    Stack* s = new Stack();
    s->push(nt.root);
    while (!s->isEmpty()) {
        Node* next = s->pop();
        while (next) {
            bool add = true;
            int i = 0;
            while (i <= cnt) {
                if (functions[i] == next->function)
                    add = false;
                i++;
            }
            if (add)
                functions[cnt++] = next->function;
            if (next->next != nullptr)
                s->push(next->next);
            next = next->first;
        }
    }
    delete s;
    return cnt;
}

Stack& finishedFunctions(Tree& nt)
{
    int cnt = 0;
    string functions[10];
    Stack* s = new Stack();
    Stack* st = new Stack();
    s->push(nt.root);
    while (!s->isEmpty()) {
        Node* next = s->pop();
        while (next) {
            bool add = true;
            int i = 0;
            while (i <= cnt) {
                if (functions[i] == next->function)
                    add = false;
                i++;
            }
            if (add) {
                functions[cnt++] = next->function;
                st->push(next);
            }
            if (next->next != nullptr)
                s->push(next->next);
            next = next->first;
        }
    }
    while (!st->isEmpty())
        s->push(st->pop());
    delete st;
    return *s;
}