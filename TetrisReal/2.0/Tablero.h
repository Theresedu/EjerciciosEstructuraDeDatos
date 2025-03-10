#ifndef TABLERO_H
#define TABLERO_H
#include "Pieza.h"
class Tablero {
public:

    static const int ANCHO = 10;
    static const int ALTO = 20;
    char tablero[ALTO][ANCHO];

    Tablero();
    void inicializar2(int);
    void inicializar();
    void dibujar2(int a, Pieza &pieza_actual);
    void dibujar(Pieza &pieza_actual);
    void Eliminar_verticalmente(int a);
    void Eliminar_horizontalmente(int a);
    void Mover_abajo(int b);
    void limpiar_letras();
};

#endif
