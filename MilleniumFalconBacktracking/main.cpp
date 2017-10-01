#include <iostream>
#include <cstdlib>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "Mapa.h"
#include "Falcon.h"
#include "PList.h"
#include "Backtracking.h"
#include "Asteroide.h"
#include "DeathStar.h"

using namespace std;

bool run=true;//Booleano que ejecuta el loop

ALLEGRO_DISPLAY *display;//Variable global ventana, se utiliza para mostrar el juego
ALLEGRO_EVENT_QUEUE *event_queue;//Variable de la cola de eventos
ALLEGRO_FONT *font;
ALLEGRO_TIMER *timer;
ALLEGRO_EVENT events;
ALLEGRO_BITMAP *player_sprite;
ALLEGRO_KEYBOARD_STATE keyState;
Mapa *zone;
Falcon *falcon;
Asteroide *asteroide1, *asteroide2,*asteroide3, *asteroide4, *asteroide5, *asteroide6, *asteroide7, *asteroide8, *asteroide9, *asteroide10, *asteroide11, *asteroide12, *asteroide13,*asteroide14, *asteroide15, *asteroide16,  *asteroide17, *asteroide18, *asteroide19, *asteroide20, *asteroide21, *asteroide22;
DeathStar *estrella;
Backtracking *backtracking;
int** zoneSolids = new int*[2];//Da los sólidos de la zona
int padondevaFila = 5, padondevaColumna = 13;
// /Constantes definidas (Colores, dimensiones, medidas, entre otros)
#define screen_width 850
#define screen_height 600
#define SPACE al_map_rgb(0, 13, 26)
#define WHITE al_map_rgb(255, 255, 255)
#define FPS 60.0

void calculateBack(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), padondevaFila, padondevaColumna);

    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack1(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 4, 0);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack2(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 6, 1);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack3(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 3, 2);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack4(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 8, 3);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack5(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 5, 4);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack6(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 1, 4);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack7(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 7, 6);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack8(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 4, 6);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack9(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 2, 7);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack10(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 6, 8);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack11(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 0, 8);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack12(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 4, 9);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack13(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 8, 10);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack14(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 1, 10);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack15(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 6, 12);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack16(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 3, 12);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack17(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 1, 13);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}
void calculateBack18(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 9, 7);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack19(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 9, 13);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack20(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 7, 14);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack21(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 9, 0);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}

void calculateBack22(Entity *entity, Mapa *map){
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 10; ++c) {
            zoneSolids[r][c] = map->getTiledAt(r,c).getIsSolid();
        }
    }

    PList<PList<int>> back = backtracking->getBack(zoneSolids, map->getRows(), map->getColumns(), entity->getCurrentRow(), entity->getCurrentColumn(), 0, 0);
    for (int m = 0; m < back.size(); ++m) {
        cout << back.get(m).get(0) << " " << back.get(m).get(1) << endl;
        entity->moveAt(back.get(m).get(0),back.get(m).get(1));
    }
}


void initialize(){
    al_init();//Inicia componentes básicos para usar alegro
    al_init_font_addon();//Inicializa los formato de letra
    al_init_ttf_addon();//Inicializa los archivos de tipos de letras
    al_init_primitives_addon();//Inicializa formas primitivas(rectángulos, triángulos, círculos, entre otros)
    al_install_keyboard();//Inicializa el teclado
    al_init_image_addon();//Inicializa imagenes
    backtracking = new Backtracking();
    font = al_load_font("game_font.ttf", 12, NULL);//Establece el formato de letra
    display = al_create_display(screen_width, screen_height);//Crea ventana con dimensiones
    timer = al_create_timer(1.0/FPS);//Temporizador de frames del loop
    event_queue = al_create_event_queue();//Cola de eventos (del teclado, mouse, display, etc)

    al_register_event_source(event_queue,al_get_keyboard_event_source());//Registra los eventos de teclado en la cola
    al_register_event_source(event_queue,al_get_display_event_source(display));//Registrando eventos display en la cola
    al_register_event_source(event_queue,al_get_timer_event_source(timer));//Registra evento del temporizador en la cola
    al_start_timer(timer);//Inicia el temporizador del loop

    //inicializador del arreglo de los sólidos
    for (int r = 0; r < 10; ++r) {
        zoneSolids[r] = new int[15];
    }

    char* map="0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,/0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,/0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,/0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,/0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,/0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,/0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,/0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,/0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,/0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,/";
    zone = new Mapa(50,50,10,15,50);
    zone->addBitmap("Fondo.png");
    zone->setBackground(map,',','/');

    falcon = new Falcon("MilleniumFalcon.png", 2, 1, 50, 50, zone);
    falcon->addAnimation("RIGHT",0,4);
    falcon->addAnimation("LEFT",1,4);
    falcon->addAnimation("DOWN",2,4);
    falcon->addAnimation("UP",3,4);

    asteroide1 = new Asteroide("Asteroide.png", 5, 0, 40, 40, zone);
    asteroide1->addAnimation("RIGHT",0,4);
    asteroide1->addAnimation("LEFT",1,4);
    asteroide1->addAnimation("DOWN",2,4);
    asteroide1->addAnimation("UP",3,4);

    asteroide2 = new Asteroide("Asteroide.png", 7, 1, 40, 40, zone);
    asteroide2->addAnimation("RIGHT",0,4);
    asteroide2->addAnimation("LEFT",1,4);
    asteroide2->addAnimation("DOWN",2,4);
    asteroide2->addAnimation("UP",3,4);

    asteroide3 = new Asteroide("Asteroide.png", 4, 2, 40, 40, zone);
    asteroide3->addAnimation("RIGHT",0,4);
    asteroide3->addAnimation("LEFT",1,4);
    asteroide3->addAnimation("DOWN",2,4);
    asteroide3->addAnimation("UP",3,4);

    asteroide4 = new Asteroide("Asteroide.png", 9, 3, 40, 40, zone);
    asteroide4->addAnimation("RIGHT",0,4);
    asteroide4->addAnimation("LEFT",1,4);
    asteroide4->addAnimation("DOWN",2,4);
    asteroide4->addAnimation("UP",3,4);

    asteroide5 = new Asteroide("Asteroide.png", 6, 4, 40, 40, zone);
    asteroide5->addAnimation("RIGHT",0,4);
    asteroide5->addAnimation("LEFT",1,4);
    asteroide5->addAnimation("DOWN",2,4);
    asteroide5->addAnimation("UP",3,4);

    asteroide6 = new Asteroide("Asteroide.png", 2, 4, 40, 40, zone);
    asteroide6->addAnimation("RIGHT",0,4);
    asteroide6->addAnimation("LEFT",1,4);
    asteroide6->addAnimation("DOWN",2,4);
    asteroide6->addAnimation("UP",3,4);

    asteroide7 = new Asteroide("Asteroide.png", 8, 6, 40, 40, zone);
    asteroide7->addAnimation("RIGHT",0,4);
    asteroide7->addAnimation("LEFT",1,4);
    asteroide7->addAnimation("DOWN",2,4);
    asteroide7->addAnimation("UP",3,4);

    asteroide8 = new Asteroide("Asteroide.png", 5, 6, 40, 40, zone);
    asteroide8->addAnimation("RIGHT",0,4);
    asteroide8->addAnimation("LEFT",1,4);
    asteroide8->addAnimation("DOWN",2,4);
    asteroide8->addAnimation("UP",3,4);

    asteroide9 = new Asteroide("Asteroide.png", 3, 7, 40, 40, zone);
    asteroide9->addAnimation("RIGHT",0,4);
    asteroide9->addAnimation("LEFT",1,4);
    asteroide9->addAnimation("DOWN",2,4);
    asteroide9->addAnimation("UP",3,4);

    asteroide10 = new Asteroide("Asteroide.png", 7, 8, 40, 40, zone);
    asteroide10->addAnimation("RIGHT",0,4);
    asteroide10->addAnimation("LEFT",1,4);
    asteroide10->addAnimation("DOWN",2,4);
    asteroide10->addAnimation("UP",3,4);

    asteroide11 = new Asteroide("Asteroide.png", 1, 8, 40, 40, zone);
    asteroide11->addAnimation("RIGHT",0,4);
    asteroide11->addAnimation("LEFT",1,4);
    asteroide11->addAnimation("DOWN",2,4);
    asteroide11->addAnimation("UP",3,4);

    asteroide12 = new Asteroide("Asteroide.png", 5, 9, 40, 40, zone);
    asteroide12->addAnimation("RIGHT",0,4);
    asteroide12->addAnimation("LEFT",1,4);
    asteroide12->addAnimation("DOWN",2,4);
    asteroide12->addAnimation("UP",3,4);

    asteroide13 = new Asteroide("Asteroide.png", 9, 10, 40, 40, zone);
    asteroide13->addAnimation("RIGHT",0,4);
    asteroide13->addAnimation("LEFT",1,4);
    asteroide13->addAnimation("DOWN",2,4);
    asteroide13->addAnimation("UP",3,4);

    asteroide14 = new Asteroide("Asteroide.png", 2, 10, 40, 40, zone);
    asteroide14->addAnimation("RIGHT",0,4);
    asteroide14->addAnimation("LEFT",1,4);
    asteroide14->addAnimation("DOWN",2,4);
    asteroide14->addAnimation("UP",3,4);

    asteroide15 = new Asteroide("Asteroide.png", 7, 12, 40, 40, zone);
    asteroide15->addAnimation("RIGHT",0,4);
    asteroide15->addAnimation("LEFT",1,4);
    asteroide15->addAnimation("DOWN",2,4);
    asteroide15->addAnimation("UP",3,4);

    asteroide16 = new Asteroide("Asteroide.png", 4, 12, 40, 40, zone);
    asteroide16->addAnimation("RIGHT",0,4);
    asteroide16->addAnimation("LEFT",1,4);
    asteroide16->addAnimation("DOWN",2,4);
    asteroide16->addAnimation("UP",3,4);

    asteroide17 = new Asteroide("Asteroide.png", 3, 13, 40, 40, zone);
    asteroide17->addAnimation("RIGHT",0,4);
    asteroide17->addAnimation("LEFT",1,4);
    asteroide17->addAnimation("DOWN",2,4);
    asteroide17->addAnimation("UP",3,4);

    asteroide18 = new Asteroide("Asteroide.png", 9, 8, 40, 40, zone);
    asteroide18->addAnimation("RIGHT",0,4);
    asteroide18->addAnimation("LEFT",1,4);
    asteroide18->addAnimation("DOWN",2,4);
    asteroide18->addAnimation("UP",3,4);

    asteroide19 = new Asteroide("Asteroide.png", 9, 14, 40, 40, zone);
    asteroide19->addAnimation("RIGHT",0,4);
    asteroide19->addAnimation("LEFT",1,4);
    asteroide19->addAnimation("DOWN",2,4);
    asteroide19->addAnimation("UP",3,4);

    asteroide20 = new Asteroide("Asteroide.png", 8, 14, 40, 40, zone);
    asteroide20->addAnimation("RIGHT",0,4);
    asteroide20->addAnimation("LEFT",1,4);
    asteroide20->addAnimation("DOWN",2,4);
    asteroide20->addAnimation("UP",3,4);

    asteroide21 = new Asteroide("Asteroide.png", 9, 1, 40, 40, zone);
    asteroide21->addAnimation("RIGHT",0,4);
    asteroide21->addAnimation("LEFT",1,4);
    asteroide21->addAnimation("DOWN",2,4);
    asteroide21->addAnimation("UP",3,4);

    asteroide22 = new Asteroide("Asteroide.png", 1, 0, 40, 40, zone);
    asteroide22->addAnimation("RIGHT",0,4);
    asteroide22->addAnimation("LEFT",1,4);
    asteroide22->addAnimation("DOWN",2,4);
    asteroide22->addAnimation("UP",3,4);

    estrella = new DeathStar("DeathStar.png",5,14,80,80,zone);

    calculateBack(falcon,zone);
    calculateBack1(asteroide1,zone);
    calculateBack2(asteroide2,zone);
    calculateBack3(asteroide3,zone);
    calculateBack4(asteroide4,zone);
    calculateBack5(asteroide5,zone);
    calculateBack6(asteroide6,zone);
    calculateBack7(asteroide7,zone);
    calculateBack8(asteroide8,zone);
    calculateBack9(asteroide9,zone);
    calculateBack10(asteroide10,zone);
    calculateBack11(asteroide11,zone);
    calculateBack12(asteroide12,zone);
    calculateBack13(asteroide13,zone);
    calculateBack14(asteroide14,zone);
    calculateBack15(asteroide15,zone);
    calculateBack16(asteroide16,zone);
    calculateBack17(asteroide17,zone);
    calculateBack18(asteroide18,zone);
    calculateBack19(asteroide19,zone);
    calculateBack20(asteroide20,zone);
    calculateBack21(asteroide21,zone);
    calculateBack22(asteroide22,zone);
}

//Manejador de eventos. Aquí se establecen y administran eventos de teclado, mouse, display, entre otros.
void eventsHandler(){
    //Evento que finaliza el loop al cerrar la ventana
    if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        run = false;
    }
}

//Loop que dibuja y actualiza los componentes del juego
void loop(){
    al_draw_text(font, WHITE, screen_width / 2, 0, ALLEGRO_ALIGN_CENTER, "millenium falcon backtracking");//Muestra texto en pantalla
    al_flip_display();//Refresca pantalla
    al_clear_to_color(SPACE);//Repinta fondo
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    initialize();
    while(run) {
        al_wait_for_event(event_queue, &events);
        al_get_keyboard_state(&keyState);
        eventsHandler();
        zone->draw();
        asteroide1->draw();
        asteroide2->draw();
        asteroide3->draw();
        asteroide4->draw();
        asteroide5->draw();
        asteroide6->draw();
        asteroide7->draw();
        asteroide8->draw();
        asteroide9->draw();
        asteroide10->draw();
        asteroide11->draw();
        asteroide12->draw();
        asteroide13->draw();
        asteroide14->draw();
        asteroide15->draw();
        asteroide16->draw();
        asteroide17->draw();
        asteroide18->draw();
        asteroide19->draw();
        asteroide20->draw();
        asteroide21->draw();
        asteroide22->draw();
        estrella->draw();
        falcon->draw();
        loop();
    }
    al_destroy_display(display);
    return 0;
}