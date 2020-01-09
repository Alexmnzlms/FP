/*
	Programa que dado un vector de caracteres, queremos
	sustituir todas las apariciones de un carácter y poner 
	en su lugar el contenido de otro vector.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main () {
	const char TERMINADOR = '#';
	const int TAMANO = 100;
	char caracter, a_borrar;
	char v[TAMANO] , nuevo[TAMANO];
	int v_util = 0, nuevo_util = 0;
	int v_contador = 0;
	
	cout << "Vector: ";
	cin >> caracter;
	while (caracter != TERMINADOR){
		v[v_util] = caracter;
		v_util++;
		cout << "Vector: ";
		cin >> caracter;
	}
	
	cout << "Vector nuevo: ";
	cin >> caracter;
	while (caracter != TERMINADOR){
		nuevo[nuevo_util] = caracter;
		nuevo_util++;
		cout << "Vector: ";
		cin >> caracter;
	}
	
	cout << "Caracter a borrar: ";
	cin >> a_borrar;
	
	while(v_contador != v_util){
		if(v[v_contador] == a_borrar){
			for(int i = v_contador; i < v_util; i++){
				v[i] = v[i+1];
			}
			v_util = v_util -1;
			
			for(int i = v_util; i >= v_contador; i--){
				v[i + nuevo_util] = v[i];
			}
			
			for(int i = 0; i < nuevo_util; i++){
				v[v_contador + i] = nuevo[i];
			}
			
			v_util += nuevo_util;
			v_contador += nuevo_util;
		}
		else{
			v_contador++;
		}
	}
	for(int contador = 0; contador < nuevo_util; contador++){
		cout << nuevo[contador] << " ";
	}
}
