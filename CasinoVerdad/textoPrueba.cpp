/*
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

// Definir las letras como matrices de 5x5
vector<vector<string>> letras = {
    {" ### ", "#   #", "#####", "#   #", "#   #"}, // A
    {"#### ", "#   #", "#### ", "#   #", "#### "}, // B
    {" ####", "#    ", "#    ", "#    ", " ####"}, // C
    {"#### ", "#   #", "#   #", "#   #", "#### "}, // D
    {"#####", "#    ", "#####", "#    ", "#####"}, // E
    {"#####", "#    ", "#####", "#    ", "#    "}, // F
    {" ####", "#    ", "#  ##", "#   #", " ####"}, // G
    {"#   #", "#   #", "#####", "#   #", "#   #"}, // H
    {"#####", "  #  ", "  #  ", "  #  ", "#####"}, // I
    {"  ###", "   # ", "   # ", "#  # ", " ##  "}, // J
    {"#   #", "#  # ", "###  ", "#  # ", "#   #"}, // K
    {"#    ", "#    ", "#    ", "#    ", "#####"}, // L
    {"#   #", "## ##", "# # #", "#   #", "#   #"}, // M
    {"#   #", "##  #", "# # #", "#  ##", "#   #"}, // N
    {" ### ", "#   #", "#   #", "#   #", " ### "}, // O
    {"#### ", "#   #", "#### ", "#    ", "#    "}, // P
    {" ### ", "#   #", "# # #", "#  ##", " ####"}, // Q
    {"#### ", "#   #", "#### ", "#  # ", "#   #"}, // R
    {" ####", "#    ", " ### ", "    #", "#### "}, // S
    {"#####", "  #  ", "  #  ", "  #  ", "  #  "}, // T
    {"#   #", "#   #", "#   #", "#   #", " ### "}, // U
    {"#   #", "#   #", "#   #", " # # ", "  #  "}, // V
    {"#   #", "#   #", "# # #", "## ##", "#   #"}, // W
    {"#   #", " # # ", "  #  ", " # # ", "#   #"}, // X
    {"#   #", " # # ", "  #  ", "  #  ", "  #  "}, // Y
    {"#####", "   # ", "  #  ", " #   ", "#####"}  // Z
};

// Mapeo de letras a índices en la matriz
string texto = "BIENVENIDO";

void imprimirTexto() {
    for (int fila = 0; fila < 5; fila++) { // 5 filas por letra
        for (char c : texto) {
            if (c == ' ') {
                cout << "   "; // Espacio entre palabras
            } else {
                cout << letras[c - 'A'][fila] << "  "; // Imprimir fila de cada letra
            }
        }
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(200)); // Pequeño delay para efecto
    }
}

void mostrarBienvenida() {
    imprimirTexto();
    cout << endl;
}
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "TextoPrueba.h"

using namespace std;

// La matriz de las letras representadas como arte ASCII
vector<vector<string>> letras = {
    {" ### ", "#   #", "#####", "#   #", "#   #"}, // A
    {"#### ", "#   #", "#### ", "#   #", "#### "}, // B
    {" ####", "#    ", "#    ", "#    ", " ####"}, // C
    {"#### ", "#   #", "#   #", "#   #", "#### "}, // D
    {"#####", "#    ", "#####", "#    ", "#####"}, // E
    {"#####", "#    ", "#####", "#    ", "#    "}, // F
    {" ####", "#    ", "#  ##", "#   #", " ####"}, // G
    {"#   #", "#   #", "#####", "#   #", "#   #"}, // H
    {"#####", "  #  ", "  #  ", "  #  ", "#####"}, // I
    {"  ###", "   # ", "   # ", "#  # ", " ##  "}, // J
    {"#   #", "#  # ", "###  ", "#  # ", "#   #"}, // K
    {"#    ", "#    ", "#    ", "#    ", "#####"}, // L
    {"#   #", "## ##", "# # #", "#   #", "#   #"}, // M
    {"#   #", "##  #", "# # #", "#  ##", "#   #"}, // N
    {" ### ", "#   #", "#   #", "#   #", " ### "}, // O
    {"#### ", "#   #", "#### ", "#    ", "#    "}, // P
    {" ### ", "#   #", "# # #", "#  ##", " ####"}, // Q
    {"#### ", "#   #", "#### ", "#  # ", "#   #"}, // R
    {" ####", "#    ", " ### ", "    #", "#### "}, // S
    {"#####", "  #  ", "  #  ", "  #  ", "  #  "}, // T
    {"#   #", "#   #", "#   #", "#   #", " ### "}, // U
    {"#   #", "#   #", "#   #", " # # ", "  #  "}, // V
    {"#   #", "#   #", "# # #", "## ##", "#   #"}, // W
    {"#   #", " # # ", "  #  ", " # # ", "#   #"}, // X
    {"#   #", " # # ", "  #  ", "  #  ", "  #  "}, // Y
    {"#####", "   # ", "  #  ", " #   ", "#####"}  // Z
};

// La palabra a imprimir
string texto = "BIENVENIDO";

// Método para imprimir el texto en forma de arte ASCII
void TextoPrueba::imprimirTexto() {
    for (int fila = 0; fila < 5; fila++) { // 5 filas por letra
        for (char c : texto) {
            if (c == ' ') {
                cout << "   "; // Espacio entre palabras
            } else {
                cout << letras[c - 'A'][fila] << "  "; // Imprimir fila de cada letra
            }
        }
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(200)); // Pequeño delay para efecto
    }
    system("pause");
}
