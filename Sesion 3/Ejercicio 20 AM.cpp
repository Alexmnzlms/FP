/*
	Programa que muestra en pantalla distintas aproximaciones de PI provenientes de distintas expresiones
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double const PI_1 = 256 / 81.0;
	double const PI_2 = 3 + 1 / 8.0;
	double const PI_3 = 337 / 120.0;
	
	cout << PI_1 << '\t' << PI_2 << '\t' << PI_3;
}
