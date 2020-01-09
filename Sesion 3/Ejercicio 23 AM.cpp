/*
	Programa que trunca decimales
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int numero_entero;
	double numero_decimal, cifra_trunc, modulo, potencia;
	
	cout << "Intruduzca el numero a truncar y la cifra:\t";
	cin >> numero_decimal;
	cin >> cifra_trunc;
	
	potencia = pow(10, cifra_trunc + 1);
	numero_entero =  numero_decimal * potencia;
	modulo = numero_entero % 10;
	numero_decimal = numero_entero - modulo;
	numero_decimal = numero_decimal / potencia;
	
	cout << '\t' << numero_decimal;
}
