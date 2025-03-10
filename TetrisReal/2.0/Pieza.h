#ifndef PIEZA_H
#define PIEZA_H

class Pieza {
public:
    char letra;
    int x, y;

    Pieza(char l);
    bool mover(int dx, int dy, char tablero[][10]);
};

#endif
