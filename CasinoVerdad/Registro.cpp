

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
    string edad_input;
    string monto_input;

    /*do {
        cout << "Ingrese su edad: ";
        edad = stoi(obtenerEntrada(true));
        if (edad < 18) {
            cout << "No puedes registrarte si eres menor de 18 años." << endl;
            system("pause");
            return false;
        }
    } while (edad < 18);*/

    do {
        cout << "Ingrese su edad: ";
        edad_input = obtenerEntrada(true); // Solo se permiten números

        if (edad_input.empty()) {
            cout << "La edad no puede estar vacía. Intenta nuevamente." << endl;
        } else {
            try {
                edad = stoi(edad_input); // Convertir el valor de la edad a entero
                if (edad < 18 || edad>90) {
                    cout << "Su edad no es valida" << endl;
                }
            } catch (invalid_argument& e) {
                cout << "La edad debe ser un número válido. Intenta nuevamente." << endl;
                continue; // Si la conversión falla, continúa pidiendo la edad
            }
        }
    } while (edad < 18 || edad_input.empty() || edad>90);

    do {
        cout << "Ingrese su nombre: ";
        nombre = obtenerEntrada(false); // Solo se permiten letras
        if (nombre.empty()) {
            cout << "El nombre no puede estar vacío. Intenta nuevamente." << endl;
        }
    } while (nombre.empty());
    
    do {
        cout << "Ingrese su apellido: ";
        apellido = obtenerEntrada(false); // Solo se permiten letras
        if (apellido.empty()) {
            cout << "El apellido no puede estar vacío. Intenta nuevamente." << endl;
        }
    } while (apellido.empty());

    do {
        cout << "Ingrese su cedula (10 digitos): ";
        cedula = obtenerEntrada(true);
        if (!extraer(cedula)) {
            cout << "Cedula invalida. Intente nuevamente." << endl;
        }
    } while (!extraer(cedula));

    /*do {
        cout << "Ingrese el monto con el que va a jugar: ";
        monto_input = obtenerEntrada(true); // Solo se permiten números

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
    } while (monto <= 0 || monto_input.empty());*/
     monto=1;

    guardarRegistro(nombre, apellido, cedula, edad, monto);
    cout << "Registro exitoso! Bienvenido, " << nombre << " " << apellido << " al casino." << endl;
    return true;
}