/*
	Programa que leea la velocidad capatada por un radar y le aplique un porcentaje de error
	
*/

#include <iostream>

using namespace std;

int main(){
	int numero_1, numero_2;
	bool no_tiene_mismo_signo, tiene_mismo_signo;
	
	cout << "Introduzca los numeros a comparar:\t";
	cin >> numero_1;
	cin >> numero_2;

	tiene_mismo_signo = ((numero_1 > 0 && numero_2 > 0) || (numero_1 < 0 && numero_2 < 0));
	no_tiene_mismo_signo = ((numero_1 > 0 && numero_2 < 0) || (numero_1 < 0 && numero_2 > 0) || (numero_1 == 0) || (numero_2 == 0));
	
	if(tiene_mismo_signo)
		cout << "Tienen el mismo signo";
	if(no_tiene_mismo_signo)
		cout << "No tienen el mismo signo";
}
