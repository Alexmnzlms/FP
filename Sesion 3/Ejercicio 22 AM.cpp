/*
   Programa que lee el precio del billete y aplica un descuento del 4% y del 2%
*/

#include <iostream>	
#include <cmath>
using namespace std;

int main(){
	double precio_billete;
	int descuento_principal, descuento_secundario;
	double precio_descuento_principal, precio_descuento_secundario;
	
	cout << "Introduzca el precio de su billete:\t";
	cin >> precio_billete;
	
	cout << "Introduzca sus descuentos: \t";
	cin >> descuento_principal;
	cin >> descuento_secundario;
	
	double aplicacion_desc_prim = ((100 - descuento_principal) / 100.0);
	double aplicacion_desc_secun = ((100 - descuento_secundario) / 100.0);
	
	precio_descuento_principal = precio_billete * aplicacion_desc_prim;
	precio_descuento_secundario = precio_billete * aplicacion_desc_secun;
	
	cout << "\nSu precio tras la aplicacion de nuestros descuentos \ndesciende a : ";
	
	cout << precio_descuento_principal << " euros" << " despues de aplicar el " 
	     <<  descuento_principal << "%" << " y " << precio_descuento_secundario 
		  << " euros" << " despues de aplicar el " << descuento_secundario << "%";
}

