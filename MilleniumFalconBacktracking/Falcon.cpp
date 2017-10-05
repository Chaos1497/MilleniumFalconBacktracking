#include "Falcon.h"

Falcon::Falcon(char* resource, int row, int column, int width, int height,Mapa *m)  : Entity(resource,row,column,width,height,m){
    plane->setSolidTiledAt(row, column, 1);
    m->setEntityAt(row,column,"FALCON");
    setSpeed(10);
}

void Falcon::draw(){
    Entity::moving();
    Entity::draw();
}
