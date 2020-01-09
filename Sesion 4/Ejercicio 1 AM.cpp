/*
	Programa que comprueba si dos numeros son del mismo signo.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int numero_1, numero_2;
	bool mismo_signo;
	
	cout << "Introduzca los numeros a comparar:\t";
	cin >> numero_1;
	cin >> numero_2;
	
	mismo_signo = numero_1 * numero_2 > 0;
	
	if(numero_1 != 0 && numero_2 != 0){
		if(mismo_signo)
			cout << "\tTienen el mismo signo";
		else
			cout << "\tNo tienen el mismo signo";
	}
	else{
		cout << "\tNo tienen el mismo signo";
	}	
}
