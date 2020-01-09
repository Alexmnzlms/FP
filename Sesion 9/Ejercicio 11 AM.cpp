#include <iostream>

using namespace std;

int main(){
	
	// Declaracion de las variables generales
	
	int tamanio_vector, tamanio_a_borrar;
	int numero, izquierda, intercambia, minimo, posicion_minimo, posicion_escritura = 0, posicion_lectura, contador, recorredor;
	
	// Introduccion de tamaño del vector
	// Declaracion del mismo
	// Introduccion de los datos de vector
	
	cout << "Introduzca el tamaño del vector: ";
	cin >> tamanio_vector;
	int vector[tamanio_vector];

	for(int contador = 0; contador < tamanio_vector; contador++){
		cin >> numero;
		vector[contador] = numero;
	}
	
	// Introduccion de tamaño de a_borrar
	// Declaracion del mismo
	// Introduccion de los datos de a_borrar
	
	cout << "Introduzca el tamaño de a borrar: ";
	cin >> tamanio_a_borrar;
	int a_borrar[tamanio_a_borrar];
	
	for(int contador = 0; contador < tamanio_a_borrar; contador++){
		cin >> numero;
	a_borrar[contador] = numero;
	}
	
	//Algoritmo de ordenacion por seleccion
	
	for(izquierda = 0; izquierda < tamanio_a_borrar; izquierda++){
		minimo =a_borrar[izquierda];
		posicion_minimo = izquierda;
		
		for(int i = izquierda + 1; i < tamanio_a_borrar; i++){
			if(a_borrar[i] < minimo){
				minimo = a_borrar[i];
				posicion_minimo = i;
			}
		}
		
		intercambia = a_borrar[izquierda];
		a_borrar[izquierda] = a_borrar[posicion_minimo];
		a_borrar[posicion_minimo] = intercambia;
	}
	
	//Algoritmo de sustracion de los datos de a_borrar del vector
	
	int resultado[tamanio_vector];
	contador = tamanio_vector;
	recorredor = 0;
	
	for(posicion_lectura = 0; posicion_lectura < tamanio_vector; posicion_lectura++){
		if(posicion_lectura == a_borrar[recorredor]){
			recorredor++;
			contador--;
		}
		else{
			resultado[posicion_escritura] = vector[posicion_lectura];
			posicion_escritura++;
		}
		
	}	
	
	//Algoritmo de salida que imprime el vector
	
	cout << "El vector despues: ";
	for(int i = 0; i < contador; i++){
		cout << resultado[i] << '\t';
	}
	
}
