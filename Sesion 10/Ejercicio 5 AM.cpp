#include <iostream>

using namespace std;

// DEFINICION DE FUNCIONES

int PotenciaEntera(int numero, int exponente){
	
	int potencia = numero;
	
	for(int i = 0; i < exponente - 1; i++){
		potencia = potencia * numero;
	}
	return potencia;
}//Devuelve un entero elevado a otro

/* 
FUNCION PRINCIPAL MAIN

Este programa eleva un numero a otro
*/

int main(){
	
	//VARIABLES
	
	int numero;
	int exponente;
	
	//ENTRADA
	
	cout << "Introduzca la base: ";
	cin >> numero;
	cout << "Introduzca el exponente: ";
	cin >> exponente;
	
	//SALIDA
	
	cout << "El resultado es: " <<PotenciaEntera(numero, exponente);

}
