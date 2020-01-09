/*
   Programa que lee el precio del billete y aplica un descuento del 4% y del 2%
*/

#include <iostream>	
#include <cmath>
using namespace std;

int main(){
	double precio_billete;
	double descuento_principal, descuento_secundario;
	double precio_descuento_principal, precio_descuento_secundario;
	
	cout << "Introduzca el precio de su billete: ";
	cin >> precio_billete;
	
	descuento_principal = 4;
	descuento_secundario = 2;
	
	precio_descuento_principal = precio_billete * ((100 - descuento_principal) / 100);
	precio_descuento_secundario = precio_billete * ((100 - descuento_secundario) / 100);
	
	cout << "\nSu precio tras la aplicacion de nuestros descuentos \ndesciende a :";
	cout << precio_descuento_principal << " euros" << " despues de aplicar el " <<  descuento_principal << "%" << " y " 
	<< precio_descuento_secundario << " euros" << " despues de aplicar el " << descuento_secundario << "%";
}

