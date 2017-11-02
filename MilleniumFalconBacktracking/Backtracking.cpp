#include "Backtracking.h"

Backtracking::Backtracking() {
    this->_openSet = new PList<Node*>();
    this->_closeSet = new PList<Node*>();
    this->_back = new PList<Node*>();
}

Backtracking::~Backtracking() {}

double Backtracking::Heuristics(Node* pStartNode, Node* pEndNode) {
    int x = pEndNode->getPosI() - pStartNode->getPosI();
    int y = pEndNode->getPosJ() - pStartNode->getPosJ();
    return std::sqrt((x*x) + (y*y));
}

bool Backtracking::inOpenSet(Node* pNode) {
    for(int i = 0; i < this->_openSet->size(); i++) {
        if(this->_openSet->get(i) == pNode)
            return true;
    }
    return false;
}

bool Backtracking::inCloseSet(Node* pNode) {
    for(int i = 0; i < this->_closeSet->size(); i++) {
        if(this->_closeSet->get(i) == pNode)
            return true;
    }
    return false;
}

void Backtracking::initiateNodesMap(int** pMap, int pRows, int pColumns){
    this->_nodeMap = new Node**[pRows];
    for(int i = 0; i < pRows; i++) {
        this->_nodeMap[i] = new Node*[pColumns];
    }
    for(int i = 0; i < pRows; i++) {
        for(int j = 0; j < pColumns; j++) {
            this->_nodeMap[i][j] = new Node(i, j, pMap[i][j]);
        }
    }
    for(int i = 0; i < pRows; i++) {
        for(int j = 0; j < pColumns; j++) {
            this->_nodeMap[i][j]->addNeighbors(this->_nodeMap, pRows, pColumns);
        }
    }
}

void Backtracking::cleanLists() {
    this->_openSet->clear();
    this->_closeSet->clear();
    this->_back->clear();
}

PList<PList<int>> Backtracking::getBack(int** pMap, int pRows, int pColumns, int pStartI, int pStartJ, int pEndI, int pEndJ) {
    this->initiateNodesMap(pMap, pRows, pColumns);
    Node* startNode = this->_nodeMap[pStartI][pStartJ];
    Node* endNode = this->_nodeMap[pEndI][pEndJ];
    this->_openSet->insert(startNode);
    while(this->_openSet->size() > 0) {
        int bestNodePosition = 0;
        for(int i = 0; i < this->_openSet->size(); i++) {
            if(this->_openSet->get(i)->getTotal() < this->_openSet->get(bestNodePosition)->getTotal())
                bestNodePosition = i;
        }
        Node* currentNode = this->_openSet->get(bestNodePosition);
        if(currentNode == endNode){
            Node* tempNode = currentNode;
            this->_back->insert(tempNode);
            while(tempNode->getPreviousNode()) {
                cout<<tempNode;
                this->_back->insert(tempNode->getPreviousNode());
                tempNode = tempNode->getPreviousNode();
            }
            break;
        }
        this->_openSet->remove(bestNodePosition);
        this->_closeSet->insert(currentNode);
        for(int i = 0; i < currentNode->getNeighbors()->size(); i++) {
            if(!(this->inCloseSet(currentNode->getNeighbors()->get(i))) && !(currentNode->getNeighbors()->get(i)->getWalkable())) {
                int tmpSigte = currentNode->getSigte() + 1;
                if (this->inOpenSet(currentNode->getNeighbors()->get(i))) {
                    if (tmpSigte < currentNode->getNeighbors()->get(i)->getSigte())
                        currentNode->getNeighbors()->get(i)->setSigte(tmpSigte);
                }
                else {
                    currentNode->getNeighbors()->get(i)->setSigte(tmpSigte);
                    this->_openSet->insert(currentNode->getNeighbors()->get(i));
                }
                currentNode->getNeighbors()->get(i)->setSalto(this->Heuristics(currentNode->getNeighbors()->get(i), endNode));
                currentNode->getNeighbors()->get(i)->setCostLast((currentNode->getNeighbors()->get(i)->getSigte() + currentNode->getNeighbors()->get(i)->getLast()));
                currentNode->getNeighbors()->get(i)->setPreviousNode(currentNode);
            }
        }
    }

    PList<PList<int>> positionBack;

    if(this->_openSet->size() <= 0) {
        cout << "NO Solution Founded " << endl;
        this->cleanLists();
        return positionBack;
    }
    else {
        for(int i = ((int)this->_back->size() - 1); i >= 0; i--) {
            PList<int> positions;
            positions.insert(this->_back->get(i)->getPosI());
            positions.insert(this->_back->get(i)->getPosJ());
            positionBack.insert(positions);
        }
        cout << "Solution Founded" << endl;
        this->cleanLists();
        return positionBack;
    }
}