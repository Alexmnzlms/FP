/*
	Programa que despues de leer un numero y un grado, comprueba si ese numero
	es feliz para un grado <= al introducido.
	Calcula el nuemro de cifras y la suma de estas cada una elevadas al cuadrado
	mientras que el numero de iteraciones es menor que el grado introducido.
	Si en algun momento la suma de estos cuadrados es 1, el programa asigna
	true a una variable que controla el estado.
	Si antes de que llegue a 1 el numero de iteraciones supera al grado, el
	programa termina e imprime que el numero no es feliz para el grado introducido.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
// VARIABLES
	
	int i, numero, iteraciones = 0, cifras = 2, cuadrado, numero_contador, suma_cuadrados = 0, grado, iteracion_feliz;
	bool es_feliz = false;

// ENTRADA
	
	cin >> numero;
	cin >> grado;

// COMPUTO

	while(iteraciones < grado){
		numero_contador = numero;
		cifras = 1;
		while(numero_contador > 9){
			numero_contador = numero_contador / 10;
			cifras ++;
		}
		for(i = 0; i <= cifras; i++){
			cuadrado = numero % 10;
			numero = numero / 10;
			suma_cuadrados	= suma_cuadrados + pow(cuadrado, 2);	
		}
		numero = suma_cuadrados;
		iteraciones++;
		if(suma_cuadrados == 1){
			es_feliz = true;
			iteracion_feliz = iteraciones;
			iteraciones = grado + 1;
		}
		suma_cuadrados = 0;
	}
	
// SALIDA

	if(es_feliz){
		cout << "Es feliz para cualquier grado >= " << iteracion_feliz;
	}
	else{
		cout << "No es feliz para cualquier grado <= " << grado;
	}
}
