

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include <iostream>
#include "Blackjack.h"
#include "Ruleta.h"
#include "Tragamonedas.h"
#include "Registro.h"

using namespace std;

class Menu {
private:
    vector<string> options;
    int selectedIndex;
    string title;
    Blackjack blackjack;
    Ruleta ruleta;
    Tragamonedas tragamonedas;
    Registro registroUsuario;

    void hacerBackup();  // Función para hacer backup
    void cargarBackup(); // Función para cargar backup
    void mostrarBackup(); // Función para mostrar el contenido del backup

public:
    Menu();
    void addOption(const string& option);
    void displayMenu();
    int getSelectedOption();
    void addTitle(const string& title);
    void principal_menu();
    void showRegistroMenu();
    void showBackupMenu();
    void iniciarJuego();
    bool registro();
};

#endif // MENU_H
