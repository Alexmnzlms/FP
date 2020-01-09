/*
   Programa que lee una cadena de 1 y 0.
   Solicita datos continuamente hasta que es introducido un numero negativo,
   entonces terminara la ejecucion.
   Si el numero introducido no es ni un 0 ni un 1, el programa pasara por alto
   este dato y pasara al siguiente.
   Una vez se hayan introducido correctamente una serie de 8 numeros mecesarios
   para completar el bloque, el programa convierte estos numeros a un caracter 
   y lo imprime.
   Si el numero negativo se introdujera antes de que el programa haya completado
	un bloque de 8 bits, estos son descartados.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
// VARIABLES
	
	int bit = 0, i;
	int bit_caracter = 0;
	char caracter;
	double porcentaje, total, letra = 0, otro = 0;
	
// COMPUTO Y ENTRADA
	
	while(bit>=0){
		for(i = 7; i >= 0; i--){
			cin >> bit;
			if(bit==0||bit==1){
				bit_caracter = bit_caracter + (bit*pow(2,i));
			}
			else{
				if(bit>1){
					i++;
				}
				else{
					if(i >= 0){
						bit_caracter = 0;
					}
				i = -1;
				}
			}
		}
		if(bit_caracter != 0){
			caracter = bit_caracter;
			cout << caracter;
			bit_caracter = 0;
			if((caracter >= 97 && caracter <= 122) || (caracter >= 65 && caracter <= 90)){
				letra++;	
			}
			else{
				otro++;
			}
		}
	}
	total = letra + otro;
	porcentaje = (100 / total);
	letra = letra * porcentaje;
	otro = otro * porcentaje;
	
// SALIDA
	
	cout << '\n' << letra << "%" << '\n' << otro << "%";
}
