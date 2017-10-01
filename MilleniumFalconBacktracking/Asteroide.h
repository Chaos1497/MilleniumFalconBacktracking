#ifndef MILLENNIUMFALCONBACKTRACKING_ASTEROIDE_H
#define MILLENNIUMFALCONBACKTRACKING_ASTEROIDE_H

#include "Falcon.h"
#include "Entidad.h"

class Asteroide : public Entity{
private:
    List<Falcon*> *targets;
public:
    Asteroide(char* resource,int row, int column, int width, int height, Mapa *m);
    ~Asteroide();
    void draw();
};

#endif //MILLENNIUMFALCONBACKTRACKING_ASTEROIDE_H