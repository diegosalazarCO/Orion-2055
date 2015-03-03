//
//  main.cpp
//  Orion 2055
//
//  Created by Diego Salazar on 9/15/14.
//
//

#include <iostream>
#include <list>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>


#include "Globales.h"
#include "ObjetoJuego.h"
#include "Nave.h"

using namespace std;

bool teclas[5] = {false, false, false, false, false};
enum TECLAS{ARRIBA, ABAJO, IZQ, DERECHA, ESPACIO};

// variables globales
Nave *nave;
//list<ObjetoJuego *> objetos;
//list<ObjetoJuego *>::iterator iterador;
//list<ObjetoJuego *>::iterator iterador2;

int main(int argc, char **argv)
{
	//==============================================
	//VARIABLES DE SHELL
	//==============================================
	bool terminado = false;
	bool render = false;
    
	float gameTime = 0;
	int frames = 0;
	int FPSjuego = 0;
    
	//==============================================
	//VARIABLES DE PROYECTO
	//==============================================
	
    nave = new Nave();
    ALLEGRO_BITMAP *imagenNave = NULL;
    
	//==============================================
	//VARIABLES DE ALLEGRO
	//==============================================
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *colaEventos = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_FONT *font18;
	
	//==============================================
	//FUNCIONES INIT ALLEGRO
	//==============================================
	if(!al_init()){										//initialize Allegro
		return -1;
    }
    
	display = al_create_display(ANCHO, ALTO);			//create our display object
    al_set_window_title(display, "Orion 2055");
	if(!display){										//test display object
		return -1;
    }
    cout << "\n" << display;
	//==============================================
	// INSTALAR ADDONS
	//==============================================
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
    
    
	//==============================================
	//PROJECT INIT
	//==============================================
    
    font18 = al_load_font("Vanadine Regular.ttf", 18, 0);
    imagenNave = al_load_bitmap("spaceship_by_arboris.png");
    al_convert_mask_to_alpha(imagenNave, al_map_rgb(255, 0, 255));
    cout << "\n" << imagenNave ;
    nave -> Iniciar(imagenNave);
    
    //objetos.push_back(nave);
    
	srand(time(NULL));
	//==============================================
	// TIMER E INICIAR
	//==============================================
	colaEventos = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
    
	al_register_event_source(colaEventos, al_get_timer_event_source(timer));
	al_register_event_source(colaEventos, al_get_keyboard_event_source());
    
	al_start_timer(timer);
	gameTime = al_current_time();
    cout << "\n Game time: " << gameTime;
	while(!terminado)
	{
        cout << "\nhi";
		ALLEGRO_EVENT ev;
		al_wait_for_event(colaEventos, &ev);
        
		//==============================================
		// ENTRADAS
		//==============================================
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
                case ALLEGRO_KEY_ESCAPE:
                    terminado = true;
                    break;
                case ALLEGRO_KEY_LEFT:
                    teclas[IZQ] = true;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    teclas[DERECHA] = true;
                    break;
                case ALLEGRO_KEY_UP:
                    teclas[ARRIBA] = true;
                    break;
                case ALLEGRO_KEY_DOWN:
                    teclas[ABAJO] = true;
                    break;
                case ALLEGRO_KEY_SPACE:
                    teclas[ESPACIO] = true;
                    break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch(ev.keyboard.keycode)
			{
                case ALLEGRO_KEY_ESCAPE:
                    terminado = true;
                    break;
                case ALLEGRO_KEY_LEFT:
                    teclas[IZQ] = false;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    teclas[DERECHA] = false;
                    break;
                case ALLEGRO_KEY_UP:
                    teclas[ARRIBA] = false;
                    break;
                case ALLEGRO_KEY_DOWN:
                    teclas[ABAJO] = false;
                    break;
                case ALLEGRO_KEY_SPACE:
                    teclas[ESPACIO] = false;
                    break;
			}
		}
		//==============================================
		// ACTUALIZACION DE JUEGO
		//==============================================
		else if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			render = true;
            
			//UPDATE FPS===========
			frames++;
            cout << "\nFrames:" << frames;
            cout << "\nif.. " << al_current_time();
			if(al_current_time() - gameTime >= 1)
			{
				gameTime = al_current_time();
				FPSjuego = frames;
				frames = 0;
			}
			//=====================
            
            if (teclas[ARRIBA]) {
                nave -> Acelerar();
            } else if (teclas[IZQ]){
                nave -> RotarIZQ();
            } else if (teclas[DERECHA]){
                nave -> RotarDER();
            }
            // actualizar
            nave -> Actualizar();
            /*for (iterador = objetos.begin(); iterador != objetos.end(); ++iterador) {
                cout << "\nObjetos:" << objetos.size();
                cout << "\n\t:D itera";
                (*iterador)-> Actualizar();
            }*/
           
        }
		//==============================================
		// RENDERIZAR
		//==============================================
		if(render && al_is_event_queue_empty(colaEventos))
		{
			render = false;
			al_draw_textf(font18, al_map_rgb(236, 240, 241), 5, 5, 0, "FPS: %i", FPSjuego);	//display FPS on screen
            
			//BEGIN PROJECT RENDER================
            /*for (iterador = objetos.begin(); iterador != objetos.end(); ++iterador) {
                (*iterador)-> Renderizar();
            }*/
            //nave -> Renderizar();
            
			//FLIP BUFFERS========================
			al_flip_display();
			al_clear_to_color(al_map_rgb(44, 62, 80));
		}
	}
    
	//==============================================
	// DESTRUIR OBJETOS DE PROYECTO
	//==============================================

    /*for (iterador = objetos.begin(); iterador != objetos.end(); ++iterador) {
        (*iterador)-> Destruir();
        delete (*iterador);
        iterador = objetos.erase(iterador);
    }*/
    nave -> Destruir();
    
    al_destroy_bitmap(imagenNave);
    
	// OBJETOS DE SHELL=================================
    al_destroy_font(font18);
	al_destroy_timer(timer);
	al_destroy_event_queue(colaEventos);
	al_destroy_display(display);
    
	return 0;
    
}