#include <iostream>
#include <cmath>

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

int NumeroCifras(int numero){
	int cifras = 1;
	
	while(numero < 9){
		numero = numero / 10;
		cifras++;
	}

	return cifras;
}

string DoubleToString(double decimal, int cifra_redondeo){
	
	double numero_a_convertir;
	string numero_convertido = "";
	int numero_a_convertir_entero, numero_cifras;
	char numero_caracter;
	
	numero_a_convertir = Redondea( decimal, cifra_redondeo);
	numero_a_convertir_entero = numero_a_convertir * cifra_redondeo;
	
	numero_cifras = NumeroCifras(numero_a_convertir_entero);
	
	for(int i = numero_cifras; i > 0; i--){
		numero_caracter = numero_a_convertir_entero / PotenciaEntera(10,i);
		numero_convertido.push_back(numero_caracter);
		numero_a_convertir_entero -= numero_caracter * PotenciaEntera(10,i);
	}
	
	return numero_convertido;
	
	
	}

int main(){
	double numero;
	int cifra;
	string cadena_vacia = "";
	
	cout << "Introduzca el numero";
	cin >> numero;
	cout << "Introduzca el numero";
	cin >> cifra;
	
	cout << DoubleToString(numero, cifra);

}
