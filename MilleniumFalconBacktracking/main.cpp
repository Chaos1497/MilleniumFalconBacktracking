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
Asteroide *asteroide1, *asteroide2,*asteroide3, *asteroide4, *asteroide5, *asteroide6, *asteroide7, *asteroide8, *asteroide9, *asteroide10, *asteroide11, *asteroide12, *asteroide13,*asteroide14, *asteroide15, *asteroide16,  *asteroide17, *asteroide18, *asteroide19, *asteroide20, *asteroide21;
DeathStar *estrella;
Backtracking *backtracking;
int** zoneSolids = new int*[2];//Da los sólidos de la zona
int padondevaFila = 9, padondevaColumna = 13;
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


void initialize(){
    al_init();//Inicia componentes básicos para usar alegro
    al_init_font_addon();//Inicializa los formato de letra
    al_init_ttf_addon();//Inicializa los archivos de tipos de letras
    al_init_primitives_addon();//Inicializa formas primitivas
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

    falcon = new Falcon("MilleniumFalcon.png", 2, 0, 50, 50, zone);
    falcon->addAnimation("RIGHT",0,4);
    falcon->addAnimation("LEFT",1,4);
    falcon->addAnimation("DOWN",2,4);
    falcon->addAnimation("UP",3,4);

    asteroide1 = new Asteroide("Asteroide.png", 0, 1, 40, 40, zone);
    asteroide2 = new Asteroide("Asteroide.png", 4, 0, 40, 40, zone);
    asteroide3 = new Asteroide("Asteroide.png", 9, 0, 40, 40, zone);
    asteroide4 = new Asteroide("Asteroide.png", 6, 1, 40, 40, zone);
    asteroide5 = new Asteroide("Asteroide.png", 3, 2, 40, 40, zone);
    asteroide6 = new Asteroide("Asteroide.png", 8, 3, 40, 40, zone);
    asteroide7 = new Asteroide("Asteroide.png", 5, 4, 40, 40, zone);
    asteroide8 = new Asteroide("Asteroide.png", 1, 4, 40, 40, zone);
    asteroide9 = new Asteroide("Asteroide.png", 4, 6, 40, 40, zone);
    asteroide10 = new Asteroide("Asteroide.png", 7, 6, 40, 40, zone);
    asteroide11 = new Asteroide("Asteroide.png", 9, 7, 40, 40, zone);
    asteroide12 = new Asteroide("Asteroide.png", 2, 7, 40, 40, zone);
    asteroide13 = new Asteroide("Asteroide.png", 0, 8, 40, 40, zone);
    asteroide14 = new Asteroide("Asteroide.png", 6, 8, 40, 40, zone);
    asteroide15 = new Asteroide("Asteroide.png", 4, 9, 40, 40, zone);
    asteroide16 = new Asteroide("Asteroide.png", 1, 10, 40, 40, zone);
    asteroide17 = new Asteroide("Asteroide.png", 8, 10, 40, 40, zone);
    asteroide18 = new Asteroide("Asteroide.png", 6, 12, 40, 40, zone);
    asteroide19 = new Asteroide("Asteroide.png", 3, 12, 40, 40, zone);
    asteroide20 = new Asteroide("Asteroide.png", 1, 13, 40, 40, zone);
    asteroide21 = new Asteroide("Asteroide.png", 5, 14, 40, 40, zone);

    estrella = new DeathStar("DeathStar.png",9,14,80,80,zone);

    calculateBack(falcon,zone);
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
        falcon->draw();
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
        estrella->draw();
        loop();
    }
    al_destroy_display(display);
    return 0;
}