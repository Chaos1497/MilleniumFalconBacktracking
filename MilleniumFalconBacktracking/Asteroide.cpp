#include "Asteroide.h"

Asteroide::Asteroide(char *resource, int row, int column, int width, int height, Mapa *m):Entity(resource,row,column,width,height,m){
    plane->setSolidTiledAt(row, column, 1);
    m->setEntityAt(row,column,"ASTEROIDE");
    setSpeed(100);
}
void Asteroide::draw() {
    Entity::draw();
    Entity::moving();
}