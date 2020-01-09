#include <iostream>
#include <cmath>
using namespace std;

// DEFINICION DE FUNCIONES

int PotenciaEntera(int numero, int exponente){
	
	int potencia = numero;
	
	for(int i = 0; i < exponente - 1; i++){
		potencia = potencia * numero;
	}
	return potencia;
}//Devuelve un entero elevado a otro

double Redondea(double decimal, int cifra_redondeo){
	decimal = decimal * PotenciaEntera(10, cifra_redondeo);
	decimal = round(decimal);
	decimal = decimal / PotenciaEntera(10, cifra_redondeo);
	
	return decimal;
}//Redonde un numero a la cifra indicada

/* 
FUNCION PRINCIPAL MAIN

Este programa redonde un numero a una cifra
*/

int main(){
	
	//VARIABLES
	
	double decimal;
	double c_redondeo;
	
	//ENTRADA
	
	cout << "Introduzca el numero que se desea redondear: ";
	cin >> decimal;
	cout << "Introduzca al decimal al que desea redondearlo: ";
	cin >> c_redondeo;
	
	//COMPUTO
	
	decimal = Redondea(decimal, c_redondeo);
	
	//SALIDA
	
	cout << "\nEl numero redondeado a la " << c_redondeo << " cifra es " << decimal;
}
