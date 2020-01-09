/*
	Programa que redondea un decimal a la cifra deseada
*/ 

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double decimal;
	double c_redondeo;
	
	cout << "Introduzca el numero que se desea redondear: ";
	cin >> decimal;
	
	cout << "Introduzca al decimal al que desea redondearlo: ";
	cin >> c_redondeo;
	
	decimal = decimal * pow(10, c_redondeo);
	decimal = round(decimal);
	decimal = decimal / pow(10, c_redondeo);
	
	
	cout << "\nEl numero redondeado a la " << c_redondeo << " cifra es " << decimal;
}
