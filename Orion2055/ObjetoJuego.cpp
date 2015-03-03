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
    
    x = 0; y = 0;
    
    velX = 0; velY = 0;
    
    velX = 0; velY = 0;
    
    dirX = 0; dirY = 0;
    
    boundX = 0; boundY = 0;
    
    angulo = 0; Vangular = 0;
    
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
    
    estaVivo = true;
    colisiona = true;
}

void ObjetoJuego::Destruir()
{
    /*if (imagen != NULL) {
        al_destroy_bitmap(imagen);
    }*/
}

void ObjetoJuego::Iniciar(float x, float y, float velX, float velY, int dirX, int dirY, int boundX, int boundY){

    ObjetoJuego::x = x;
    std::cout << "x: "<< x ;
    std::cout << "\n";
    ObjetoJuego::y = y;
    std::cout << "y: "<< y ;
    std::cout << "\n";
    ObjetoJuego::velX = velX;
    std::cout << "Velx: "<< velX ;
    std::cout << "\n";
    ObjetoJuego::velY = velY;
    std::cout << "Vely: "<< velY ;
    std::cout << "\n";
    ObjetoJuego::dirX = dirX;
    std::cout << "dirx: "<< dirX ;
    std::cout << "\n";
    ObjetoJuego::dirY = dirY;
    std::cout << "dirY: "<< dirY ;
    std::cout << "\n";
    ObjetoJuego::boundX = boundX;
    std::cout << "bx: "<< boundX ;
    std::cout << "\n";
    ObjetoJuego::boundY = boundY;
    std::cout << "by: "<< boundY ;
    std::cout << "\n";
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
    int obY = otroObjeto -> GetBoundY();
    
    if( x + boundX > oX - obX &&
       x - boundX < oX + obX &&
       y + boundY > oY - obY &&
       y - boundY < oY + obY){
		return true;
    }
	else{
		return false;
    }
    
}

void ObjetoJuego::Collided(int objectID)
{}

bool ObjetoJuego::Collidable()
{
	return estaVivo && colisiona;
}