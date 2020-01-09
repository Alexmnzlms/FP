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
	const int KILOMETROS_DESC = 700; 
	const int PUNTOS_PRIM_DESC = 200;
	const int PUNTOS_SEC_DESC = 100;   
   double kilometros;
   double precio;
   int puntos;
   double desc_2_porcien, desc_3_porcien, desc_4_porcien;
   double app_desc_total = 1;
   
   desc_2_porcien = 2;
   desc_3_porcien = 3;
   desc_4_porcien = 4;
   
   double app_desc_2 = ((100 - desc_2_porcien) / 100.0);
   double app_desc_3 = ((100 - desc_3_porcien) / 100.0);
   double app_desc_4 = ((100 - desc_4_porcien) / 100.0);
   

   cout << "Introduzca la distancia a su destino: ";
   cin >> kilometros;
   
   cout << "Introduzca su numero de puntos: ";
   cin >> puntos;
	
	precio = TARIFA_BASE;
	
	if(kilometros >= LIMITE_KM){
		precio = precio + ((kilometros - LIMITE_KM)*0.1);
	}
	
	if(kilometros >= KILOMETROS_DESC){
		app_desc_total = app_desc_total * app_desc_2;
	}
	
	if(puntos > PUNTOS_SEC_DESC){
		app_desc_total = app_desc_total * app_desc_3;
		if(puntos >= PUNTOS_PRIM_DESC){
			app_desc_total = app_desc_total / app_desc_3 * app_desc_4;
		}
	}
	
	precio = precio * app_desc_total;
	
   cout << "\nSu precio es de: " << precio  << '\t' << app_desc_total << " euros";
}
