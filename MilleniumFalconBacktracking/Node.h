#ifndef MILLENNIUMFALCONBACKTRACKING_NODE_H
#define MILLENNIUMFALCONBACKTRACKING_NODE_H

#include "PList.h"

class Node {

private:
    //Attributes
    int _posI;
    int _posJ;
    bool _walkable;
    int _costSigte;
    double _last;
    double _total;
    Node* _previous;
    PList<Node*>* _neighbors;

public:

    Node(int, int, bool);
    virtual ~Node();

    int getPosI() const;
    void setPosI(int);

    int getPosJ() const;
    void setPosJ(int);

    bool getWalkable() const;
    void setWalkable(bool);

    int getSigte() const;
    void setSigte(int);

    double getLast() const;
    void setSalto(double);

    double getTotal() const;
    void setCostLast(double);

    Node* getPreviousNode() const;
    void setPreviousNode(Node*);

    void addNeighbors(Node***, int, int);

    PList<Node*>* getNeighbors() const;

};

#endif //MILLENNIUMFALCONBACKTRACKING_NODE_H