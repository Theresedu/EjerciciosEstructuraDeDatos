//g++ main.cpp Menu.cpp Blackjack.cpp Ruleta.cpp -o casino.exe -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system

#include "Menu.h"
#include <iostream>

int main(){
    Menu menu;
    menu.principal_menu();
    return 0;
}
