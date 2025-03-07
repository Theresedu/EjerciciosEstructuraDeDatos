//g++ Main.cpp Menu.cpp Blackjack.cpp Ruleta.cpp Tragamonedas.cpp textoPrueba.cpp MenuApuestas.cpp Registro.cpp -o casino.exe -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system

#include "textoPrueba.h"
#include "Menu.h"
#include <iostream>

int main(){

    // Crear una instancia de la clase TextoPrueba
    TextoPrueba bienvenida;
    // Mostrar el mensaje de bienvenida
    bienvenida.imprimirTexto();

    Menu menu;
    menu.principal_menu();
    return 0;
}
