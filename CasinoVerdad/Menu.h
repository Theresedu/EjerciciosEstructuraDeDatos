#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include <iostream>
#include "Blackjack.h"
#include "Ruleta.h"
//#include "Ayuda.html"

using namespace std;

class Menu {
private:
    vector<string> options;
    int selectedIndex;
    string title;
    Blackjack blackjack;  // Se añaden estos atributos
    Ruleta ruleta;
    
public:
    Menu();
    void addOption(const string& option);
    void displayMenu();
    int getSelectedOption();
    void addTitle(const string& title);
    void principal_menu();
    //void ayuda();
};

#endif // MENU_H


