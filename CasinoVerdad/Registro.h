/*
#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <string>

using namespace std;

class Registro {
private:
    string nombre, apellido, cedula;
    int edad;

public:
    void borrar(char a[]);
    bool extraer(const string& cedula); // Validación de cédula
    void guardarRegistro(const string& nombre, const string& apellido, const string& cedula, int edad, double monto); // Guardar los datos en un archivo
    bool registrarUsuario(const string& nombre, const string& apellido, const string& cedula, int edad, double monto );  // Registrar el usuario
    string obtenerEntrada(bool soloNumeros); // Obtener entrada del usuario, permitiendo solo números o letras
    string obtenerFechaHora();  // Obtener la fecha y hora actual
    double monto;
    double getMonto() const{ return monto; 
    }

    void setmonto(double monto) { this->monto = monto; };
};

#endif // REGISTRO_H
*/
/*
#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <string>

using namespace std;

class Registro {
private:
    string nombre, apellido, cedula;
    int edad;
    double monto;

public:
    void borrar(char a[]);
    bool extraer(const string& cedula); // Validación de cédula
    void guardarRegistro(const string& nombre, const string& apellido, const string& cedula, int edad, double monto); // Guardar los datos en un archivo
    void registrarUsuario();  // Registrar el usuario
    string obtenerEntrada(bool soloNumeros); // Obtener entrada del usuario, permitiendo solo números o letras
    string obtenerFechaHora();  // Obtener la fecha y hora actual
    double getMonto() const{ return monto; }
    void setmonto(double monto) { this->monto = monto; };
};

#endif // REGISTRO_H
*/
/*

#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <string>

using namespace std;

class Registro {
private:
    string nombre, apellido, cedula;
    int edad;
    double monto;

public:
    void borrar(char a[]);
    bool extraer(const string& cedula); // Validación de cédula
    void guardarRegistro(const string& nombre, const string& apellido, const string& cedula, int edad, double monto); // Guardar los datos en un archivo
    bool registrarUsuario(double& monto);  // Registrar el usuario y devolver el monto
    string obtenerEntrada(bool soloNumeros); // Obtener entrada del usuario, permitiendo solo números o letras
    string obtenerFechaHora();  // Obtener la fecha y hora actual
    double getMonto() const { return monto; }
    void setMonto(double monto) { this->monto = monto; }
};

#endif // REGISTRO_H
*/

/*
#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <string>

using namespace std;

class Registro {
private:
    string nombre, apellido, cedula;
    int edad;
    double monto;

public:
    void borrar(char a[]);
    bool extraer(const string& cedula); // Validación de cédula
    void guardarRegistro(const string& nombre, const string& apellido, const string& cedula, int edad, double monto); // Guardar los datos en un archivo
    bool registrarUsuario(double& monto);  // Registrar el usuario y devolver el monto
    string obtenerEntrada(bool soloNumeros); // Obtener entrada del usuario, permitiendo solo números o letras
    string obtenerFechaHora();  // Obtener la fecha y hora actual
    double getMonto() const { return monto; }
    void setMonto(double monto) { this->monto = monto; }
    Registro() : nombre(""), apellido(""), cedula(""), edad(0) {}

    Registro(std::string nombre, std::string apellido, std::string cedula, int edad)
        : nombre(nombre), apellido(apellido), cedula(cedula), edad(edad) {}

    std::string getNombre() const {
        return nombre;
    }

    std::string getApellido() const {
        return apellido;
    }

    std::string getCedula() const {
        return cedula;
    }

    int getEdad() const {
        return edad;
    }
};

#endif // REGISTRO_H
*/

#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

class Registro {
private:
    std::string nombre, apellido, cedula;
    int edad;
    double monto;

public:
    Registro() : nombre(""), apellido(""), cedula(""), edad(0), monto(0) {}

    bool registrarUsuario(double& monto);
    double getMonto() const { return monto; }
    void setMonto(double monto) { this->monto = monto; }

    std::string getNombre() const { return nombre; }
    std::string getApellido() const { return apellido; }
    std::string getCedula() const { return cedula; }
    int getEdad() const { return edad; }

    void guardarRegistro(const std::string& nombre, const std::string& apellido, const std::string& cedula, int edad, double monto);
    std::string obtenerFechaHora();
    std::string obtenerEntrada(bool soloNumeros);
    bool extraer(const std::string& cedula);
    void borrar(char a[]);
};

#endif // REGISTRO_H