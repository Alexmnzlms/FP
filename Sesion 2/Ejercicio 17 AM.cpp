/*
	rograma que permuta la posicion de tres variables
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double caja_dch, caja_izq, caja_cnt, caja_xtr;
	
	cout << "Introduzca el valor de la caja 1: ";
	cin >> caja_dch;
	
	cout << "Introduzca el valor de la caja 2: ";
	cin >> caja_cnt;
	
	cout << "Introduzca el valor de la caja 3: ";
	cin >> caja_izq;

	caja_xtr = 0;
	caja_xtr = caja_izq;
	caja_izq = caja_cnt;
	caja_cnt = caja_dch;
	caja_dch = caja_xtr;
	
	cout << '\n' << "la caja 1 vale: " << caja_dch << '\n' << "la caja 2 vale: " << caja_cnt << '\n' << "la caja 3 vale: " << caja_izq;
}
