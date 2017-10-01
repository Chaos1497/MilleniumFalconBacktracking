#ifndef MILLENNIUMFALCONBACKTRACKING_TILED_H
#define MILLENNIUMFALCONBACKTRACKING_TILED_H

#include "Matrix.h"
#include "Sprite.h"

class Tiled{
private:
    int x, y, size, isSolid;
    char* resource;
    Sprite *sprite;
public:
    Tiled(char* resource, int x, int y, int size, int isSolid=0);
    ~Tiled();
    void draw();
    void setSolid();
    char* getResource();
    int getIsSolid();
    int getX();
    int getY();
    int getSize();
};

#endif //MILLENNIUMFALCONBACKTRACKING_TILED_H