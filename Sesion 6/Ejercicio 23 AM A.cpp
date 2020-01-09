/*
	Programa que aproxima pi por Gregory-Leibniz
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int i, tope, max_tope = 100000, min_tope = 1;
	double pi = 0, sumatoria;
	
	do{
		cout << "Introduzca el tope:\t ";
		cin >> tope;
	}while(tope > max_tope || tope < min_tope);
	
	for(i = 0; i <= tope; i++){
		sumatoria = 4*(pow(-1, i)/(2*i + 1));
		pi = pi + sumatoria;
	}
	cout.precision(15);
	cout << pi;
}
