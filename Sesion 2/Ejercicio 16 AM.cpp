/*
	Progrmama que calcula la abscisa de una funcion gaussiana leyendo la x y la esperanza y la desviacion media
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){	
	double const PI = 3.1416;
	double abscisa, esperanza, desviacion;
	double inversa_raiz, cuadrado, exponente_e, gaussiana;
	
	cout << "Introduce la esperanza y la desviacion media: ";
	cin >> esperanza;
	cin >> desviacion;
	
	cout << "Introduce la abscisa: ";
	cin >> abscisa;
	
	inversa_raiz = 1 / (desviacion * sqrt(2 * PI));
	cuadrado = pow( ( (abscisa -  esperanza) / desviacion ), 2 );
	exponente_e = exp( -0.5 * cuadrado);
	gaussiana = inversa_raiz * exponente_e;
	
	cout << '\n' << "la abscisa vale: " <<  gaussiana;
}
