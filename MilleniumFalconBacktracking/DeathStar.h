//
// Created by esteban on 26/09/17.
//

#ifndef MILLENNIUMFALCONBACKTRACKING_DEATHSTAR_H
#define MILLENNIUMFALCONBACKTRACKING_DEATHSTAR_H


#include "Falcon.h"
#include "Entidad.h"

class DeathStar : public Entity{
private:
    List<Falcon*> *targets;
    char* target;
    int range=3, timer=0;
public:
    DeathStar(char* resource,int row, int column, int width, int height, Mapa *m);
    ~DeathStar();
    void draw();
    void setTarget(char *target);
    void setRange(int range);
    void attack(Falcon *entity);
    char* getTarget();
    int getRange();
};



#endif //MILLENNIUMFALCONBACKTRACKING_DEATHSTAR_H
