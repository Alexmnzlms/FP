/*
	Progrmama que lee un maximo y un minimo de un intervalo y es capaz de desplazar un entero dentro del mismo.
	Hace uso de una variable distancia, que es la diferencia entre el entero despalzado y el minimo.
	A esa distancia se le resta el rango en funcion de si el entero desplazado esta por encima o por debajo del maximo para obtener la posicion
	Esa informacion se almacena en la variable multiplicador que vale 0 si el entero esta en el intervalo y 1 si lo sobrepasa.
	Finalmente añada al minimo la informacion que aporta la posicion, 
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){	
	
	int maximo, minimo, numero, desplazamiento;
	int multiplicador, numero_desplazado, numero_final, rango, posicion, distancia;
	
	cout << "Introduzca minimo, maximo, desplazamiento y numero: ";
	cin >> minimo;
	cin >> maximo;
	cin >> desplazamiento;
	cin >> numero;
	
	rango = maximo - minimo + 1;
	numero_desplazado = numero + desplazamiento;
	distancia = numero_desplazado - minimo;
	multiplicador = distancia / rango;			
	posicion = distancia - rango * multiplicador;   
	numero_final = minimo + posicion;
	
	
	cout << '\n' << "El resultado es: " << numero_final;
	
}
