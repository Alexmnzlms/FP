/*
   Programa simple para la obtencion del numero pi a traves /
   del arcoseno de un angulo conocido
*/

#include <iostream>   // Inclusi�n de recursos de E/S
#include <cmath>      // Inclusi�n de recursos matem�ticos
using namespace std;

int main(){               // Programa Principal
   double arcoseno;          // Declara variable arcoseno para guardar
   double pi;              // la informacion introducida por el usuario
   
   arcoseno=0.5;

   pi= 6*asin(arcoseno); // falta encontrar las operaciones adecuadas
   
   cout << "\nPi vale: " << pi;
}
