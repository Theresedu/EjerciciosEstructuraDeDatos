
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

    string monto_input;
            double monto;
    
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
            
            do {
                cout << "Ingrese el monto con el que va a jugar: ";
                monto_input = registroUsuario.obtenerEntrada(true); // Solo se permiten números
        
                if (monto_input.empty()) {
                    cout << "El monto no puede estar vacío. Intenta nuevamente." << endl;
                } else {
                    try {
                        monto = stod(monto_input); // Convertir el monto a número
                        if (monto <= 0) {
                            cout << "El monto debe ser mayor a 0." << endl;
                        }
                    } catch (invalid_argument& e) {
                        cout << "El monto debe ser un número válido. Intenta nuevamente." << endl;
                        continue; // Si la conversión falla, continúa pidiendo el monto
                    }
                }
            } while (monto <= 0 || monto_input.empty());
            registroUsuario.setMonto(monto);
            tragamonedas.setSaldo(monto);
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