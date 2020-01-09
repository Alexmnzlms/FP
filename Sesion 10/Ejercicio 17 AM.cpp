#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string EliminaUltimos(string cadena, char borrar){
	
	while(cadena[cadena.size() - 1] == borrar){
		cadena.pop_back();
	}

	return cadena;
}

int PotenciaEntera(int numero, int exponente){
	
	int potencia = numero;
	
	for(int i = 0; i < exponente - 1; i++){
		potencia = potencia * numero;
	}
	
	return potencia;
}

double Redondea(double decimal, int cifra_redondeo){
	
	decimal = decimal * PotenciaEntera(10, cifra_redondeo);
	decimal = round(decimal);
	decimal = decimal / PotenciaEntera(10, cifra_redondeo);
	
	return decimal;
}

string DoubleToString(double decimal, int cifra_redondeo){
	
	double numero_a_convertir;
	string numero_convertido;
	
	numero_a_convertir = Redondea(decimal, cifra_redondeo);
	numero_convertido = to_string(numero_a_convertir);
	numero_convertido = EliminaUltimos(numero_convertido, '0');
	
	return numero_convertido;
}

int main(){

	double numero;
	int cifra;

	cout << "Introduzca el numero: ";
	cin >> numero;
	cout << "Introduzca el numero: ";
	cin >> cifra;

	cout << DoubleToString(numero, cifra);
}
