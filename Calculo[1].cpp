#include<iostream> 
#include<conio.h> 
#include "Calculo.h" 
#include <stdio.h> 
using namespace std; 
// **Funci�n para sumar los valores de a y b**
template <typename T> 
T Calculo<T>::sumar() { 
 return a + b;  
 } 
// **Funci�n para restar los valores de a y b** 
template <typename T> 
T Calculo<T>::restar() { 
 return a - b;  
 } 
// **Funci�n para multiplicar los valores de a y b**
template <typename T> 
T Calculo<T>::multiplicar() { 
 return a * b;  
 } 
 

