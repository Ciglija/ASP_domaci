#include "Graph.h"

Graph::~Graph()
{
    for (int i = 0; i < size; ++i) {
        GraphNode* current = adjacencyList[i];
        while (current != nullptr) {
            GraphNode* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] adjacencyList;
}

Graph& Graph::makeGraph(Tree& bt) {
    int cnt = 0;
    while (cnt != size) {
        Stack* s = new Stack();
        s->push(bt.getRoot());
        while (!s->isEmpty()) {
            Node* next = s->pop();
            while (next) {
                if (funNames[cnt] == next->function) {
                    Node* child = next->first;
                    while (child) {
                        GraphNode* neighbor = adjacencyList[cnt];
                        bool add = true;
                        while (neighbor != nullptr) {
                            if (neighbor->fnc == child->function)
                                add = false;
                            neighbor = neighbor->next;
                        }
                        if (add) {
                            GraphNode* newNode = new GraphNode(child->function);
                            newNode->next = adjacencyList[cnt];
                            adjacencyList[cnt] = newNode;
                        }
                        child = child->next;
                    }
                }
                if (next->next != nullptr)
                    s->push(next->next);
                next = next->first;
            }
        }
        cnt++;
    }
    return *this;
}

void Graph::dfs() {

    bool* visited = new bool[size];
    for (int i = 0; i < size; ++i)
        visited[i] = false;

    int stack[10];
    int stackTop = -1;
    stack[++stackTop] = 0;

    while (stackTop >= 0) {
        int current = stack[stackTop--];

        if (!visited[current]) {
            std::cout << funNames[current] << " ";
            visited[current] = true;

            GraphNode* neighbor = adjacencyList[current];
            while (neighbor != nullptr) {
                int cnt = 0;
                int notVisitedCnt = 0;
                while (cnt != size) {
                    if (funNames[cnt] == neighbor->fnc) {
                        notVisitedCnt = cnt;
                        break;
                    }
                    cnt++;
                }
                if (!visited[notVisitedCnt]) {
                    stack[++stackTop] = notVisitedCnt;
                }
                neighbor = neighbor->next;
            }
        }
    }
    delete[] visited;
}

void Graph::findRecursion()
{
    int cnt = 0;
    while (cnt != size) {
        GraphNode* neighbor = adjacencyList[cnt];
        while (neighbor) {
            int br = 0;
            while (neighbor->fnc != funNames[br])
                br++;

            GraphNode* recursionNeighbor = adjacencyList[br];
            while (recursionNeighbor) {
                if (funNames[cnt] == recursionNeighbor->fnc) {
                    std::cout << "Postoji rekurzija." << endl;
                    return;
                }
                recursionNeighbor = recursionNeighbor->next;
            }
            neighbor = neighbor->next;
        }
        cnt++;
    }
    std::cout << "Ne postoji rekurzija." << endl;
}