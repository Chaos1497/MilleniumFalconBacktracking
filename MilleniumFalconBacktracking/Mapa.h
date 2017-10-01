#ifndef MILLENNIUMFALCONBACKTRACKING_MAPA_H
#define MILLENNIUMFALCONBACKTRACKING_MAPA_H

#include <iostream>
#include <math.h>
#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Tiled.h"

class Mapa {
private:
    int x, y, rows, columns, size_tiled;
    Matrix<Tiled*> *matrix;
    Matrix<char*> *IDs;
    ALLEGRO_BITMAP *tiled;
    List<char*> *bitmaps;
public:
    Mapa(int x, int y, int rows, int columns, int size_tiled);
    ~Mapa();
    void draw();
    int getTiledSize();
    int getX();
    int getY();
    int getRows();
    int getColumns();
    char* getEntityAt(int row,int column);
    Tiled getTiledAt(int row, int column);
    void setSolidTiledAt(int row, int column, int isSolid);
    void setEntityAt(int row, int column, char* id_entity);
    void setBackground(char* map, char div_column, char div_row);
    void addBitmap(char* resource);
};

#endif //MILLENNIUMFALCONBACKTRACKING_MAPA_H