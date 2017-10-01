#include "Node.h"

Node::Node(int pPosI, int pPosJ, bool pWall) {

    this->setPosI(pPosI);
    this->setPosJ(pPosJ);
    this->setWalkable(pWall);
    this->setCostG(0);
    this->setCostH(0);
    this->setCostF(0);
    this->setPreviousNode(nullptr);
    this->_neighbors = new PList<Node*>();

}
Node::~Node() {
    //?????
}


int Node::getPosI() const{
    return this->_posI;
}
void Node::setPosI(int pPosI){
    this->_posI = pPosI;
}


int Node::getPosJ() const {
    return this->_posJ;
}
void Node::setPosJ(int pPosJ) {
    this->_posJ = pPosJ;
}


bool Node::getWalkable() const {
    return this->_walkable;
}
void Node::setWalkable(bool pWalkable) {
    this->_walkable = pWalkable;
}


int Node::getCostG() const {
    return this->_costG;
}
void Node::setCostG(int pCostG) {
    this->_costG = pCostG;
}


double Node::getCostH() const {
    return this->_costH;
}
void Node::setCostH(double pCostH) {
    this->_costH = pCostH;
}


double Node::getCostF() const {
    return this->_costF;
}
void Node::setCostF(double pCostF) {
    this->_costF = pCostF;
}

Node* Node::getPreviousNode() const {
    return this->_previous;
}
void Node::setPreviousNode(Node* pNode) {
    this->_previous = pNode;
}

void Node::addNeighbors(Node*** pNodeMap, int pRows, int pColumns) {

    if(this->getPosJ() < (pColumns - 1))
        this->_neighbors->insert(pNodeMap[this->getPosI()][this->getPosJ() + 1]);

    if(this->getPosI() < (pRows - 1))
        this->_neighbors->insert(pNodeMap[this->getPosI() + 1][this->getPosJ()]);

    if(this->getPosI() > 0)
        this->_neighbors->insert(pNodeMap[this->getPosI() - 1][this->getPosJ()]);

    if(this->getPosJ() > 0)
        this->_neighbors->insert(pNodeMap[this->getPosI()][this->getPosJ() - 1]);
}

PList<Node*>* Node::getNeighbors() const {
    return this->_neighbors;
}