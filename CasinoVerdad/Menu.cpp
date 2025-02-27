#include "Menu.h"
#include <iostream>
#include <conio.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//#include <shellapi.h> 

using namespace std;

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#undef byte
#define CLEAR() system("cls")
#else
#include <cstdlib>
#define CLEAR() system("clear")
#endif
/*
void Menu::ayuda() {
    string filename = "ayuda.html";  // Archivo HTML de ayuda
    ShellExecute(0, "open", filename.c_str(), 0, 0, SW_SHOWNORMAL);  
}*/


Menu::Menu() : selectedIndex(0), title("") {} // Constructor

void Menu::addOption(const string &option) {
    options.push_back(option);
}

void Menu::addTitle(const string &title) {
    this->title = title;
}

void Menu::displayMenu() {
    bool running = true;
    while (running) {
        CLEAR();
        if (!title.empty()) {
            cout << title << "\n";
        }
        cout << "\n";
        for (size_t i = 0; i < options.size(); ++i) {
            if (static_cast<int>(i) == selectedIndex) {
                cout << "==> " << options[i] << " \n";
            } else {
                cout << "  " << options[i] << "\n";
            }
        }
        int key = _getch();
        switch (key) {
        case 72: // Flecha arriba
            selectedIndex = (selectedIndex - 1 + options.size()) % options.size();
            break;
        case 80: // Flecha abajo
            selectedIndex = (selectedIndex + 1) % options.size();
            break;
        case 13: // Enter
            running = false;
            break;
        }
    }
}

int Menu::getSelectedOption() {
    return selectedIndex;
}

void Menu::principal_menu() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    bool running = true;
    while (running) {
        options.clear();
        addOption("Jugar Blackjack");
        addOption("Jugar Ruleta");
        addOption("Ayuda");
        addOption("Salir");
        addTitle("\t Bienvenido al Casino");
        displayMenu();
        switch (getSelectedOption()) {
        case 0:
            blackjack.startGame(); // Ahora se reconocen correctamente
            break;
        case 1:
            ruleta.startGame();
            break;
        /*
            case 2:
            ayuda();
            break;
            */
        case 2:
            running = false;
            break;
        }
    }
}
