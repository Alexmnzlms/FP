#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int i, tope, max_tope = 100000, min_tope = 0;
	double pi = 4, fraccion, denominador = 1.0, numerador = 2.0;
	bool toca_cambio_arriba;
	
	do{
		cout << "Introduzca el tope:\t ";
		cin >> tope;
	}while(tope > max_tope && tope < min_tope);
	
	for(i=0; i<=tope; i++){
		toca_cambio_arriba = (i % 2 != 0);
		if(toca_cambio_arriba){
		numerador = numerador + 2;
		}
		else{
		denominador = denominador + 2;
		}
		fraccion = numerador / denominador;
		pi = pi * fraccion;
	}
	cout.precision(15);
	cout << pi;
}
