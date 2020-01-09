/*
	Programa que leea la velocidad del vehículo e imprima en pantalla la sanción correspondiente
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	const int VELLIM = 120;
	int velocidad, sancion;
	
	cout << "Introduzca su velocidad: ";
	cin >> velocidad;
	
	if(velocidad > VELLIM + 1){
		sancion = 2;
		if(velocidad > VELLIM + 31){
			sancion = sancion + 2;
			if(velocidad > VELLIM + 51){
				sancion = sancion + 2;
			}
		}
	}
	
	cout << " Ha perdido:\t" << sancion << " puntos";
}
