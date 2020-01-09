/*
	Programa que codifica una letra y luego la descodifica
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	char letra;
	char letra_final, letra_desc;
	int clave;
	const int MAXIMO = 'Z', MINIMO = 'A';
	int rango;
	
	cout << "Introduzca clave y letra:\t";
	cin >> clave;
	cin >> letra;
	
	rango = MAXIMO - MINIMO + 1;
	letra_final = (letra - MINIMO + clave) % rango;
	letra_final = letra_final + MINIMO;
	letra_desc = (letra_final + MINIMO - clave) % rango;
	letra_desc = letra_desc + MINIMO;

	cout << '\n' << "El resultado es: " << letra_final << ", " << letra_desc;
	
}
