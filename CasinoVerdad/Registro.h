

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