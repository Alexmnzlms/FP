#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// DEFINICION DE FUNCIONES

int PotenciaEntera(int numero, int exponente){
	
	int potencia = numero;
	
	if(exponente == 0){
		return 1;
	}
	
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

int NumeroCifras(int numero){
	
	int cifras = 1;
	
	while(numero > 9){
		numero = numero / 10;
		cifras++;
	}
	
	return cifras;
}//Devuelve el numero de cifras de un numero

char NumeroACaracter(int numero){
	const int CARACTER_0 = 48;
	char caracter;
	
	numero += CARACTER_0;
	caracter = numero;
	
	return caracter;
}//Pasa un numero a su equivalente en caracter

string DoubleToString(double decimal_a_string, int cifra_para_redondeo){
	
	string convertido = "";
	double numero_a_convertir;
	int num_cifras_enteras, num_a_char, potencia_diez;
	char caracter;
	
	numero_a_convertir = Redondea( decimal_a_string, cifra_para_redondeo);
	num_cifras_enteras = NumeroCifras(numero_a_convertir);

	
	for(int i = num_cifras_enteras - 1; i >= 0; i--){
		potencia_diez = 1 * PotenciaEntera(10,i);
		num_a_char = numero_a_convertir / potencia_diez;
		caracter = NumeroACaracter(num_a_char);
		convertido.push_back(caracter);
		numero_a_convertir = numero_a_convertir - num_a_char * potencia_diez;
	}
	
	convertido.push_back('.');
	
	for(int j = 0; j < cifra_para_redondeo; j++){
		numero_a_convertir = numero_a_convertir * 10;
	}
	
	num_cifras_enteras = NumeroCifras(numero_a_convertir);
		
	for(int k = num_cifras_enteras - 1; k >= 0; k--){
		potencia_diez = 1 * PotenciaEntera(10,k);
		num_a_char = numero_a_convertir / potencia_diez;
		caracter = NumeroACaracter(num_a_char);
		convertido.push_back(caracter);
		numero_a_convertir = numero_a_convertir - num_a_char * potencia_diez;
	}
	
	return convertido;
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
