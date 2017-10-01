#include "Backtracking.h"

Backtracking::Backtracking() {
    this->_openSet = new PList<Node*>();
    this->_closeSet = new PList<Node*>();
    this->_path = new PList<Node*>();
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
    this->_path->clear();
}

PList<PList<int>> Backtracking::getBack(int** pMap, int pRows, int pColumns, int pStartI, int pStartJ, int pEndI, int pEndJ) {
    this->initiateNodesMap(pMap, pRows, pColumns);
    Node* startNode = this->_nodeMap[pStartI][pStartJ];
    Node* endNode = this->_nodeMap[pEndI][pEndJ];
    //Inserts the starting node into the list of nodes for evaluating (openSet)
    this->_openSet->insert(startNode);
    //If there are nodes for evaluating
    while(this->_openSet->size() > 0) {
        int bestNodePosition = 0;
        //Looks for the best node in the list of nodes for evaluating (openSet)
        for(int i = 0; i < this->_openSet->size(); i++) {
            if(this->_openSet->get(i)->getCostF() < this->_openSet->get(bestNodePosition)->getCostF())
                //Saves the position of the best node
                bestNodePosition = i;
        }
        //Our current node will be which was chosen as the best (the one with the lowest cost F)
        Node* currentNode = this->_openSet->get(bestNodePosition);
        //If the final node is reached (end of the back)
        if(currentNode == endNode){
            //Saves the current node in a temporary node
            Node* tempNode = currentNode;
            //Inserts the temporary node into the back list
            this->_path->insert(tempNode);
            //If the temporary node has a previous node
            while(tempNode->getPreviousNode()) {
                //Inserts the temporary node into the back list
                this->_path->insert(tempNode->getPreviousNode());
                //The temporary node will be the previous to the current
                tempNode = tempNode->getPreviousNode();
            }
            break;
        }

        //Removes the winning node (best node) in the list of nodes for evaluating
        this->_openSet->remove(bestNodePosition);
        //Inserts the winning node (best node) into the list of nodes already evaluated
        this->_closeSet->insert(currentNode);
        //Checks all the neighbors of the current node
        for(int i = 0; i < currentNode->getNeighbors()->size(); i++) {
            //If the current neighbor has not been evaluated and is not an obstacle (we can walk over it)
            if(!(this->inCloseSet(currentNode->getNeighbors()->get(i))) && !(currentNode->getNeighbors()->get(i)->getWalkable())) {
                //Estimates the G cost that the current neighbor will have
                int tmpCostG = currentNode->getCostG() + 1;
                //If the current neighbor is already in the list of nodes for evaluating (openSet)
                if (this->inOpenSet(currentNode->getNeighbors()->get(i))) {
                    //If the estimated G cost is better than that one it had
                    if (tmpCostG < currentNode->getNeighbors()->get(i)->getCostG())
                        //Defines the new G cost of the current neighbor
                        currentNode->getNeighbors()->get(i)->setCostG(tmpCostG);
                }
                else {
                    //Defines the G cost of the current neighbor
                    currentNode->getNeighbors()->get(i)->setCostG(tmpCostG);
                    //Inserts the current neighbor in the list of nodes for evaluating (openSet)
                    this->_openSet->insert(currentNode->getNeighbors()->get(i));
                }
                //Defines the H cost of the current neighbor
                currentNode->getNeighbors()->get(i)->setCostH(this->calculateHeuristics(currentNode->getNeighbors()->get(i), endNode));
                //Defines the F cost of the current neighbor
                currentNode->getNeighbors()->get(i)->setCostF((currentNode->getNeighbors()->get(i)->getCostG() + currentNode->getNeighbors()->get(i)->getCostH()));
                //Defines the previous node of the current neighbor, who will be our current node
                currentNode->getNeighbors()->get(i)->setPreviousNode(currentNode);
            }
        }
    }

    PList<PList<int>> positionBack;

    //If all nodes were evaluated and we never got to the goal
    if(this->_openSet->size() <= 0) {
        cout << "NO Solution Founded " << endl;
        this->cleanLists();
        return positionBack;
    }
    else {
        for(int i = ((int)this->_path->size() - 1); i >= 0; i--) {
            PList<int> positions;
            positions.insert(this->_path->get(i)->getPosI());
            positions.insert(this->_path->get(i)->getPosJ());
            positionBack.insert(positions);
        }
        cout << "Solution Founded" << endl;
        this->cleanLists();
        return positionBack;
    }
}