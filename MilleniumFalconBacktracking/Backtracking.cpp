#include "Backtracking.h"

Backtracking::Backtracking() {
    this->_openSet = new PList<Node*>();
    this->_closeSet = new PList<Node*>();
    this->_back = new PList<Node*>();
}

Backtracking::~Backtracking() {}

double Backtracking::calculateHeuristics(Node* pStartNode, Node* pEndNode) {
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

void Backtracking::initiateNodesMap(int** pMap, int pRows, int pColumns) {
    //Create the array of nodes
    this->_nodeMap = new Node**[pRows];
    for(int i = 0; i < pRows; i++) {
        this->_nodeMap[i] = new Node*[pColumns];
    }
    //Fill the matrix with nodes
    for(int i = 0; i < pRows; i++) {
        for(int j = 0; j < pColumns; j++) {
            this->_nodeMap[i][j] = new Node(i, j, pMap[i][j]);
        }
    }
    //Established the neighbors of each node in the matrix
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
            if(this->_openSet->get(i)->getCostF() < this->_openSet->get(bestNodePosition)->getCostF())
                bestNodePosition = i;
        }
        Node* currentNode = this->_openSet->get(bestNodePosition);
        if(currentNode == endNode){
            Node* tempNode = currentNode;
            this->_back->insert(tempNode);
            while(tempNode->getPreviousNode()) {
                this->_back->insert(tempNode->getPreviousNode());
                tempNode = tempNode->getPreviousNode();
            }
            break;
        }
        this->_openSet->remove(bestNodePosition);
        this->_closeSet->insert(currentNode);
        for(int i = 0; i < currentNode->getNeighbors()->size(); i++) {
            if(!(this->inCloseSet(currentNode->getNeighbors()->get(i))) && !(currentNode->getNeighbors()->get(i)->getWalkable())) {
                int tmpCostG = currentNode->getCostG() + 1;
                if (this->inOpenSet(currentNode->getNeighbors()->get(i))) {
                    if (tmpCostG < currentNode->getNeighbors()->get(i)->getCostG())
                        currentNode->getNeighbors()->get(i)->setCostG(tmpCostG);
                }
                else {
                    currentNode->getNeighbors()->get(i)->setCostG(tmpCostG);
                    this->_openSet->insert(currentNode->getNeighbors()->get(i));
                }
                currentNode->getNeighbors()->get(i)->setCostH(this->calculateHeuristics(currentNode->getNeighbors()->get(i), endNode));
                currentNode->getNeighbors()->get(i)->setCostF((currentNode->getNeighbors()->get(i)->getCostG() + currentNode->getNeighbors()->get(i)->getCostH()));
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