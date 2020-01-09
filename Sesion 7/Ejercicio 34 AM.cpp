/*
   Programa que imprime una tabla de velocidades.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
// VARIABLES

	const int INICIO_VELOCIDAD = 31;
	const int SALTO = 10;
	int contador_fila, contador_columna, diferencia = 90, fila_maximo;
	
// COMPUTO Y SALIDA
	
	for(contador_columna = INICIO_VELOCIDAD; contador_columna <= (INICIO_VELOCIDAD + 50); contador_columna = contador_columna + SALTO){
		fila_maximo = contador_columna + diferencia;
		for(contador_fila = contador_columna; contador_fila <= fila_maximo; contador_fila = contador_fila + SALTO){
			if(contador_columna == 51 && contador_fila == 81){
				contador_fila = contador_fila + SALTO;
			}
			if(contador_columna == 61 && contador_fila == 101){
				contador_fila = contador_fila + 2*SALTO;
			}
			if(contador_columna == 71 && contador_fila == 101){
				contador_fila = contador_fila + 2*SALTO;
			}
			if(contador_columna ==81 && contador_fila == 111){
				contador_fila = contador_fila + 2*SALTO;
			}
			cout << contador_fila << " ";
		}
		if(diferencia < 110){
			diferencia = diferencia + SALTO;
		}
		else{
			diferencia = 110;
		}
		cout << '\n';
		if(contador_columna == INICIO_VELOCIDAD){
			contador_columna = contador_columna + SALTO;
		}
		
	}
}
