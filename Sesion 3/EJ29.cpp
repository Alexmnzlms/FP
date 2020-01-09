/*

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
	
	cout << "Introduzca clave y letra: ";
	cin >> clave;
	cin >> letra;
	
	rango = MINIMO - MAXIMO;
	letra_final = (letra - MINIMO + clave) % rango;
	letra_final = letra_final + MINIMO;
	letra_desc = letra_final + rango;
	
	cout << '\n' << "El resultado es: " << letra_final << ", " << letra_desc;
	
}
