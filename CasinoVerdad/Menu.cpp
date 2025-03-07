/*#include "Tragamonedas.h"
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
    string archivo, comando;
    bool running = true;
    while (running) {
        options.clear();
        addOption("Jugar Blackjack");
        addOption("Jugar Ruleta");
        addOption("Jugar Tragamonedas");
        addOption("Ayuda");
        addOption("Salir");
        addTitle("\t Menu del Casino");
        displayMenu();
        switch (getSelectedOption()) {
        case 0:
            blackjack.startGame(); // Ahora se reconocen correctamente
            break;
        case 1:
            ruleta.startGame();
            break;
        case 2:
            jugarTragamonedas();  // Llamar a la función para jugar Tragamonedas
            break;
        case 3:
        cout << "Ayuda" << endl;
        archivo = "ayuda.html";
        comando = "start " + archivo;
        system(comando.c_str());
        system("pause");

            break;
        case 4:
            running = false;
            break;
        }
    }
}
*/

////////////////////////////////////////////////////////////////////////////////////////////////////

/*
#include "Registro.h"// Asegúrate de que este archivo esté correctamente incluido
#include "Tragamonedas.h"  // Asegúrate de que este archivo esté correctamente incluido
#include "Menu.h"
#include <iostream>
#include <conio.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

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

Menu::Menu() : selectedIndex(0), title("") {}

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
*/
/*

void Menu::principal_menu() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    string archivo, comando;
    bool running = true;
    while (running) {
        options.clear();
        addOption("Jugar Blackjack");
        addOption("Jugar Ruleta");
        addOption("Jugar Tragamonedas");
        addOption("Ayuda");
        addOption("Salir");
        addTitle("\t Menu del Casino");
        displayMenu();
        switch (getSelectedOption()) {
        case 0:
            blackjack.startGame(); // Iniciar Blackjack
            break;
        case 1:
            ruleta.startGame(); // Iniciar Ruleta
            break;
        case 2:
            tragamonedas.setSaldo(1000);  // Asignar saldo inicial
            tragamonedas.setApuesta(10);  // Establecer la apuesta inicial
            tragamonedas.startGame();  // Iniciar Tragamonedas directamente
            break;
        case 3:
            cout << "Ayuda" << endl;
            archivo = "ayuda.html";
            comando = "start " + archivo;
            system(comando.c_str());
            system("pause");
            break;
        case 4:
            running = false;
            break;
        }
    }
}
*/
/*
void Menu::principal_menu() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    string archivo, comando;
    bool running = true;
    while (running) {
        options.clear();
        addOption("Registro de Usuario");
        addOption("Backup");
        addOption("Salir");
        addTitle("\t Menú Principal");
        displayMenu();
        switch (getSelectedOption()) {
        case 0:
            showRegistroMenu(); // Mostrar el menú de registro
            break;
        case 1:
            showBackupMenu(); // Mostrar el menú de backup
            break;
        case 2:
            running = false;  // Salir
            break;
        }
    }
}

void Menu::showRegistroMenu() {
    options.clear();
    addOption("Registrar Usuario");
    addOption("Volver");
    addTitle("Menú de Registro");

    displayMenu();
    
    switch (getSelectedOption()) {
    case 0: // Registrar Usuario
        if (registro()) {
            cout << "Registro exitoso! Redirigiendo al menú del casino...\n";
            iniciarJuego();  // Si el registro es exitoso, iniciamos el juego
        } else {
            cout << "Registro fallido. Por favor, inténtalo de nuevo.\n";
        }
        break;
    case 1: // Volver
        break;
    }
}

void Menu::showBackupMenu() {
    options.clear();
    addOption("Hacer Backup");
    addOption("Cargar Backup");
    addOption("Salir");
    addTitle("Menú de Backup");

    displayMenu();

    switch (getSelectedOption()) {
    case 0:
        cout << "Haciendo Backup...\n";
        // Implementación de la funcionalidad de hacer backup aquí
        break;
    case 1:
        cout << "Cargando Backup...\n";
        // Implementación de la funcionalidad de cargar backup aquí
        break;
    case 2:
        break;
    }
}

bool Menu::registro() {
    if (registroUsuario.registrarUsuario()) {
        cout << "Registro exitoso!" << endl;
        return true;
    }
    return false;
}

void Menu::iniciarJuego() {
    bool running = true;
    while (running) {
        options.clear();
        addOption("Jugar Blackjack");
        addOption("Jugar Ruleta");
        addOption("Jugar Tragamonedas");  // Opción para Tragamonedas
        addOption("Salir");
        addTitle("\t Menú del Casino");
        displayMenu();
        switch (getSelectedOption()) {
        case 0:
            blackjack.startGame(); // Iniciar Blackjack
            break;
        case 1:
            ruleta.startGame(); // Iniciar Ruleta
            break;
        case 2:
                tragamonedas.setSaldo(10000);  // Asignar saldo inicial
                tragamonedas.setApuesta(10);  // Establecer la apuesta inicial
                tragamonedas.startGame();  // Iniciar Tragamonedas directamente
                break;
        case 3:
            running = false;  // Salir
            break;
        }
    }
}
*/

/*
#include "Registro.h"
#include "Tragamonedas.h"
#include "Menu.h"
#include <iostream>
#include <conio.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

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

Menu::Menu() : selectedIndex(0), title("") {}

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
    string archivo, comando;
    bool running = true;
    while (running) {
        options.clear();
        addOption("Registro de Usuario");
        addOption("Backup");
        addOption("Salir");
        addTitle("\t Menú Principal");
        displayMenu();
        switch (getSelectedOption()) {
        case 0:
            showRegistroMenu();
            break;
        case 1:
            showBackupMenu();
            break;
        case 2:
            running = false;
            break;
        }
    }
}

void Menu::showRegistroMenu() {
    options.clear();
    addOption("Registrar Usuario");
    addOption("Volver");
    addTitle("Menú de Registro");

    displayMenu();
    
    switch (getSelectedOption()) {
    case 0:
        if (registro()) {
            cout << "Registro exitoso! Redirigiendo al menú del casino...\n";
            iniciarJuego();
        } else {
            cout << "Registro fallido. Por favor, inténtalo de nuevo.\n";
        }
        break;
    case 1:
        break;
    }
}

void Menu::showBackupMenu() {
    options.clear();
    addOption("Hacer Backup");
    addOption("Cargar Backup");
    addOption("Salir");
    addTitle("Menú de Backup");

    displayMenu();

    switch (getSelectedOption()) {
    case 0:
        cout << "Haciendo Backup...\n";
        break;
    case 1:
        cout << "Cargando Backup...\n";
        break;
    case 2:
        break;
    }
}

bool Menu::registro() {
    double monto;
    if (registroUsuario.registrarUsuario(monto)) {
        cout << "Registro exitoso!" << endl;
        tragamonedas.setSaldo(monto);
        return true;
    }
    return false;
}

void Menu::iniciarJuego() {
    bool running = true;
    while (running) {
        options.clear();
        addOption("Jugar Blackjack");
        addOption("Jugar Ruleta");
        addOption("Jugar Tragamonedas");
        addOption("Salir");
        addTitle("\t Menú del Casino");
        displayMenu();
        switch (getSelectedOption()) {
        case 0:
            blackjack.startGame();
            break;
        case 1:
            ruleta.startGame();
            break;
        case 2:
            tragamonedas.setApuesta(10);
            tragamonedas.startGame();
            break;
        case 3:
            running = false;
            break;
        }
    }
}
    */

    #include "Registro.h"
    #include "Tragamonedas.h"
    #include "Menu.h"
    #include <iostream>
    #include <fstream> // Para manejar archivos
    #include <conio.h>
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
    
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
    
    Menu::Menu() : selectedIndex(0), title("") {}
    
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
        string archivo, comando;
        bool running = true;
        while (running) {
            options.clear();
            addOption("Registro de Usuario");
            addOption("Backup");
            addOption("Salir");
            addTitle("\t Menú Principal");
            displayMenu();
            switch (getSelectedOption()) {
            case 0:
                showRegistroMenu();
                break;
            case 1:
                showBackupMenu();
                break;
            case 2:
                running = false;
                break;
            }
        }
    }
    
    void Menu::showRegistroMenu() {
        options.clear();
        addOption("Registrar Usuario");
        addOption("Volver");
        addTitle("Menú de Registro");
    
        displayMenu();
        
        switch (getSelectedOption()) {
        case 0:
            if (registro()) {
                cout << "Registro exitoso! Redirigiendo al menú del casino...\n";
                iniciarJuego();
            } else {
                cout << "Registro fallido. Por favor, inténtalo de nuevo.\n";
            }
            break;
        case 1:
            break;
        }
    }
    
    void Menu::showBackupMenu() {
        options.clear();
        addOption("Hacer Backup");
        addOption("Cargar Backup");
        addOption("Mostrar Backup");
        addOption("Volver");
        addTitle("Menú de Backup");
    
        displayMenu();
    
        switch (getSelectedOption()) {
        case 0:
            hacerBackup(); // Hacer backup
            break;
        case 1:
            cargarBackup(); // Cargar backup
            break;
        case 2:
            mostrarBackup(); // Mostrar backup
            break;
        case 3:
            break;
        }
    }
    
    bool Menu::registro() {
        double monto;
        if (registroUsuario.registrarUsuario(monto)) {
            cout << "Registro exitoso!" << endl;
            tragamonedas.setSaldo(monto);
            return true;
        }
        return false;
    }
    string archivo, comando;
    void Menu::iniciarJuego() {
        bool running = true;
        while (running) {
            options.clear();
            addOption("Jugar Blackjack");
            addOption("Jugar Ruleta");
            addOption("Jugar Tragamonedas");
            addOption("Ayuda");
            addOption("Salir");
            addTitle("\t Menú del Casino");
            displayMenu();
            switch (getSelectedOption()) {
            case 0:
                blackjack.startGame();
                break;
            case 1:
                ruleta.startGame();
                break;
            case 2:
                tragamonedas.setApuesta(10);
                tragamonedas.startGame();
                break;
            case 3:
            cout << "Ayuda" << endl;
            archivo = "ayuda.html";
            comando = "start " + archivo;
            system(comando.c_str());
            system("pause");
            break;
            case 4:
                running = false;
                break;
            }
        }
    }
    
    // Función para hacer backup
    void Menu::hacerBackup() {
        ofstream archivo("backup_casino.txt");
        if (archivo.is_open()) {
            archivo << "Backup del Casino\n";
            archivo << "Saldo actual: " << tragamonedas.getSaldo() << "\n";
            archivo << "Datos de registro:\n";
            archivo << "Nombre: " << registroUsuario.getNombre() << "\n";
            archivo << "Apellido: " << registroUsuario.getApellido() << "\n";
            archivo << "Cédula: " << registroUsuario.getCedula() << "\n";
            archivo << "Edad: " << registroUsuario.getEdad() << "\n";
            archivo << "Monto: " << registroUsuario.getMonto() << "\n";
            archivo.close();
            cout << "Backup realizado correctamente en 'backup_casino.txt'.\n";
        } else {
            cout << "Error al crear el archivo de backup.\n";
        }
        system("pause");
    }
    
    // Función para cargar backup
    void Menu::cargarBackup() {
        string nombreArchivo;
        cout << "Ingrese el nombre del archivo de backup (ej: backup_casino.txt): ";
        cin >> nombreArchivo;
    
        ifstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                cout << linea << "\n";
            }
            archivo.close();
            cout << "Backup cargado correctamente.\n";
        } else {
            cout << "Error al abrir el archivo de backup.\n";
        }
        system("pause");
    }
    
    // Función para mostrar el contenido del backup
    void Menu::mostrarBackup() {
        ifstream archivo("backup_casino.txt");
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                cout << linea << "\n";
            }
            archivo.close();
        } else {
            cout << "No se encontró el archivo de backup.\n";
        }
        system("pause");
    }