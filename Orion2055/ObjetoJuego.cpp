//
//  ObjetoJuego.cpp
//  Orion 2055
//
//  Created by Diego Salazar on 9/15/14.
//
//

#include "ObjetoJuego.h"

ObjetoJuego::ObjetoJuego()
{
    
    x = 0, y = 0;
    
    velX = 0, velY = 0;
    
    velX = 0, velY = 0;
    
    dirX = 0, dirY = 0;
    
    boundX = 0, boundY = 0;
    
    angulo = 0, Vangular = 0;
    
    friccion = 0;
    
    maxCuadros = 0;
	cuadroActual = 0;
	cuentaCuadro = 0;
	retrasoCuadro = 0;
	anchoCuadro = 0;
	altoCuadro = 0;
	columnasAnimacion = 0;
	direccionAnimacion = 0;
    
    imagen = NULL;
}

void ObjetoJuego::Destruir()
{
    if (imagen != NULL) {
        al_destroy_bitmap(imagen);
    }
}

void ObjetoJuego::Iniciar(float x, float y, float velX, float velY, int dirX, int dirY, int boundX, int boundY){

    ObjetoJuego::x = x;
    ObjetoJuego::y = y;
    ObjetoJuego::velX = velX;
    ObjetoJuego::velY = velY;
    ObjetoJuego::dirX = dirX;
    ObjetoJuego::dirY = dirY;
    ObjetoJuego::boundX = boundX;
    ObjetoJuego::boundY = boundY;
}


void ObjetoJuego::Actualizar()
{
    x += velX * dirX;
    y += velY * dirY;
}

void ObjetoJuego::Renderizar()
{
    
}

bool ObjetoJuego::CheckCollisions(ObjetoJuego *otroObjeto)
{
    float oX = otroObjeto -> GetX();
    float oY = otroObjeto -> GetY();
    
    int obX = otroObjeto -> GetBoundX();
    int oby = otroObjeto -> GetBoundY();
    
    
    return true;
}
