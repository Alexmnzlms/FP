#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// DEFINICION DE FUNCIONES

string EliminaUltimos(string cadena, char borrar){
	
	while(cadena[cadena.size() - 1] == borrar){
		cadena.pop_back();
	}

	return cadena;
}//Eliminas los caracteres iguales a uno dado desde el final de la cadena

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

string DoubleToString(double decimal, int cifra_redondeo){
	
	double numero_a_convertir;
	string numero_convertido;
	
	numero_a_convertir = Redondea(decimal, cifra_redondeo);
	numero_convertido = to_string(numero_a_convertir);
	numero_convertido = EliminaUltimos(numero_convertido, '0');
	
	return numero_convertido;
}//Convierte un double a un string

/* 
FUNCION PRINCIPAL MAIN

Este programa convierte un doble a un string
*/

int main(){
	
	//VARIABLES
	
	double numero;
	int cifra;
	
	//ENTRADA
	
	cout << "Introduzca el numero: ";
	cin >> numero;
	cout << "Introduzca el numero: ";
	cin >> cifra;
	
	//COMPUTO Y SALIDA
	
	cout << DoubleToString(numero, cifra);
}
