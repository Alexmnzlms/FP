/*
	Programa que aproxima pi por Madhava sin usar pow
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int i, j, tope, max_tope = 100000, min_tope = 0;
	double pi, denominador, numerador, menos_uno_exp, raiz_exp, raiz, sumatoria;
	
	raiz = 1 / sqrt(3);
	
	do{
		cout << "Introduzca el tope:\t ";
		cin >> tope;
	}while(tope > max_tope && tope < min_tope);
	
	for(i=0; i<=tope; i++){
		
		
	}
	cout.precision(15);
	cout << pi;
}
