#ifndef MILLENNIUMFALCONBACKTRACKING_FALCON_H
#define MILLENNIUMFALCONBACKTRACKING_FALCON_H

#include "Entidad.h"

class Falcon : public Entity{
private:
    char* name;
public:
    Falcon(char* resource,int row, int column, int width, int height, Mapa *m);
    ~Falcon();
    void draw();
};
#endif //MILLENNIUMFALCONBACKTRACKING_FALCON_H
