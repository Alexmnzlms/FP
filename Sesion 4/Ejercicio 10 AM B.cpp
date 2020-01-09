/*
	Programa que calcula que instate sucedio antes sin restarlos
*/ 

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	double hora_i, hora_f;
	double minuto_i, minuto_f;
	double segundo_i, segundo_f;
	
	cout << "Introduzca hora, minutos y segundos iniciales: ";
	cin >> hora_i;
	cin >> minuto_i;
	cin >> segundo_i;
	
	cout << "Introduzca hora, minutos y segundos finales: ";
	cin >> hora_f;
	cin >> minuto_f;
	cin >> segundo_f;
	
	if(hora_i < hora_f){
		cout << "El primero es anterior";
	}
	else {
		if(minuto_i < minuto_f){
			cout << "El primero es anterior";
		}
		else{
			if(segundo_i < segundo_f){
				cout << "El primero es anterior";
				}
			else{
				cout << "El segundo es anterior";
			}
		}
	}	
}

