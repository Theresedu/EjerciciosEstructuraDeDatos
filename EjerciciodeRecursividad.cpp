#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;
int ingresar(char *);
int ingresar(char *msj){
    char cad[10];
    char c;
    int i = 0;
    int valor = 0;
    printf("%s", msj);

    while((c = getch()) != 13){
        if (c >= '0' && c <= '9'){
            printf("%c", c);
            cad[i++] = c;
        } else if (c == 8) {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        }
    }

    cad[i++] = '\0';
    valor = atoi(cad);
    return valor;
}
//****Recursividad Simple*******************************************************
int sumaTail(int n, int acumulador = 0) {
    if (n == 0) return acumulador;               
    return sumaTail(n - 1, acumulador + n);      
}
//*****Recursividad de cola******************************************************
int factorialTail(int n, int resultado = 1) {
    if (n <= 1) return resultado;                
    return factorialTail(n - 1, resultado * n);  
}
//****Recursividad no cola*******************************************************
int producto(int n) {
    if (n <= 1) return 1;                    
    return n * producto(n - 1);              
}

//****Recursividad Mutua******************************************************
bool esMultiploDeTres(int n);  
bool esNoMultiploDeTres(int n);

bool esMultiploDeTres(int n) {
    if (n == 0) return true;                  
    return esNoMultiploDeTres(n - 1);         
}

bool esNoMultiploDeTres(int n) {
    if (n == 0) return false;                 
    return esMultiploDeTres(n - 1);           
}
//****Recursividad Anidada*******************************************************
int decrementoAnidado(int n) {
    if (n <= 0) return 0;                    
    return decrementoAnidado(decrementoAnidado(n - 2) - 1);  
}
//****Recursividad Multiple*******************************************************
int pascal(int fila, int columna) {
    if (columna == 0 || columna == fila) return 1; 
    return pascal(fila - 1, columna - 1) + pascal(fila - 1, columna); 
}
//****Recursividad Indirecta*******************************************************
int sumaPares(int n);
int sumaImpares(int n);

int sumaPares(int n) {
    if (n <= 0) return 0;                    
    return n + sumaImpares(n - 1);           
}

int sumaImpares(int n) {
    if (n <= 1) return 0;                    
    return sumaPares(n - 1);                 
}

int main() {
    int num1 = ingresar("Ingrese un valor entero:\n");
    cout << endl;

    // Ejemplo de Recursividad Simple****************************************************
    cout << "Suma de los primeros " << num1 << " numeros: " << sumaTail(num1) << endl;

    // Ejemplo de Recursividad de Cola****************************************************
    cout << "Factorial de " << num1 << " (usando recursividad de cola): " << factorialTail(num1) << endl;

    // Ejemplo de Recursividad No de Cola****************************************************
    cout << "Producto de los primeros " << num1 << " numeros: " << producto(num1) << endl;

    // Ejemplo de Recursividad Mutua****************************************************
    if (esMultiploDeTres(num1)) {
        cout << num1 << " es multiplo de 3." << endl;
    } else {
        cout << num1 << " no es multiplo de 3." << endl;
    }

    // Ejemplo de Recursividad Anidada****************************************************
    cout << "Decremento anidado de " << num1 << ": " << decrementoAnidado(num1) << endl;

    // Ejemplo de Recursividad Múltiple****************************************************
    int fila = ingresar("Ingrese la fila para el Triangulo de Pascal:\n");
    int columna = ingresar("Ingrese la columna para el Triangulo de Pascal:\n");
    cout << "Valor en el Triangulo de Pascal en fila " << fila << ", columna " << columna << ": " << pascal(fila, columna) << endl;

    // Ejemplo de Recursividad Indirecta****************************************************
    cout << "Suma de los primeros pares hasta " << num1 << ": " << sumaPares(num1) << endl;

    return 0;
}