/*
   Programa para calcular el precio final del billete conociendo el numero de kilometros
*/

#include <iostream>   
#include <cmath>      
#include <iomanip>
using namespace std;

int main(){               
   double kilometros;
   double precio;

   cout << "Introduzca la distancia a su destino: ";
   cin >> kilometros;

   precio = (kilometros*0.1+150);
   
   cout << "\nSu precio es de: " << fixed << setprecision(2) << precio << " euros";
}
