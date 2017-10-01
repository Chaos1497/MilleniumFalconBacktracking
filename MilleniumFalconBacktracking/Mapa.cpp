#include "Mapa.h"

Mapa::Mapa(int x,int y, int rows, int columns, int size_tiled){
    this->x=x;
    this->y=y;
    this->rows=rows;
    this->columns=columns;
    this->size_tiled=size_tiled;
    matrix = new Matrix<Tiled*>(rows,columns);
    IDs = new Matrix<char*>(rows,columns);
    //Llena la matriz de entidades con char* vacios para evitar errores
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            IDs->addAt(r,c,"");
        }
    }
    bitmaps = new List<char*>();
}

void Mapa::addBitmap(char* resource){
    bitmaps->Insert(resource);
}

void Mapa::setBackground(char* map, char div_column, char div_row) {
    int temp = 0, temp_row = 0, temp_column = 0, u = 0, caracter = 0, integer = 0;
    while (temp < rows * columns) {
        if (map[caracter] == div_column) {
            matrix->addAt(temp_row, temp_column, new Tiled(bitmaps->Get(integer), x+temp_column*size_tiled, y+temp_row*size_tiled, size_tiled));
            cout << "setting on position " << temp_row << " " << temp_column << endl;
            temp_column++;
            u = 0;
            integer = 0;
            temp++;
        } else if (map[caracter] == div_row) {
            temp_row++;
            temp_column = 0;
        } else {
            integer += (map[caracter] - '0') * pow(10, u);
            u++;
        }
        caracter++;
    }
}

void  Mapa::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix->getData(i,j)->draw();
        }
    }
}

void Mapa::setSolidTiledAt(int row, int column, int isSolid) {
    matrix->addAt(row, column, new Tiled(getTiledAt(row,column).getResource(), getTiledAt(row,column).getX(), getTiledAt(row,column).getY(), getTiledAt(row,column).getSize(), isSolid));
}

Tiled Mapa::getTiledAt(int row, int column) {
    return *matrix->getData(row,column);
}

void Mapa::setEntityAt(int row, int column, char *id_entity) { IDs->addAt(row, column, id_entity); }
char* Mapa::getEntityAt(int row, int column) { return IDs->getData(row, column); }
int Mapa::getRows() { return rows; }
int Mapa::getColumns() { return columns; }
int Mapa::getX(){ return x; }
int Mapa::getY() { return y; }
int Mapa::getTiledSize() { return size_tiled; }