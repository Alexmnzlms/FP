/*
   Programa que lee el precio del billete y aplica un descuento del 4% y del 2%
*/

#include <iostream>	
#include <cmath>
using namespace std;

int main(){
	double const DESCUENTO_PRINCIPAL = 4;
	double const DESCUENTO_SECUNDARIO = 2;
	double precio_billete;
	double precio_descuento_principal, precio_descuento_secundario;
	double aplicacion_descuento_principal, aplicacion_descuento_secundario;
	
	
	cout << "Introduzca el precio de su billete: ";
	cin >> precio_billete;


	aplicacion_descuento_principal = ((100 - DESCUENTO_PRINCIPAL) / 100);
	aplicacion_descuento_secundario = ((100 - DESCUENTO_SECUNDARIO) / 100);
	
	precio_descuento_principal = precio_billete * aplicacion_descuento_principal;
	precio_descuento_secundario = precio_billete * aplicacion_descuento_secundario;
	
	
	cout << "\nSu precio tras la aplicacion de nuestros descuentos \ndesciende a: ";
	cout << precio_descuento_principal << " euros" << " despues de aplicar el " <<  DESCUENTO_PRINCIPAL << "%" << " y " 
	<< precio_descuento_secundario << " euros" << " despues de aplicar el " << DESCUENTO_SECUNDARIO << "%";
}

