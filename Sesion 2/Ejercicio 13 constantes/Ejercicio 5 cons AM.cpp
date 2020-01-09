/*
   Programa para calcular el precio final del billete conociendo el numero de kilometros
*/

#include <iostream>   
#include <cmath>      
using namespace std;

int main(){ 
	double const TARIFA_BASE = 150.0;
	double const EURO_KILOMETRO = 0.1;           
   double kilometros;
   double precio;

   cout << "Introduzca la distancia a su destino: ";
   cin >> kilometros;

   precio = kilometros * EURO_KILOMETRO + TARIFA_BASE;
   
   cout << "\nSu precio es de: " << precio << " euros";
}
