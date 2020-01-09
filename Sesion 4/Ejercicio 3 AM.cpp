/*
   Programa para calcular el precio final del billete conociendo el numero de kilometros
*/

#include <iostream>   
#include <cmath>      
#include <iomanip>
using namespace std;

int main(){
	const int TARIFA_BASE = 150;
	const int LIMITE_KM = 300;        
   double kilometros;
   double precio;

   cout << "Introduzca la distancia a su destino: ";
   cin >> kilometros;
	
	if(kilometros <= LIMITE_KM){
		precio = TARIFA_BASE;
	}
	else{
		precio = (TARIFA_BASE + (kilometros - LIMITE_KM)*0.1);
	}
   
   cout << "\nSu precio es de: " << precio << " euros";
}
