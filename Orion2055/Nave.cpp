//
//  Nave.cpp
//  Orion 2055
//
//  Created by Diego Salazar on 9/15/14.
//
//

#include "Nave.h"

Nave::Nave(){
    
}
void Nave::Destruir()
{
    ObjetoJuego::Destruir();
}

void Nave::Iniciar(ALLEGRO_BITMAP *imagen)
{
    ObjetoJuego::Iniciar(20, 200, 6, 6, 0, 0, 10, 12);
    
    SetID(JUGADOR);
    SetEstaVivo(true);
    
    vidas = 3;
    puntaje = 0;
    
    maxCuadros = 3;
	cuadroActual = 0;
	cuentaCuadro = 0;
	retrasoCuadro = 0;
	anchoCuadro = 46;
	altoCuadro = 41;
	columnasAnimacion = 3;
	direccionAnimacion = 1;
    
    filasAnimacion = 1;
    
    if (!imagen) {
        Nave::imagen = imagen;
    }
}

void Nave::Actualizar()
{
    ObjetoJuego::Actualizar();
    if (x < 0) {
        x = ANCHO;
    } else if (x>ANCHO){
        x = 0;
    }
    if (y < 0) {
        y = ALTO;
    } else if (y > ALTO){
        y = 0;
    }
}

void Nave::Renderizar()
{
    //ObjetoJuego::Renderizar();
    
    int fx = (cuadroActual % columnasAnimacion) * anchoCuadro;
    int fy = filasAnimacion * altoCuadro;
    
    al_draw_bitmap_region(imagen, fx, fy, anchoCuadro, altoCuadro, x -anchoCuadro/2, y - altoCuadro/2, 0);
    
}

void Nave::Acelerar()
{
    
}
void Nave::RotarIZQ(){
    
}
void Nave::RotarDER(){
    
}


void Nave::Collisionar(int objetoID)
{
    if (objetoID == ENEMIGO || objetoID == ASTEROIDE) {
        vidas--;
    }
    
}

void Nave::ReiniciarAnimacion(int posicion)
{
    if (posicion==1) {
        filasAnimacion = 1;
        dirY = 0;
    }
    else {
        cuadroActual = 0;
        dirX = 0;
    }
    
}