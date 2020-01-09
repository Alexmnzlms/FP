#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int PotenciaEntera(int numero, int exponente){
	
	int potencia = numero;
	
	if(exponente == 0){
		return 1;
	}
	
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
	
	while(numero > 9){
		numero = numero / 10;
		cifras++;
	}
	
	return cifras;
}

char NumeroACaracter(int numero){
	const int CARACTER_0 = 48;
	char caracter;
	
	numero += CARACTER_0;
	caracter = numero;
	
	return caracter;
	
}

int main(){
	
	double numero;
	int cifra;
	
	string convertido = "";
	double numero_a_convertir;
	int num_cifras_enteras, num_a_char, potencia_diez;
	char caracter;
	
	cout << "Introduzca el numero: ";
	cin >> numero;
	cout << "Introduzca el numero: ";
	cin >> cifra;
	
	numero_a_convertir = Redondea(numero, cifra);
	num_cifras_enteras = NumeroCifras(numero_a_convertir);

	
	for(int i = num_cifras_enteras - 1; i >= 0; i--){
		potencia_diez = 1 * PotenciaEntera(10,i);
		num_a_char = numero_a_convertir / potencia_diez;
		caracter = NumeroACaracter(num_a_char);
		convertido.push_back(caracter);
		numero_a_convertir = numero_a_convertir - num_a_char * potencia_diez;
	}
	
	convertido.push_back('.');
	
	cout << numero_a_convertir << '\n';
	
	for(int k = 0; k < cifra; k++){
		numero_a_convertir = numero_a_convertir * 10;
	}
	
	cout << numero_a_convertir << '\n';
	
	num_cifras_enteras = NumeroCifras(numero_a_convertir);
	
	cout << num_cifras_enteras << '\n';
	
	for(int l = num_cifras_enteras - 1; l >= 0; l--){
		potencia_diez = 1 * PotenciaEntera(10,l);
		num_a_char = numero_a_convertir / potencia_diez;
		caracter = NumeroACaracter(num_a_char);
		convertido.push_back(caracter);
		numero_a_convertir = numero_a_convertir - num_a_char * potencia_diez;
	}
	
	cout << convertido << '\n';
	}
	
	

}
// Ejercicio 9 Antiguo

/*

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

char NumeroACaracter(int numero){
	const int CARACTER_0 = 48;
	char caracter;
	
	caracter = numero + CARACTER_0;
	
	return caracter
	
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

*/
