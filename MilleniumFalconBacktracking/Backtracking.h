#ifndef MILLENNIUMFALCONBACKTRACKING_H
#define MILLENNIUMFALCONBACKTRACKING_H
#include <iostream>
#include "Node.h"
#include <cmath>
using namespace std;
class Backtracking {
private:
    //Attributes
    Node*** _nodeMap;
    PList<Node*>* _openSet;
    PList<Node*>* _closeSet;
    PList<Node*>* _back;

    //Methods
    double Heuristics(Node*, Node*);
    bool inOpenSet(Node*);
    bool inCloseSet(Node*);
    void initiateNodesMap(int**, int, int);
    void cleanLists();
public:
    Backtracking();
    ~Backtracking();
    PList<PList<int>> getBack(int**, int, int, int, int, int, int);
};

#endif //MILLENNIUMFALCONBACKTRACKING_H