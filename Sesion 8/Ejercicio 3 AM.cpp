/*
	Programa que calcula la diferencia de altitud, la maxima y el desnivel acumulado positivo
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    const int TAMANIO = 500;
    int gps[TAMANIO];
    int diferencias[TAMANIO];
    int tope;
    int valores;
    int recorredor;
    int maximo_desnivel = 0;
    int desnivel_acumulado = 0;

    cout << "Introduzca el tope del vector: ";
    cin >> tope;
    cout << "Introduzca los valores del gps: ";

    for (valores = 0; valores < tope; valores++){
        cin >> gps[valores];
    }
    for (recorredor = 0; recorredor < tope - 1; recorredor++){
        diferencias[recorredor] = (gps[recorredor+1] - gps[recorredor]);
        }
        
   maximo_desnivel = diferencias[0];
   for( recorredor = 0; recorredor < tope - 1; recorredor++){
		if(diferencias[recorredor] > maximo_desnivel){
			maximo_desnivel = diferencias[recorredor];
		}
	}
	
	for( recorredor = 0; recorredor < tope - 1; recorredor++){
   	if(diferencias[recorredor] > 0){
			desnivel_acumulado = desnivel_acumulado + diferencias[recorredor];
		}
   }
   if(tope == 1){
		cout << "No hay datos suficientes";
	}
	else{
    cout << "El maximo desnivel es " << abs(maximo_desnivel) << " y el desnivel acumulado positivo es " 
          << desnivel_acumulado;
	}
   
}
