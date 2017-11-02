#include "Node.h"

Node::Node(int pPosI, int pPosJ, bool pWall) {

    this->setPosI(pPosI);
    this->setPosJ(pPosJ);
    this->setWalkable(pWall);
    this->setSigte(0);
    this->setSalto(0);
    this->setCostLast(0);
    this->setPreviousNode(nullptr);
    this->_neighbors = new PList<Node*>();

}
Node::~Node() {}

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
int Node::getSigte() const {
    return this->_costSigte;
}
void Node::setSigte(int pcostSigte) {
    this->_costSigte = pcostSigte;
}

double Node::getLast() const {
    return this->_last;
}
void Node::setSalto(double pCostH) {
    this->_last = pCostH;
}

double Node::getTotal() const {
    return this->_total;
}
void Node::setCostLast(double pCostF) {
    this->_total = pCostF;
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