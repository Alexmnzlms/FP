/*
	Programa que codifica una letra y luego la descodifica
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	char letra;
	char letra_cod, letra_desc;
	int clave;
	const int MAXIMO = 'Z', MINIMO = 'A';
	int rango;
	
	cout << "Introduzca clave y letra:\t";
	cin >> clave;
	cin >> letra;
	
	rango = MAXIMO - MINIMO + 1;	
	letra_cod = letra + clave;
	letra_desc = letra_cod - clave;
	
	if(letra_cod > MAXIMO){
		letra_cod = letra_cod - rango;
	}
	if(letra_desc < MINIMO){
		letra_desc = letra_desc + rango;
	}

	cout << '\n' << "El resultado es: " << letra_cod << ", " << letra_desc;
	
}
