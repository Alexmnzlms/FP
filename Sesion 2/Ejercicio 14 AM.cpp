/*
	Programa que proporciona la distancia entre dos puntos
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double distancia;
	double coordenada_11, coordenada_12;
	double coordenada_21, coordenada_22;
	double suma_coordenadas1, suma_coordenadas2;
	double coordenadas1_cuadrado, coordenadas2_cuadrado;
	
	cout << "Introduzca las cordenadas: ";
	cin >> coordenada_11;
	cin >> coordenada_12;
	
	cout << "Introduzca las cordenadas: ";
	cin >> coordenada_21;
	cin >> coordenada_22;
	
	suma_coordenadas1 = coordenada_11 - coordenada_21;
	suma_coordenadas2 = coordenada_12 - coordenada_22;
	
	coordenadas1_cuadrado = suma_coordenadas1 * suma_coordenadas1;
	coordenadas2_cuadrado = suma_coordenadas2 * suma_coordenadas2;
	
	distancia = sqrt(coordenadas1_cuadrado + coordenadas2_cuadrado);
	
	cout << '\n' << "la distancia vale: " << distancia;
}
