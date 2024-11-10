#include<iostream>
#include<conio.h>
#include <iostream> 
using namespace std; 
// **Declaraci�n de la plantilla de la clase Calculo**
template <typename T> 
class Calculo 
{ 
public: 
// **Constructor**
// Este constructor inicializa las 2 variables privadas
// de la clase Calculo, con los valores especificados en
// los valores especificados en los argumentos a y b tipo template
	Calculo(T a, T b) : a(a), b(b) {}; 
// **Funci�n para sumar los valores de a y b**
    T sumar(); 
// **Funci�n para restar los valores de a y b**
    T restar(); 
// **Funci�n para multiplicar los valores de a y b**
    T multiplicar(); 
 // Getters
    T getA() const { return a; }
    T getB() const { return b; }

    // Setters
    void setA(T value) { a = value; }
    void setB(T value) { b = value; }
private: 
// **Atributos**
// Almacenan los valores de tipo T que se utilizar�n en las operaciones.
    T a; 
    T b; 
}; 

