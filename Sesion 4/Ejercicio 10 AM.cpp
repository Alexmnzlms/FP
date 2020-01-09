/*
	Programa que calcula los segundos que pasan entre dos instantes introducidos
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
	
	segundo_i = hora_i *3600 + minuto_i * 60 + segundo_i;
	segundo_f = hora_f *3600 + minuto_f * 60 + segundo_f;
	
	cout << "\nla diferencia es de: " << segundo_f - segundo_i << " segundos";
	
}
