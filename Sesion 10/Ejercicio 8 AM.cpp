#include <iostream>

using namespace std;

// DEFINICION DE FUNCIONES

string EliminaUltimos(string cadena, char borrar){
	
	while(cadena[cadena.size() - 1] == borrar){
		cadena.pop_back();
	}

	return cadena;
}//Eliminas los caracteres iguales a uno dado desde el final de la cadena

/* 
FUNCION PRINCIPAL MAIN

Este programa reocge caracteres hasta que se introduce un terminador y luego
elimina todos los caracteres iguales a uno dado que se encuentran delante
del terminador
*/

int main(){
	
	//VARIABLES
	
	const char TERMINADOR = '#';
	char caracter, a_borrar;
	string cadena_a_borrar;
	
	//ENTRADAS
	
	caracter = cin.get();
	while(caracter != TERMINADOR){
		cadena_a_borrar.push_back(caracter);
		caracter = cin.get();
	}
	a_borrar = cin.get();
	
	//COMPUTO
	
	cadena_a_borrar = EliminaUltimos(cadena_a_borrar, a_borrar);
	
	//SALIDA
	
	cout << cadena_a_borrar;
	

}
