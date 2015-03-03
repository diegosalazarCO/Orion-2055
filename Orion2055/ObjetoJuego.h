//
//  ObjetoJuego.h
//  Orion 2055
//
//  Created by Diego Salazar on 9/15/14.
//
//

#ifndef Orion_2055_Juego_h
#define Orion_2055_Juego_h

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Globales.h"

class ObjetoJuego
{
private:
    
    int ID;
    bool estaVivo;
    bool colisiona;
    
protected:
    
    float x, y;
    
    float velX, velY;
    
    int dirX, dirY;
    
    int boundX, boundY;
    
    float angulo, Vangular;
    
    float friccion;
    
    int maxCuadros;
	int cuadroActual;
	int cuentaCuadro;
	int retrasoCuadro;
	int anchoCuadro;
	int altoCuadro;
	int columnasAnimacion;
	int direccionAnimacion;
    
    ALLEGRO_BITMAP *imagen;
    
public:
	ObjetoJuego();
	void virtual Destruir();
    
	void Iniciar(float x, float y, float velX, float velY, int dirX, int dirY, int boundX, int boundY);
	void virtual Actualizar();
	void virtual Renderizar();
    
	float GetX() {return x;}
	float GetY() {return y;}
    
	void SetX(float x) {ObjetoJuego::x = x;}
	void SetY(float y) {ObjetoJuego::y = y;}
    
	int GetBoundX() {return boundX;}
	int GetBoundY() {return boundY;}
    
	int GetID() {return ID;}
	void SetID(int ID) {ObjetoJuego::ID = ID;}
    
	bool GetEstaVivo() {return estaVivo;}
	void SetEstaVivo(bool estaVivo) {ObjetoJuego::estaVivo = estaVivo;}
    
	bool GetCollidable() {return colisiona;}
	void SetCollidable(bool colisiona) {ObjetoJuego::colisiona = colisiona;}
    
	bool CheckCollisions(ObjetoJuego *otroObjeto);
	void virtual Collided(int idObjeto);
	bool Collidable();
    
};

#endif
