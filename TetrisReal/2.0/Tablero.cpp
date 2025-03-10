#include <iostream>
#include <windows.h>
#include "Tablero.h"

using namespace std;

Tablero::Tablero() {
    inicializar();
}

void Tablero::inicializar2(int a){
    for (int j = 0; j < ANCHO; j++) {
        tablero[a][j] = ' ';
    }
}

void Tablero::inicializar() {
    for (int i = 0; i < ALTO; i++) {
        inicializar2(i);
    }
}

void Tablero::dibujar2(int a, Pieza &pieza_actual) {
    for (int j = 0; j < ANCHO; j++) {
        if (a == pieza_actual.y && j == pieza_actual.x) {
            cout << "{" << pieza_actual.letra;
        } else {
            cout << "}" << tablero[a][j];
        }
    }
    cout << "|" << endl;
}


void Tablero::dibujar(Pieza &pieza_actual) {
    system("cls");
    for (int i = 0; i < ALTO; i++) {
        dibujar2(i, pieza_actual);
    }
}
/*
void Tablero::dibujar(Pieza &pieza_actual) {
    system("cls");
    // Cambiar la forma en que se dibuja el tablero.
    for (int i = 0; i < ALTO; i++) {
        cout << "    "; // Añadir un poco de margen
        for (int j = 0; j < ANCHO; j++) {
            if (i == pieza_actual.y && j == pieza_actual.x) {
                // Usar un símbolo distinto para las piezas
                cout << "[A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z]";  // O cualquier otro símbolo visual
            } else {
                // Cambiar el fondo o cómo se muestra el vacío
                cout << "[ ]";  // Puedes usar un espacio vacío, o un guion, o cualquier otra cosa
            }
        }
        cout << endl;
    }
}*/


void Tablero::Eliminar_verticalmente(int a){
    for (int j = 0; j < ANCHO; j++) {
        if (tablero[a][j] != ' ' && tablero[a][j] == tablero[a + 1][j]) {
            tablero[a][j] = ' ';
            tablero[a + 1][j] = ' ';
        }
    }
}

void Tablero::Eliminar_horizontalmente(int a){
    for (int j = 0; j < ANCHO - 1; j++) {
        if (tablero[a][j] != ' ' && tablero[a][j] == tablero[a][j + 1]) {
            tablero[a][j] = ' ';
            tablero[a][j + 1] = ' ';
        }
    }
}

void Tablero::Mover_abajo(int b){
    for (int i = ALTO - 2; i >= 0; i--) {  // Desde abajo hacia arriba
        if (tablero[i][b] != ' ' && tablero[i + 1][b] == ' ') {
            int k = i;
            while (k + 1 < ALTO && tablero[k + 1][b] == ' ') {
                tablero[k + 1][b] = tablero[k][b];
                tablero[k][b] = ' ';
                k++;
            }
        }
    }
}


void Tablero::limpiar_letras() {
    // Eliminar letras iguales verticalmente
    for (int i = 0; i < ALTO - 1; i++) {
        Eliminar_verticalmente(i);
    }

    // Eliminar letras iguales horizontalmente
    for (int i = 0; i < ALTO; i++) {
        Eliminar_horizontalmente(i);
    }

    // Mover las letras hacia abajo si hay espacios vacíos
    for (int j = 0; j < ANCHO; j++) {
        Mover_abajo(j);
    }

    // Unir letras horizontalmente solo en la base (primera fila ocupada desde abajo)
    int fila_base = -1;
    for (int i = ALTO - 1; i >= 0; i--) {
        bool tiene_letras = false;
        for (int j = 0; j < ANCHO; j++) {
            if (tablero[i][j] != ' ') {
                tiene_letras = true;
                break;
            }
        }
        if (tiene_letras) {
            fila_base = i;
            break;
        }
    }

    if (fila_base != -1) {
        for (int j = 1; j < ANCHO; j++) { // Mover solo en la fila base
            if (tablero[fila_base][j] != ' ' && tablero[fila_base][j - 1] == ' ') {
                int k = j;
                while (k > 0 && tablero[fila_base][k - 1] == ' ') {
                    tablero[fila_base][k - 1] = tablero[fila_base][k];
                    tablero[fila_base][k] = ' ';
                    k--;
                }
            }
        }
    }
}
