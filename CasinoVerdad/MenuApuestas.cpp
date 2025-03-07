#include "MenuApuestas.h"

MenuApuestas::MenuApuestas() : selectedIndex(0), title("") {}

void MenuApuestas::addOption(const string &option) {
    options.push_back(option);
}

void MenuApuestas::addTitle(const string &title) {
    this->title = title;
}

void MenuApuestas::displayMenu() {
    bool running = true;
    while (running) {
        system("cls");
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

int MenuApuestas::getSelectedOption() {
    return selectedIndex;
}

int MenuApuestas::mostrarMenuApuestas() {
    options.clear();
    addOption("Numero especifico");
    addOption("Rojo");
    addOption("Negro");
    addOption("Par");
    addOption("Impar");
    addOption("Docena");
    addOption("Columna");
    addTitle("\t Menu de Apuestas");

    displayMenu();
    return getSelectedOption();
}