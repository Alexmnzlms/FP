///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//////////                                                            /////////
//////////	Programa que pasa de mayusculas a minusculas y viceversa  /////////
//////////                                                            /////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const int A_MIN = 'a', A_MAY = 'A';
	char letra;
	int diferencia, comprobador;
	
	cout << "Introduzca la letra:\t";
	cin >> letra;
	
	diferencia = A_MIN - A_MAY;
	comprobador = letra / (A_MIN - 1);
	letra = letra + diferencia - ( 2* diferencia * comprobador);
	cout << '\t' <<  letra;	
}
