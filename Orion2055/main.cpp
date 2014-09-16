//
//  main.cpp
//  Orion 2055
//
//  Created by Diego Salazar on 9/15/14.
//
//

#include "main.h"
#include "Globales.h"

bool teclas[] = {false, false, false, false, false};
enum TECLAS{ARRIBA, ABAJO, IZQ, DERECHA, SPACIO};

// variables globales

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
	if(!al_init())										//initialize Allegro
		return -1;
    
	display = al_create_display(ANCHO, ALTO);			//create our display object
    
	if(!display)										//test display object
		return -1;
    
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

    
	//srand(time(NULL));
	//==============================================
	// TIMER E INICIAR
	//==============================================
	colaEventos = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
    
	al_register_event_source(colaEventos, al_get_timer_event_source(timer));
	al_register_event_source(colaEventos, al_get_keyboard_event_source());
    
	al_start_timer(timer);
	gameTime = al_current_time();
	while(!terminado)
	{
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
                    teclas[SPACIO] = true;
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
                    teclas[SPACIO] = false;
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
			if(al_current_time() - gameTime >= 1)
			{
				gameTime = al_current_time();
				FPSjuego = frames;
				frames = 0;
			}
			//=====================
           
        
		//==============================================
		// RENDERIZAR
		//==============================================
		if(render && al_is_event_queue_empty(colaEventos))
		{
			render = false;
			//al_draw_textf(font18, al_map_rgb(255, 0, 255), 5, 5, 0, "FPS: %i", FPSjuego);	//display FPS on screen
            
			//BEGIN PROJECT RENDER================
            
			//FLIP BUFFERS========================
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
	}
    
	//==============================================
	// DESTRUIR OBJETOS DE PROYECTO
	//==============================================

    
    
	// OBJETOS DE SHELL=================================
	al_destroy_timer(timer);
	al_destroy_event_queue(colaEventos);
	al_destroy_display(display);
    
	return 0;
}

