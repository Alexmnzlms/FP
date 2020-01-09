/*
	Programa que permuta la posicion de dos variables
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double caja_dch, caja_izq, caja_xtr;
	
	cout << "Introduzca el valor de la caja 1: ";
	cin >> caja_dch;
	
	cout << "Introduzca el valor de la caja 2: ";
	cin >> caja_izq;
	
	caja_xtr = 0;
	
	caja_xtr = caja_dch;
	caja_dch = caja_izq;
	caja_izq = caja_xtr;
	
	cout << '\n' << "La caja 1 vale: "<< caja_dch << '\n' << "la caja 2 vale: " << caja_izq;
}
