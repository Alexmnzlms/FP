#include <iostream>
#include <cmath>
using namespace std;

// DEFINICION DE FUNCIONES

int conv_seg(int hora, int minuto, int segundo){
	
	int const SEGUNDOS_HORA = 3600;
	int const SEGUNDOS_MINUTO = 60;
	int segundos;
	
	segundos = hora * SEGUNDOS_HORA + minuto * SEGUNDOS_MINUTO + segundo;
	
	return segundos;
}//Convierte horas minutos y segundos a segundos

int conv_min(int segundo){
	
	int const SEGUNDOS_MINUTO = 60;
	int minutos;
	
	minutos = segundo / SEGUNDOS_MINUTO;
	
	return minutos;
}//Convierte segundos a minutos

int LeeIntRango(int min, int max, string mensaje) {
   int a_leer;
   
   do{
      cout << mensaje;
      cin >> a_leer;
   }while (min > a_leer || max < a_leer);
   
   return a_leer;
}//Lee los extremos de un intervalo y acepta el numero si esta en el rango

/* 
FUNCION PRINCIPAL MAIN

Este programa conivierte le tiempo entre dos instantes en segundos y minutos
*/

int main(){
	
	//VARIABLES
	
	int hora_i, hora_f;
 	int minuto_i, minuto_f;
	int segundo_i, segundo_f;
	int segundos_finales;

	//ENTRADA

	hora_i = LeeIntRango(0,23,"Introduzca horas iniciales: ");
	minuto_i = LeeIntRango(0,59,"Introduzca minutos iniciales: ");
	segundo_i = LeeIntRango(0,59,"Introduzca segundos iniciales: ");

	hora_f = LeeIntRango(0,23,"Introduzca horas finales: ");
	minuto_f = LeeIntRango(0,59,"Introduzca minutos finales: ");
	segundo_f = LeeIntRango(0,59,"Introduzca segundos finales: ");
	
	//COMPUTO
	
	segundo_i = conv_seg(hora_i, minuto_i, segundo_i);
	segundo_f = conv_seg(hora_f, minuto_f, segundo_f);
	segundos_finales = segundo_f - segundo_i;
	
	//SALIDA
	
	cout << "\nla diferencia es de: " << segundos_finales << " segundos";
	cout << "\ny en minutos: " << conv_min(segundos_finales);
	
}
