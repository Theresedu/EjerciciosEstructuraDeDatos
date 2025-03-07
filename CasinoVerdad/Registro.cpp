/*
#include "Registro.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cctype>
#include <ctime> // Para obtener la hora del sistema
#include <iomanip>

using namespace std;

// Función para borrar el salto de línea al final de la cédula
void borrar(char a[]) {
    for (int i = 0; i < 11; i++) {
        if (a[i] == '\n')
            a[i] = '\0';
    }
}

// Función para validar la cédula ecuatoriana
bool extraer(const string& cedula) {
    int v[10], num, limite;
    limite = cedula.length();

    if (limite != 10) {
        cout << "Cedula No Valida" << endl;
        return false;
    }

    for (int i = 0; i < 10; i++) {
        num = cedula[i] - '0';
        v[i] = num;
    }

    int vec[10], suma = 0, ultimo, ultimon;
    if (v[0] == 1 || v[0] == 2) {
        if (v[2] > 0 && v[2] < 6) {
            for (int i = 0; i < 9; i += 2) {
                vec[i] = v[i] * 2;
                if (vec[i] >= 10)
                    vec[i] -= 9;
            }
            for (int i = 1; i < 9; i += 2) {
                vec[i] = v[i];
            }
            for (int i = 0; i < 9; i++) {
                suma += vec[i];
            }

            ultimo = ((suma / 10) + 1) * 10;
            ultimon = ultimo - suma;

            if (ultimon == v[9]) {
                cout << "Cedula VERIFICADA" << endl;
                return true;
            } else {
                cout << "Cedula NO VERIFICADA" << endl;
                return false;
            }
        }
    }
    cout << "Cedula incorrecta" << endl;
    return false;
}

// Función para obtener la fecha y la hora actual
string obtenerFechaHora() {
    time_t ahora = time(0);
    struct tm* tiempo = localtime(&ahora);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tiempo);
    return string(buffer);
}

// Función para guardar el registro en un archivo
void guardarRegistro(const string& nombre, const string& apellido, const string& cedula, int edad, double monto) {
    ofstream archivo("usuarios.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Nombre: " << nombre << " " << apellido
                << ", Cedula: " << cedula
                << ", Edad: " << edad
                << ", Monto: " << monto
                << ", Fecha de Registro: " << obtenerFechaHora() << endl;
        archivo.close();
    } else {
        cout << "Error al abrir el archivo de usuarios." << endl;
    }
}

// Función para obtener entrada del usuario (solo números o solo letras)
string obtenerEntrada(bool soloNumeros) {
    string entrada = "";
    char c;
    while ((c = getch()) != '\r') { // Enter para terminar
        if (c == '\b' && !entrada.empty()) {
            cout << "\b \b";
            entrada.pop_back();
        } else if (soloNumeros && isdigit(c)) {
            entrada += c;
            cout << c;
        } else if (!soloNumeros && isalpha(c)) {
            entrada += c;
            cout << c;
        }
    }
    cout << endl;
    return entrada;
}

// Función para registrar un usuario
void registrarUsuario() {
    string nombre, apellido, cedula;
    int edad;
    double monto;

    do {
        cout << "Ingrese su edad: ";
        edad = stoi(obtenerEntrada(true));
        if (edad < 18) {
            cout << "No puedes registrarte si eres menor de 18 años." << endl;
            return ;
        }
    } while (edad < 18);

    cout << "Ingrese su nombre: ";
    nombre = obtenerEntrada(false);
    cout << "Ingrese su apellido: ";
    apellido = obtenerEntrada(false);

    do {
        cout << "Ingrese su cedula (10 digitos): ";
        cedula = obtenerEntrada(true);
        if (!extraer(cedula)) {
            cout << "Cedula invalida. Intente nuevamente." << endl;
        }
    } while (!extraer(cedula));

    do {
        cout << "Ingrese el monto con el que va a jugar: ";
        monto = stod(obtenerEntrada(true));
        if (monto <= 0) {
            cout << "El monto debe ser mayor a 0." << endl;
        }
    } while (monto <= 0);

    guardarRegistro(nombre, apellido, cedula, edad, monto);
    cout << "Registro exitoso! Bienvenido, " << nombre << " " << apellido << " al casino." << endl;
}
*/

/*
#include "Registro.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cctype>
#include <ctime> // Para obtener la hora del sistema
#include <iomanip>

using namespace std;

// Función para borrar el salto de línea al final de la cédula
void Registro::borrar(char a[]) {
    for (int i = 0; i < 11; i++) {
        if (a[i] == '\n')
            a[i] = '\0';
    }
}

// Función para validar la cédula ecuatoriana
bool Registro::extraer(const string& cedula) {
    int v[10], num, limite;
    limite = cedula.length();

    if (limite != 10) {
        cout << "Cedula No Valida" << endl;
        return false;
    }

    for (int i = 0; i < 10; i++) {
        num = cedula[i] - '0';
        v[i] = num;
    }

    int vec[10], suma = 0, ultimo, ultimon;
    if (v[0] == 1 || v[0] == 2) {
        if (v[2] > 0 && v[2] < 6) {
            for (int i = 0; i < 9; i += 2) {
                vec[i] = v[i] * 2;
                if (vec[i] >= 10)
                    vec[i] -= 9;
            }
            for (int i = 1; i < 9; i += 2) {
                vec[i] = v[i];
            }
            for (int i = 0; i < 9; i++) {
                suma += vec[i];
            }

            ultimo = ((suma / 10) + 1) * 10;
            ultimon = ultimo - suma;

            if (ultimon == v[9]) {
                cout << "Cedula VERIFICADA" << endl;
                return true;
            } else {
                cout << "Cedula NO VERIFICADA" << endl;
                return false;
            }
        }
    }
    cout << "Cedula incorrecta" << endl;
    return false;
}

// Función para obtener la fecha y la hora actual
string Registro::obtenerFechaHora() {
    time_t ahora = time(0);
    struct tm* tiempo = localtime(&ahora);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tiempo);
    return string(buffer);
}

// Función para guardar el registro en un archivo
void Registro::guardarRegistro(const string& nombre, const string& apellido, const string& cedula, int edad, double monto) {
    ofstream archivo("usuarios.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Nombre: " << nombre << " " << apellido
                << ", Cedula: " << cedula
                << ", Edad: " << edad
                << ", Monto: " << monto
                << ", Fecha de Registro: " << obtenerFechaHora() << endl;
        archivo.close();
    } else {
        cout << "Error al abrir el archivo de usuarios." << endl;
    }
}

// Función para obtener entrada del usuario (solo números o solo letras)
string Registro::obtenerEntrada(bool soloNumeros) {
    string entrada = "";
    char c;
    while ((c = getch()) != '\r') { // Enter para terminar
        if (c == '\b' && !entrada.empty()) {
            cout << "\b \b";
            entrada.pop_back();
        } else if (soloNumeros && isdigit(c)) {
            entrada += c;
            cout << c;
        } else if (!soloNumeros && isalpha(c)) {
            entrada += c;
            cout << c;
        }
    }
    cout << endl;
    return entrada;
}

// Función para registrar un usuario
bool Registro::registrarUsuario(double& monto) {
    string nombre, apellido, cedula;
    int edad;

    do {
        cout << "Ingrese su edad: ";
        edad = stoi(obtenerEntrada(true));
        if (edad < 18) {
            cout << "No puedes registrarte si eres menor de 18 años." << endl;
            return false;
        }
    } while (edad < 18);

    cout << "Ingrese su nombre: ";
    nombre = obtenerEntrada(false);
    cout << "Ingrese su apellido: ";
    apellido = obtenerEntrada(false);

    do {
        cout << "Ingrese su cedula (10 digitos): ";
        cedula = obtenerEntrada(true);
        if (!extraer(cedula)) {
            cout << "Cedula invalida. Intente nuevamente." << endl;
        }
    } while (!extraer(cedula));

    do {
        cout << "Ingrese el monto con el que va a jugar: ";
        monto = stod(obtenerEntrada(true));
        if (monto <= 0) {
            cout << "El monto debe ser mayor a 0." << endl;
        }
    } while (monto <= 0);

    guardarRegistro(nombre, apellido, cedula, edad, monto);
    cout << "Registro exitoso! Bienvenido, " << nombre << " " << apellido << " al casino." << endl;
    return true;
}
*/
/*
#include "Registro.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cctype>
#include <ctime> // Para obtener la hora del sistema
#include <iomanip>

using namespace std;

// Función para borrar el salto de línea al final de la cédula
void Registro::borrar(char a[]) {
    for (int i = 0; i < 11; i++) {
        if (a[i] == '\n')
            a[i] = '\0';
    }
}

// Función para validar la cédula ecuatoriana
bool Registro::extraer(const string& cedula) {
    int v[10], num, limite;
    limite = cedula.length();

    if (limite != 10) {
        cout << "Cedula No Valida" << endl;
        return false;
    }

    for (int i = 0; i < 10; i++) {
        num = cedula[i] - '0';
        v[i] = num;
    }

    int vec[10], suma = 0, ultimo, ultimon;
    if (v[0] == 1 || v[0] == 2) {
        if (v[2] > 0 && v[2] < 6) {
            for (int i = 0; i < 9; i += 2) {
                vec[i] = v[i] * 2;
                if (vec[i] >= 10)
                    vec[i] -= 9;
            }
            for (int i = 1; i < 9; i += 2) {
                vec[i] = v[i];
            }
            for (int i = 0; i < 9; i++) {
                suma += vec[i];
            }

            ultimo = ((suma / 10) + 1) * 10;
            ultimon = ultimo - suma;

            if (ultimon == v[9]) {
                cout << "Cedula VERIFICADA" << endl;
                return true;
            } else {
                cout << "Cedula NO VERIFICADA" << endl;
                return false;
            }
        }
    }
    cout << "Cedula incorrecta" << endl;
    return false;
}

// Función para obtener la fecha y la hora actual
string Registro::obtenerFechaHora() {
    time_t ahora = time(0);
    struct tm* tiempo = localtime(&ahora);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tiempo);
    return string(buffer);
}

// Función para guardar el registro en un archivo
void Registro::guardarRegistro(const string& nombre, const string& apellido, const string& cedula, int edad, double monto) {
    ofstream archivo("usuarios.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Nombre: " << nombre << " " << apellido
                << ", Cedula: " << cedula
                << ", Edad: " << edad
                << ", Monto: " << monto
                << ", Fecha de Registro: " << obtenerFechaHora() << endl;
        archivo.close();
    } else {
        cout << "Error al abrir el archivo de usuarios." << endl;
    }
}

// Función para obtener entrada del usuario (solo números o solo letras)
string Registro::obtenerEntrada(bool soloNumeros) {
    string entrada = "";
    char c;
    while ((c = getch()) != '\r') { // Enter para terminar
        if (c == '\b' && !entrada.empty()) {
            cout << "\b \b";
            entrada.pop_back();
        } else if (soloNumeros && isdigit(c)) {
            entrada += c;
            cout << c;
        } else if (!soloNumeros && isalpha(c)) {
            entrada += c;
            cout << c;
        }
    }
    cout << endl;
    return entrada;
}

// Función para registrar un usuario
bool Registro::registrarUsuario(double& monto) {
    string nombre, apellido, cedula;
    int edad;

    do {
        cout << "Ingrese su edad: ";
        edad = stoi(obtenerEntrada(true));
        if (edad < 18) {
            cout << "No puedes registrarte si eres menor de 18 años." << endl;
            return false;
        }
    } while (edad < 18);

    cout << "Ingrese su nombre: ";
    nombre = obtenerEntrada(false);
    cout << "Ingrese su apellido: ";
    apellido = obtenerEntrada(false);

    do {
        cout << "Ingrese su cedula (10 digitos): ";
        cedula = obtenerEntrada(true);
        if (!extraer(cedula)) {
            cout << "Cedula invalida. Intente nuevamente." << endl;
        }
    } while (!extraer(cedula));

    do {
        cout << "Ingrese el monto con el que va a jugar: ";
        monto = stod(obtenerEntrada(true));
        if (monto <= 0) {
            cout << "El monto debe ser mayor a 0." << endl;
        }
    } while (monto <= 0);

    guardarRegistro(nombre, apellido, cedula, edad, monto);
    cout << "Registro exitoso! Bienvenido, " << nombre << " " << apellido << " al casino." << endl;
    return true;
}*/

#include "Registro.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cctype>
#include <ctime>
#include <iomanip>

using namespace std;

// Función para borrar el salto de línea al final de la cédula
void Registro::borrar(char a[]) {
    for (int i = 0; i < 11; i++) {
        if (a[i] == '\n')
            a[i] = '\0';
    }
}

// Función para validar la cédula ecuatoriana
bool Registro::extraer(const string& cedula) {
    int v[10], num, limite;
    limite = cedula.length();

    if (limite != 10) {
        cout << "Cedula No Valida" << endl;
        return false;
    }

    for (int i = 0; i < 10; i++) {
        num = cedula[i] - '0';
        v[i] = num;
    }

    int vec[10], suma = 0, ultimo, ultimon;
    if (v[0] == 1 || v[0] == 2) {
        if (v[2] > 0 && v[2] < 6) {
            for (int i = 0; i < 9; i += 2) {
                vec[i] = v[i] * 2;
                if (vec[i] >= 10)
                    vec[i] -= 9;
            }
            for (int i = 1; i < 9; i += 2) {
                vec[i] = v[i];
            }
            for (int i = 0; i < 9; i++) {
                suma += vec[i];
            }

            ultimo = ((suma / 10) + 1) * 10;
            ultimon = ultimo - suma;

            if (ultimon == v[9]) {
                cout << "Cedula VERIFICADA" << endl;
                return true;
            } else {
                cout << "Cedula NO VERIFICADA" << endl;
                return false;
            }
        }
    }
    cout << "Cedula incorrecta" << endl;
    return false;
}

// Función para obtener la fecha y la hora actual
string Registro::obtenerFechaHora() {
    time_t ahora = time(0);
    struct tm* tiempo = localtime(&ahora);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tiempo);
    return string(buffer);
}

// Función para guardar el registro en un archivo
void Registro::guardarRegistro(const string& nombre, const string& apellido, const string& cedula, int edad, double monto) {
    ofstream archivo("usuarios.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Nombre: " << nombre << " " << apellido
                << ", Cedula: " << cedula
                << ", Edad: " << edad
                << ", Monto: " << monto
                << ", Fecha de Registro: " << obtenerFechaHora() << endl;
        archivo.close();
    } else {
        cout << "Error al abrir el archivo de usuarios." << endl;
    }
}

// Función para obtener entrada del usuario (solo números o solo letras)
string Registro::obtenerEntrada(bool soloNumeros) {
    string entrada = "";
    char c;
    while ((c = getch()) != '\r') { // Enter para terminar
        if (c == '\b' && !entrada.empty()) {
            cout << "\b \b";
            entrada.pop_back();
        } else if (soloNumeros && isdigit(c)) {
            entrada += c;
            cout << c;
        } else if (!soloNumeros && isalpha(c)) {
            entrada += c;
            cout << c;
        }
    }
    cout << endl;
    return entrada;
}

// Función para registrar un usuario
bool Registro::registrarUsuario(double& monto) {
    string nombre, apellido, cedula;
    int edad;

    do {
        cout << "Ingrese su edad: ";
        edad = stoi(obtenerEntrada(true));
        if (edad < 18) {
            cout << "No puedes registrarte si eres menor de 18 años." << endl;
            return false;
        }
    } while (edad < 18);

    cout << "Ingrese su nombre: ";
    nombre = obtenerEntrada(false);
    cout << "Ingrese su apellido: ";
    apellido = obtenerEntrada(false);

    do {
        cout << "Ingrese su cedula (10 digitos): ";
        cedula = obtenerEntrada(true);
        if (!extraer(cedula)) {
            cout << "Cedula invalida. Intente nuevamente." << endl;
        }
    } while (!extraer(cedula));

    do {
        cout << "Ingrese el monto con el que va a jugar: ";
        monto = stod(obtenerEntrada(true));
        if (monto <= 0) {
            cout << "El monto debe ser mayor a 0." << endl;
        }
    } while (monto <= 0);

    guardarRegistro(nombre, apellido, cedula, edad, monto);
    cout << "Registro exitoso! Bienvenido, " << nombre << " " << apellido << " al casino." << endl;
    return true;
}