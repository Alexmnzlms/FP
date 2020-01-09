#include <iostream>

using namespace std;

int main(){
	
	// Declaracion de las variables generales
	
	int const MAX_FILA = 5;
	int const MAX_COLUMNA = 10;
	int velocidades[MAX_FILA][MAX_COLUMNA];
	int fila, columna, inicio = 31, paso = 0;

	//Construccion de la matriz
	
	for(columna = 0; columna < MAX_COLUMNA; columna++){
		for(fila = 0; fila < MAX_FILA; fila++){
			if(columna < 3){
				velocidades[fila][columna] = inicio + paso;
				if(fila < 1){
					paso += 20;
				}
				else {
					paso += 10;
				}
			}
			else{
				velocidades[fila][columna] = inicio + paso;
				if(fila < 1){
					paso += 30;
				}
				else {
					if(fila < 2){
						paso += 20;
					}
					else{
						paso += 10;
					}
					
				}
				
			}
			
		}
		inicio += 10;
		paso = 0;
	}
	
	//Salida
	
	for(fila = 0; fila < MAX_FILA; fila++){
		for(columna = 0; columna < MAX_COLUMNA; columna++){
			cout << velocidades[fila][columna] << " ";
			
		}
		cout <<'\n';
	}
}
