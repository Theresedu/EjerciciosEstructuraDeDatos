#include "Pieza.h"

Pieza::Pieza(char l) {
    letra = l;
    x = 5;
    y = 0;
}

bool Pieza::mover(int dx, int dy, char tablero[][10]) {
    int nueva_x = x + dx;
    int nueva_y = y + dy;

    if (nueva_x >= 0 && nueva_x < 10 && nueva_y < 20) {
        if (tablero[nueva_y][nueva_x] == ' ') {
            x = nueva_x;
            y = nueva_y;
            return true;
        }
    }
    return false;
}
