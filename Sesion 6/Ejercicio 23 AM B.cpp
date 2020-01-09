/*
	Programa que aproxima pi por Gregory-Leibniz
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int i, tope, max_tope = 100000, min_tope = 1;
	double pi = 0, sumatoria, potencia;
	
	do{
		cout << "Introduzca el tope:\t ";
		cin >> tope;
	}while(tope > max_tope || tope < min_tope);
	
	for(i = 0; i <= tope; i++){
		if(i % 2 == 0){
			potencia = 1;
		}
		else{
			potencia = -1;
		}
		sumatoria = 4*(potencia/(2*i + 1));
		pi = pi + sumatoria;
	}
	cout.precision(15);
	cout << pi;
}
