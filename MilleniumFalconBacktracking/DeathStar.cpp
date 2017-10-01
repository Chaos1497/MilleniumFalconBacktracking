#include "DeathStar.h"
#include "Entidad.h"

DeathStar::DeathStar(char *resource, int row, int column, int width, int height, Mapa *m) : Entity(resource,row,column,width,height,m) {
    plane->setSolidTiledAt(row, column, 1);
    m->setEntityAt(row,column,"DEATHSTAR");
}
void DeathStar::draw() {
    Entity::draw();
}

void DeathStar::setRange(int range){
    this->range = range;
}
