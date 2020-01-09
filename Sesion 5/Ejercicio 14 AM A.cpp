/*
	Programa que leea la velocidad capatada por un radar y le aplique un porcentaje de error
	
*/

#include <iostream>

using namespace std;

int main(){
	int numero_1, numero_2;
	bool mismo_signo, tiene_mismo_signo;
	
	cout << "Introduzca los numeros a comparar:\t";
	cin >> numero_1;
	cin >> numero_2;

	if(numero_1 = 0){
		tiene_mismo_signo = false;
	}
	else if(numero_2 = 0){
		tiene_mismo_signo = false;
	}
	else if(numero_1 > 0){
		if(numero_2 > 0)
			tiene_mismo_signo = true;
		else if(numero_2 < 0)
			tiene_mismo_signo = false;
	}
	else if(numero_1 < 0){
		if(numero_2 < 0)
			tiene_mismo_signo = true;
		else if(numero_2 > 0)
			tiene_mismo_signo = false;
	}	
	
	if(tiene_mismo_signo)
		cout << "Tienen el mismo signo";
	else
		cout << "No tienen el mismo signo";
}
