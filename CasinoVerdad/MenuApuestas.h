#ifndef MENUAPUESTAS_H
#define MENUAPUESTAS_H

#include <vector>
#include <string>
#include <iostream>
#include <conio.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

using namespace std;

class MenuApuestas {
private:
    vector<string> options;
    int selectedIndex;
    string title;

public:
    MenuApuestas();
    void addOption(const string& option);
    void displayMenu();
    int getSelectedOption();
    void addTitle(const string& title);
    int mostrarMenuApuestas();
};

#endif // MENUAPUESTAS_H