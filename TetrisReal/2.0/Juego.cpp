#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "Juego.h"
#include <synchapi.h>

Juego::Juego() {}

void Juego::iniciar() {
    srand(time(0));
    Tablero tablero;
    Pieza pieza_actual('a' + rand() % 26);

    while (true) {
        tablero.limpiar_letras();
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 27) break;
            if (tecla == 75) pieza_actual.mover(-1, 0, tablero.tablero); // Flecha izquierda
            if (tecla == 77) pieza_actual.mover(1, 0, tablero.tablero);  // Flecha derecha
        }

        if (!pieza_actual.mover(0, 1, tablero.tablero)) {
            tablero.tablero[pieza_actual.y][pieza_actual.x] = pieza_actual.letra;
            tablero.limpiar_letras();
            pieza_actual = Pieza('a' + rand() % 26);
        }

        tablero.dibujar(pieza_actual);
        Sleep(300);
    }
}
