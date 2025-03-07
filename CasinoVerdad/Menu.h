/*#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include <iostream>
#include "Blackjack.h"
#include "Ruleta.h"

using namespace std;

class Menu {
private:
    vector<string> options;
    int selectedIndex;
    string title;
    Blackjack blackjack;  
    Ruleta ruleta;
    
public:
    Menu();
    void addOption(const string& option);
    void displayMenu();
    int getSelectedOption();
    void addTitle(const string& title);
    void principal_menu();
};

#endif // MENU_H

*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#ifndef MENU_H
#define MENU_H


#include <vector>
#include <string>
#include <iostream>
#include "Blackjack.h"  // Incluir Blackjack para que podamos acceder a sus funciones
#include "Ruleta.h"     // Incluir Ruleta para que podamos acceder a sus funciones
#include "Tragamonedas.h" // Incluir Tragamonedas para que podamos acceder a sus funciones
#include "Registro.h"   // Incluir Registro para que podamos acceder a sus funciones

using namespace std;

class Menu {
private:
    vector<string> options;
    int selectedIndex;
    string title;
    Blackjack blackjack;
    Ruleta ruleta;
    Tragamonedas tragamonedas;
    Registro registroUsuario;// Aquí tienes la instancia de la clase Registro

public:
    Menu();
    void addOption(const string& option);
    void displayMenu();
    int getSelectedOption();
    void addTitle(const string& title);
    void principal_menu();
    void showRegistroMenu();  // Mostrar el menú de registro
    void showBackupMenu();    // Mostrar el menú de backup
    void iniciarJuego();  
    bool registro();    // Iniciar el juego después del registro
};

#endif // MENU_H
*/
/*
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
*/

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
