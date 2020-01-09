/*
   Programa que pide reiteradamente que introduzcamos un string. Si el string
   introducido coincide con el iniciador, el programa te pedira que introduzcas
   el numero de kilometros y la distancia a tu destino. Si no, el programa 
   seguira solicitando datos hasta que uno de ellos coincida con el terminador
   y entonces finalice la ejecucion.
*/

#include <iostream>   
#include <cmath>      
#include <iomanip>
using namespace std;

int main(){
	
// VARIABLES

	const int TARIFA_BASE = 150;
	const int LIMITE_KM = 300;   
	const int KILOMETROS_DESC = 700; 
	const int PUNTOS_PRIM_DESC = 200;
	const int PUNTOS_SEC_DESC = 100; 
	const string TERMINADOR = "#";
	const string INICIADOR = "N";
	string comando;
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
   
// COMPUTO Y ENTRADA

   do{
   	cin >> comando;
   	if(comando == INICIADOR){
			do{
		   cout << "Introduzca la distancia a su destino: ";
		   cin >> kilometros;
		   
			} while(kilometros < 0);
			
			do{
			cout << "Introduzca su numero de puntos: ";
		   cin >> puntos;
		   
			} while(puntos < 0 || puntos > 400);
			
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
			
			cout << "\nSu precio es de: " << precio  << '\t' << app_desc_total << " euros" << '\n';
		}
	} while(comando != TERMINADOR);
}
