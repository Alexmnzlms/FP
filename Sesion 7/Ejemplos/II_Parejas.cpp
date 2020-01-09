//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Parejas de caracteres

/*
   Escriba un programa que lea cuatro valores de tipo char
   (min_izda, max_izda, min_dcha, max_dcha)
   e imprima las parejas que pueden formarse con los conjuntos
   {min_izda ... max_izda} y {min_dcha ... max_dcha}.
   Por ejemplo, si min_izda = b,max_izda = d,min_dcha = j,max_dcha = m,
   el programa debe imprimir lo siguiente:
   
   bj bk bl bm
   cj ck cl cm
   dj dk dl dm
*/

#include <iostream>
using namespace std;

int main(){
   char min_izda, max_izda, min_dcha, max_dcha, 
        caracter_izda, caracter_dcha;
   
   cout << "Parejas de caracteres\n\n";
   cout << "Introduzca los extremos del primer conjunto\n"
        << "y, a continuación, los del segundo\n";
        
   cin >> min_izda;
   cin >> max_izda;
   cin >> min_dcha;
   cin >> max_dcha;
   
   for (caracter_izda = min_izda; caracter_izda <= max_izda; caracter_izda++){
      
      for (caracter_dcha = min_dcha; caracter_dcha <= max_dcha; caracter_dcha++)
         cout << caracter_izda << caracter_dcha << " ";
      
      cout << "\n"; 
   }
}

