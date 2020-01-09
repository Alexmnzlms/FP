/*
	Programa que comprueba si dos numeros son del mismo signo.
*/

#include <iostream>
#include <cmath>

using namespace std;

enum class Tipodeletra 
	{mayuscula, minuscula, otro_caracter};

int main(){
	const char MAXIMO_MAY = 'Z';
	const char MINIMO_MAY = 'A';
	const char MAXIMO_MIN = 'z';
	const char MINIMO_MIN = 'a';	
	Tipodeletra tipo_letra;
	char letra;
	int cambio = MINIMO_MIN - MINIMO_MAY;
	
	cout << "Introduzca la letra: ";
	cin >> letra;
	
	bool letra_in_min = (letra < MAXIMO_MIN && letra > MINIMO_MIN);
	bool letra_in_may = (letra < MAXIMO_MAY && letra > MINIMO_MIN);
	
	if(letra_in_min){
		letra = letra + cambio;
		tipo_letra = Tipodeletra::minuscula;
	}
	else{
		if(letra_in_may){
			letra = letra - cambio;
			tipo_letra = Tipodeletra::mayuscula;
		}
		else{
			tipo_letra = Tipodeletra::otro_caracter;
		}
	}
	
	if (tipo_letra == Tipodeletra::mayuscula)
		cout << "La letra era mayuscula, una vez convertida es: ";
	if (tipo_letra == Tipodeletra::minuscula)
		cout << "La letra era mayuscula, una vez convertida es: ";
	if (tipo_letra == Tipodeletra::otro_caracter)
		cout << "El caracter no era una letra, no se cambia: ";
	
	
}
