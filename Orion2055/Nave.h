//
//  Nave.h
//  Orion 2055
//
//  Created by Diego Salazar on 9/15/14.
//
//

#ifndef __Orion_2055__Nave__
#define __Orion_2055__Nave__

#include "ObjetoJuego.h"

class Nave: public ObjetoJuego
{
    
private:
    int vidas, puntaje;
    int filasAnimacion;
    
public:
    Nave();
    void Destruir();
    
    void Iniciar(ALLEGRO_BITMAP *imagen = NULL);
    void Actualizar();
    void Renderizar();
    
    void Acelerar();
    void RotarIZQ();
    void RotarDER();
    
    void ReiniciarAnimacion(int posicion);
    
    int GetVidas() {return vidas;}
    int GetPuntaje() {return puntaje;}
    
    void PierdeVida() {vidas--;}
    void GanaPuntos() {puntaje++;}
    
    void Collisionar(int objetoID);
};

#endif /* defined(__Orion_2055__Nave__) */
