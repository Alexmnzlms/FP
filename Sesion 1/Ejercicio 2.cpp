/*
	LEY DE OHM
*/


#include <iostream>   
#include <cmath>      
using namespace std;
int main(){
	double resistencia;
	double intensidad;
	double voltaje;
	
	cout << "Introduce la resistenia: ";
	cin >> resistencia;
	cout << "Introduce la intensidad: ";
	cin >> intensidad;
	
	voltaje = resistencia * intensidad;  //ley de ohm
	
	cout << "\nEl voltaje es de: " << voltaje << " voltios";
}

