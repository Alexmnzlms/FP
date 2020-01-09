#include <iostream>

using namespace std;

int main(){
	
	// Declaracion de las variables generales
	
	const int TAMANIO = 25e+5;
	const char TERMINADOR = '#';
	char lectura[TAMANIO];
	int contador = 0, posicion_lectura = 0, posicion_escritura;
	char caracter, a_borrar;
	
	// Asignacion de los caracteres a sus correspondientes vectores
	
	caracter = cin.get();
	
	while(caracter != TERMINADOR){
		lectura[contador] = caracter;
		contador++;
		caracter = cin.get();
		}	
	caracter = cin.get();
	a_borrar = caracter;
	
	//Algoritmo que recorre y elimina el caracter a_borrar
	
	for(posicion_escritura = 0; posicion_escritura < contador; posicion_escritura++){
		while(lectura[posicion_lectura] == a_borrar){
			posicion_lectura++;
		}
		lectura[posicion_escritura] = lectura[posicion_lectura];
		posicion_lectura++;
	}
	
	//Algoritmo que imprime el vector
	
	for(int i = 0; i < contador; i++){
		cout << lectura[i];
	}
	
	
}
