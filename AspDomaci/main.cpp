#include "Graph.h"

int main() {
    Tree* t = new Tree();
    while (true) {
        bool doTree = true;
        while (doTree) {
            int operationCase;
            std::cout << "1. Ucitavanje iz tekst fajla i kreiranje stabla" << endl;
            std::cout << "2. Unos programskog steka iz konzole" << endl;
            std::cout << "3. Ispis binarnog stabla(PreOrder)" << endl;
            std::cout << "4. Brisanje programskog steka" << endl;
            std::cout << "5. Brisanje stabla" << endl;
            std::cout << "9. Prelazak na rad sa grafom" << endl;
            std::cin >> operationCase;
            std::cout << endl;
            switch (operationCase) {
            case 1:
                t->makeTree();
                break;
            case 2:
            {
                getchar();
                string inputString;
                getline(cin, inputString);
                string stackFunctions[10];
                int cnt = 0;
                stringstream ss(inputString);
                string word;
                while (ss >> word)
                    stackFunctions[cnt++] = word;
                t->insert(stackFunctions, cnt);
                break;
            }
            case 3:
                t->preOrderTraversal();
                std::cout << endl;
                break;
            case 4:
            {
                getchar();
                string inputString;
                getline(cin, inputString);
                string stackFunctions[10];
                int cnt = 0;
                stringstream ss(inputString);
                string word;
                while (ss >> word)
                    stackFunctions[cnt++] = word;
                t->deletePS(stackFunctions, cnt);
                break;
            }
            case 5:
                t->freeTree();
                break;
            case 9:
            {
                doTree = false;
                break;
            }
            default:
                break;
            }
        }
        getchar();
        bool doGraph = true;
        Graph* g = new Graph(*t);
        while (doGraph) {
            int operationCase;
            std::cout << "1. Kreiranje grafa" << endl;
            std::cout << "2. Ispis grafa" << endl;
            std::cout << "3. Provera da li postoji rekurzija" << endl;
            std::cout << "9. Povratak na rad sa stablom" << endl;
            std::cout << "0. Prekid programa" << endl;
            cin >> operationCase;
            switch (operationCase)
            {
            case 1:
                g->makeGraph(*t);
                break;
            case 2:
                g->dfs();
                std::cout << endl;
                break;
            case 3:
                g->findRecursion(); 
                break;
            case 9:
                doGraph = false;
                delete g;
                break;
            case 0:
                t->freeTree();
                delete t;
                delete g;
                return 0;
            default:
                break;
            }
        }
    }
	return 0;
}