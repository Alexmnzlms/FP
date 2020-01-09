#include <iostream>

using namespace std;

int main(){
	
	// Declaracion de las variables generales
	
	int filas, columnas;
	int numero, minimo, posicion_minimo, intercambia, util_minimos = 0, max_de_minimos;
	
	//Introduccion de los datos de filas y columnas
	
	cin >> filas;
	cin >> columnas;
	
	//Creacion de la matriz
	
	int matriz[filas][columnas];
	
	for(int util_filas = 0; util_filas < filas; util_filas++){
		for(int util_columnas = 0; util_columnas < columnas; util_columnas++){
			cin >> numero;
			matriz[util_filas][util_columnas] = numero;
		}
	}
	
	// Algoritmo de busqueda de el minimo de cada fila
	
	int vector_minimos[filas]; // Creamos un vector minimo
	
	for(int contador_filas = 0; contador_filas < filas; contador_filas++){
		minimo = matriz[contador_filas][0];
		for(int contador_columnas = 0; contador_columnas < columnas; contador_columnas++){
			if(matriz[contador_filas][contador_columnas] < minimo){
				minimo = matriz[contador_filas][contador_columnas];	
			}
		}
		vector_minimos[contador_filas] = minimo;
		util_minimos++;
	}
	
	//Algoritmo de ordenacion del vector de minimios

		for(int izquierda = 0; izquierda < util_minimos ; izquierda++){
		minimo = vector_minimos[izquierda];
		posicion_minimo = izquierda;
		
		for(int i = izquierda + 1; i < util_minimos; i++){
			if(vector_minimos[i] < minimo){
				minimo = vector_minimos[i];
				posicion_minimo = i;
			}
		}
		
		intercambia = vector_minimos[izquierda];
		vector_minimos[izquierda] = vector_minimos[posicion_minimo];
		vector_minimos[posicion_minimo] = intercambia;
	}
	
	max_de_minimos = vector_minimos[util_minimos - 1];
	
	//Salida
	
	cout << "El maximo de los minimos es: " << max_de_minimos;
	
}
	
